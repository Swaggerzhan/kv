//
// Created by Swagger on 2021/8/27.
//

#ifndef KV_RAFTIMPL_H
#define KV_RAFTIMPL_H

#include "../proto/raft.pb.h"
#include <vector>
#include "../include/timestamp.h"
#include "../include/mutex.h"

enum ROLE {
    leader      = 1,
    candidate   = 2,
    follower    = 3,
};

struct RaftNode;


class RaftImpl : public raft::Raft {
private:



public:

    RaftImpl();
    virtual ~RaftImpl();
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


    /* 节点的启动 */
    void start();

private:



};


#endif //KV_RAFTIMPL_H
