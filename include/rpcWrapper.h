//
// Created by Swagger on 2021/8/27.
//

#ifndef KV_RPCWRAPPER_H
#define KV_RPCWRAPPER_H

#include "brpc/server.h"
#include "../proto/raft.pb.h"
#include "butil/logging.h"
#include "brpc/channel.h"

/* rpc服务 */
class RpcServer : public raft::Raft {
public:

    RpcServer();
    virtual ~RpcServer();
    /* 心跳 */
    virtual void AppendEntries(::google::protobuf::RpcController *controller,
                               const ::raft::AppendEntriesRequest *request,
                               ::raft::AppendEntriesRespond *response,
                               ::google::protobuf::Closure *done) override;

    /* 选举 */
    virtual void Elect(::google::protobuf::RpcController *controller,
                       const ::raft::ElectRequest *request,
                       ::raft::ElectRespond *response,
                       ::google::protobuf::Closure *done);

private:


    brpc::Channel* channel_;            // 频道
    raft::Raft_Stub* raft_stub_;        // 呼叫桩
    brpc::Server* server_;              // 服务器


};





#endif //KV_RPCWRAPPER_H
