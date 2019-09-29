cmake_minimum_required(VERSION 3.5.0)

project(my-realtime-server)

set(CMAKE_CXX_FLAGS "-Wall -std=c++14")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
message("SRC_DIR: ${SRC_DIR}")

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gen/protobuf)
set(DEPS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/deps)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${INC_DIR}
    ${SRC_DIR}
    ${GEN_DIR}
    ${DEPS_DIR}
    ${DEPS_DIR}/grpc/include
    ${DEPS_DIR}/libuv/include
    ${DEPS_DIR}/hiredis
    ${DEPS_DIR}/hiredis/adapters
    ${DEPS_DIR}/nats.c/src
    ${DEPS_DIR}/nats.c/src/adapters
)

add_subdirectory(
    ${DEPS_DIR}/grpc
)

add_subdirectory(
    ${DEPS_DIR}/libuv
)

add_subdirectory(
    ${DEPS_DIR}/nats.c
)

# Todo: 直す
add_executable(
    main
    ${SRC_DIR}/main.cc
    ${GEN_DIR}/realtime_messenger.grpc.pb.cc
    ${GEN_DIR}/realtime_messenger.pb.cc
    ${SRC_DIR}/infrastructure/grpc/service/realtime_messenger_service.cc
    ${SRC_DIR}/infrastructure/mstore/mstore_client.cc
    ${SRC_DIR}/infrastructure/messaging/client.cc
    ${DEPS_DIR}/hiredis/hiredis.c
    ${DEPS_DIR}/hiredis/async.c
    ${DEPS_DIR}/hiredis/dict.c
    ${DEPS_DIR}/hiredis/net.c
    ${DEPS_DIR}/hiredis/read.c
    ${DEPS_DIR}/hiredis/sds.c
    ${SRC_DIR}/util/singleton.cc
)

target_link_libraries(
    main PUBLIC
    grpc++
    uv
    nats_static
)

add_executable(
    client
    ${SRC_DIR}/client/client.cc
    ${GEN_DIR}/realtime_messenger.grpc.pb.cc
    ${GEN_DIR}/realtime_messenger.pb.cc
)

target_link_libraries(
    client PUBLIC
    grpc++
)
