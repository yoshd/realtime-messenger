#include <chrono>
#include <iostream>
#include <thread>

#include <grpc++/grpc++.h>
#include "libuv/include/uv.h"

#include "gen/protobuf/realtime_messenger.grpc.pb.h"
#include "gen/protobuf/realtime_messenger.pb.h"
#include "infrastructure/grpc/service/realtime_messenger_service.h"
#include "infrastructure/messaging/client.h"
#include "infrastructure/mstore/mstore_client.h"
#include "usecase/interactor/interactor.h"

void wait(uv_idle_t* handle) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
  std::cout << "Hello, world!" << std::endl;

  auto uv_loop = uv_default_loop();
  uv_idle_t idler;
  uv_idle_init(uv_loop, &idler);
  uv_idle_start(&idler, wait);
  std::thread t([&] { uv_run(uv_loop, UV_RUN_DEFAULT); });

  rmsg::mstore::CreateClient("127.0.0.1", 6379, uv_loop);
  rmsg::infrastructure::messaging::CreateClient("127.0.0.1", 4222, uv_loop);

  auto addr = "127.0.0.1:8888";
  auto cred = grpc::InsecureServerCredentials();

  auto interactor =
      std::make_shared<rmsg::usecase::interactor::RealtimeMessengerInteractor>(
          rmsg::mstore::GetClient(),
          rmsg::infrastructure::messaging::GetClient());
  rmsg::service::RealtimeMessengerService service(interactor);
  grpc::ServerBuilder builder;
  builder.AddListeningPort(addr, cred);
  builder.RegisterService(&service);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

  server->Wait();
  t.join();
}
