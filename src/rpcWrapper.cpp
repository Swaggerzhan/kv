//
// Created by Swagger on 2021/8/27.
//
#include "../include/rpcWrapper.h"

RpcServer::RpcServer()
:   server_(nullptr)
{




}


RpcServer::~RpcServer() {


}


void RpcServer::AppendEntries(::google::protobuf::RpcController *controller,
                              const ::raft::AppendEntriesRequest *request,
                              ::raft::AppendEntriesRespond *response,
                              ::google::protobuf::Closure *done)
                              {


}


void RpcServer::Elect(::google::protobuf::RpcController *controller,
                      const ::raft::ElectRequest *request,
                      ::raft::ElectRespond *response,
                      ::google::protobuf::Closure *done)
                      {


}
