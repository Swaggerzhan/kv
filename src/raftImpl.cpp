//
// Created by Swagger on 2021/8/27.
//


#include "../include/raftImpl.h"

using std::vector;

struct RaftNode{
    RaftNode()
    {}

    Mutex mu;                           // 互斥锁
    ROLE role;                          // 角色
    int me;                             // 当前节点ID
    vector<RaftImpl*>  peers;      // 每个节点的实现
    int leaderID;                       // 领导者ID
    int currentTerm;                    // 当前任期
    int voteFor;                        // 投票的节点
    TimeStamp lastActionTime;           // 心跳超时时间
    TimeStamp lastBroadCast;            // 广播时间


    /* 关于日志 */

    vector<int> nextIndex;              // 下一个需要进行同步的日志
    vector<int> matchIndex;             // 已经同步的日志
    int commitIndex;                    // 日志提交情况 for 2 commit
    int lastApplied;                    // 状态机提交情况

    /* 关于日志的持久化... */


};



RaftImpl::RaftImpl()

{


}


RaftImpl::~RaftImpl() {

}


void RaftImpl::AppendEntries(::google::protobuf::RpcController *controller,
                              const ::raft::AppendEntriesRequest *request,
                              ::raft::AppendEntriesRespond *response,
                              ::google::protobuf::Closure *done)
{



}


void RaftImpl::Elect(::google::protobuf::RpcController *controller,
                      const ::raft::ElectRequest *request,
                      ::raft::ElectRespond *response,
                      ::google::protobuf::Closure *done)
{


}
