// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: realtime_messenger.proto

#include "realtime_messenger.pb.h"
#include "realtime_messenger.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace rmsg {

static const char* RealtimeMessenger_method_names[] = {
  "/rmsg.RealtimeMessenger/Login",
  "/rmsg.RealtimeMessenger/Logout",
  "/rmsg.RealtimeMessenger/CreateRoom",
  "/rmsg.RealtimeMessenger/JoinRoom",
  "/rmsg.RealtimeMessenger/LeaveRoom",
  "/rmsg.RealtimeMessenger/StartMessageStream",
};

std::unique_ptr< RealtimeMessenger::Stub> RealtimeMessenger::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< RealtimeMessenger::Stub> stub(new RealtimeMessenger::Stub(channel));
  return stub;
}

RealtimeMessenger::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Login_(RealtimeMessenger_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Logout_(RealtimeMessenger_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CreateRoom_(RealtimeMessenger_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_JoinRoom_(RealtimeMessenger_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_LeaveRoom_(RealtimeMessenger_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_StartMessageStream_(RealtimeMessenger_method_names[5], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::Status RealtimeMessenger::Stub::Login(::grpc::ClientContext* context, const ::rmsg::LoginReq& request, ::rmsg::LoginRes* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Login_, context, request, response);
}

void RealtimeMessenger::Stub::experimental_async::Login(::grpc::ClientContext* context, const ::rmsg::LoginReq* request, ::rmsg::LoginRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::Login(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::LoginRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::Login(::grpc::ClientContext* context, const ::rmsg::LoginReq* request, ::rmsg::LoginRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, reactor);
}

void RealtimeMessenger::Stub::experimental_async::Login(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::LoginRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::rmsg::LoginRes>* RealtimeMessenger::Stub::AsyncLoginRaw(::grpc::ClientContext* context, const ::rmsg::LoginReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::LoginRes>::Create(channel_.get(), cq, rpcmethod_Login_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rmsg::LoginRes>* RealtimeMessenger::Stub::PrepareAsyncLoginRaw(::grpc::ClientContext* context, const ::rmsg::LoginReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::LoginRes>::Create(channel_.get(), cq, rpcmethod_Login_, context, request, false);
}

::grpc::Status RealtimeMessenger::Stub::Logout(::grpc::ClientContext* context, const ::rmsg::LogoutReq& request, ::rmsg::LogoutRes* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Logout_, context, request, response);
}

void RealtimeMessenger::Stub::experimental_async::Logout(::grpc::ClientContext* context, const ::rmsg::LogoutReq* request, ::rmsg::LogoutRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Logout_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::Logout(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::LogoutRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Logout_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::Logout(::grpc::ClientContext* context, const ::rmsg::LogoutReq* request, ::rmsg::LogoutRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Logout_, context, request, response, reactor);
}

void RealtimeMessenger::Stub::experimental_async::Logout(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::LogoutRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Logout_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::rmsg::LogoutRes>* RealtimeMessenger::Stub::AsyncLogoutRaw(::grpc::ClientContext* context, const ::rmsg::LogoutReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::LogoutRes>::Create(channel_.get(), cq, rpcmethod_Logout_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rmsg::LogoutRes>* RealtimeMessenger::Stub::PrepareAsyncLogoutRaw(::grpc::ClientContext* context, const ::rmsg::LogoutReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::LogoutRes>::Create(channel_.get(), cq, rpcmethod_Logout_, context, request, false);
}

::grpc::Status RealtimeMessenger::Stub::CreateRoom(::grpc::ClientContext* context, const ::rmsg::CreateRoomReq& request, ::rmsg::CreateRoomRes* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_CreateRoom_, context, request, response);
}

void RealtimeMessenger::Stub::experimental_async::CreateRoom(::grpc::ClientContext* context, const ::rmsg::CreateRoomReq* request, ::rmsg::CreateRoomRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_CreateRoom_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::CreateRoom(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::CreateRoomRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_CreateRoom_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::CreateRoom(::grpc::ClientContext* context, const ::rmsg::CreateRoomReq* request, ::rmsg::CreateRoomRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_CreateRoom_, context, request, response, reactor);
}

void RealtimeMessenger::Stub::experimental_async::CreateRoom(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::CreateRoomRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_CreateRoom_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::rmsg::CreateRoomRes>* RealtimeMessenger::Stub::AsyncCreateRoomRaw(::grpc::ClientContext* context, const ::rmsg::CreateRoomReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::CreateRoomRes>::Create(channel_.get(), cq, rpcmethod_CreateRoom_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rmsg::CreateRoomRes>* RealtimeMessenger::Stub::PrepareAsyncCreateRoomRaw(::grpc::ClientContext* context, const ::rmsg::CreateRoomReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::CreateRoomRes>::Create(channel_.get(), cq, rpcmethod_CreateRoom_, context, request, false);
}

::grpc::Status RealtimeMessenger::Stub::JoinRoom(::grpc::ClientContext* context, const ::rmsg::JoinRoomReq& request, ::rmsg::JoinRoomRes* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_JoinRoom_, context, request, response);
}

void RealtimeMessenger::Stub::experimental_async::JoinRoom(::grpc::ClientContext* context, const ::rmsg::JoinRoomReq* request, ::rmsg::JoinRoomRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_JoinRoom_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::JoinRoom(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::JoinRoomRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_JoinRoom_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::JoinRoom(::grpc::ClientContext* context, const ::rmsg::JoinRoomReq* request, ::rmsg::JoinRoomRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_JoinRoom_, context, request, response, reactor);
}

void RealtimeMessenger::Stub::experimental_async::JoinRoom(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::JoinRoomRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_JoinRoom_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::rmsg::JoinRoomRes>* RealtimeMessenger::Stub::AsyncJoinRoomRaw(::grpc::ClientContext* context, const ::rmsg::JoinRoomReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::JoinRoomRes>::Create(channel_.get(), cq, rpcmethod_JoinRoom_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rmsg::JoinRoomRes>* RealtimeMessenger::Stub::PrepareAsyncJoinRoomRaw(::grpc::ClientContext* context, const ::rmsg::JoinRoomReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::JoinRoomRes>::Create(channel_.get(), cq, rpcmethod_JoinRoom_, context, request, false);
}

::grpc::Status RealtimeMessenger::Stub::LeaveRoom(::grpc::ClientContext* context, const ::rmsg::LeaveRoomReq& request, ::rmsg::LeaveRoomRes* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_LeaveRoom_, context, request, response);
}

void RealtimeMessenger::Stub::experimental_async::LeaveRoom(::grpc::ClientContext* context, const ::rmsg::LeaveRoomReq* request, ::rmsg::LeaveRoomRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_LeaveRoom_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::LeaveRoom(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::LeaveRoomRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_LeaveRoom_, context, request, response, std::move(f));
}

void RealtimeMessenger::Stub::experimental_async::LeaveRoom(::grpc::ClientContext* context, const ::rmsg::LeaveRoomReq* request, ::rmsg::LeaveRoomRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_LeaveRoom_, context, request, response, reactor);
}

void RealtimeMessenger::Stub::experimental_async::LeaveRoom(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::rmsg::LeaveRoomRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_LeaveRoom_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::rmsg::LeaveRoomRes>* RealtimeMessenger::Stub::AsyncLeaveRoomRaw(::grpc::ClientContext* context, const ::rmsg::LeaveRoomReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::LeaveRoomRes>::Create(channel_.get(), cq, rpcmethod_LeaveRoom_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rmsg::LeaveRoomRes>* RealtimeMessenger::Stub::PrepareAsyncLeaveRoomRaw(::grpc::ClientContext* context, const ::rmsg::LeaveRoomReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rmsg::LeaveRoomRes>::Create(channel_.get(), cq, rpcmethod_LeaveRoom_, context, request, false);
}

::grpc::ClientReaderWriter< ::rmsg::Message, ::rmsg::Message>* RealtimeMessenger::Stub::StartMessageStreamRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::rmsg::Message, ::rmsg::Message>::Create(channel_.get(), rpcmethod_StartMessageStream_, context);
}

void RealtimeMessenger::Stub::experimental_async::StartMessageStream(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::rmsg::Message,::rmsg::Message>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::rmsg::Message,::rmsg::Message>::Create(stub_->channel_.get(), stub_->rpcmethod_StartMessageStream_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::rmsg::Message, ::rmsg::Message>* RealtimeMessenger::Stub::AsyncStartMessageStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::rmsg::Message, ::rmsg::Message>::Create(channel_.get(), cq, rpcmethod_StartMessageStream_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::rmsg::Message, ::rmsg::Message>* RealtimeMessenger::Stub::PrepareAsyncStartMessageStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::rmsg::Message, ::rmsg::Message>::Create(channel_.get(), cq, rpcmethod_StartMessageStream_, context, false, nullptr);
}

RealtimeMessenger::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RealtimeMessenger_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RealtimeMessenger::Service, ::rmsg::LoginReq, ::rmsg::LoginRes>(
          std::mem_fn(&RealtimeMessenger::Service::Login), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RealtimeMessenger_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RealtimeMessenger::Service, ::rmsg::LogoutReq, ::rmsg::LogoutRes>(
          std::mem_fn(&RealtimeMessenger::Service::Logout), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RealtimeMessenger_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RealtimeMessenger::Service, ::rmsg::CreateRoomReq, ::rmsg::CreateRoomRes>(
          std::mem_fn(&RealtimeMessenger::Service::CreateRoom), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RealtimeMessenger_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RealtimeMessenger::Service, ::rmsg::JoinRoomReq, ::rmsg::JoinRoomRes>(
          std::mem_fn(&RealtimeMessenger::Service::JoinRoom), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RealtimeMessenger_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RealtimeMessenger::Service, ::rmsg::LeaveRoomReq, ::rmsg::LeaveRoomRes>(
          std::mem_fn(&RealtimeMessenger::Service::LeaveRoom), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RealtimeMessenger_method_names[5],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< RealtimeMessenger::Service, ::rmsg::Message, ::rmsg::Message>(
          std::mem_fn(&RealtimeMessenger::Service::StartMessageStream), this)));
}

RealtimeMessenger::Service::~Service() {
}

::grpc::Status RealtimeMessenger::Service::Login(::grpc::ServerContext* context, const ::rmsg::LoginReq* request, ::rmsg::LoginRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RealtimeMessenger::Service::Logout(::grpc::ServerContext* context, const ::rmsg::LogoutReq* request, ::rmsg::LogoutRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RealtimeMessenger::Service::CreateRoom(::grpc::ServerContext* context, const ::rmsg::CreateRoomReq* request, ::rmsg::CreateRoomRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RealtimeMessenger::Service::JoinRoom(::grpc::ServerContext* context, const ::rmsg::JoinRoomReq* request, ::rmsg::JoinRoomRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RealtimeMessenger::Service::LeaveRoom(::grpc::ServerContext* context, const ::rmsg::LeaveRoomReq* request, ::rmsg::LeaveRoomRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RealtimeMessenger::Service::StartMessageStream(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::rmsg::Message, ::rmsg::Message>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace rmsg

