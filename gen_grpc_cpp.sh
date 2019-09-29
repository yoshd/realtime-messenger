#!/bin/bash
set -eu

if [[ ! -e "./bin/protoc" || ! -e "./bin/grpc_cpp_plugin" ]]; then
  mkdir .build.tmp
  pushd .build.tmp
  cmake ../deps/grpc -GNinja
  ninja protoc grpc_cpp_plugin
  mv third_party/protobuf/protoc-3.8.0.0 ../bin/protoc
  mv grpc_cpp_plugin ../bin/grpc_cpp_plugin
  popd
  rm -rf .build.tmp
fi

./bin/protoc \
  --proto_path=. \
  --cpp_out=./gen/protobuf \
  --grpc_out=./gen/protobuf \
  --plugin=protoc-gen-grpc=./bin/grpc_cpp_plugin \
  realtime_messenger.proto
