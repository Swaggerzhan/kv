cmake_minimum_required(VERSION 3.19)
project(kv)

set(CMAKE_CXX_STANDARD 14)

# protobuf
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# brpc
include_directories(/Users/swagger/Github/incubator-brpc/output/include)
link_directories(/Users/swagger/Github/incubator-brpc/output/lib)

# openssl
include_directories(/usr/local/Cellar/openssl@1.1/1.1.1k/include)
link_directories(/usr/local/Cellar/openssl@1.1/1.1.1k/lib)

add_executable(kv main.cpp include/rpcWrapper.h src/rpcWrapper.cpp include/raftImpl.h src/raftImpl.cpp include/timestamp.h src/timestamp.cpp include/mutex.h src/mutex.cpp include/sThread.h src/sThread.cpp)

# protobuf
target_link_libraries(kv protoc.a)
target_link_libraries(kv protobuf.a)

# brpc
target_link_libraries(kv brpc.a)

# openssl
target_link_libraries(kv ssl.a)




