//
// Created by Swagger on 2021/8/27.
//


#include "../include/raftImpl.h"
#include "../include/sThread.h"

using std::vector;

struct RaftNode{
    RaftNode()
    {}

    bool isKill;                        // for test

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

void RaftImpl::kill() {
    // FIXME: use atom value
    self->mu.lock();
    self->isKill = true;
    self->mu.unlock();
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


void RaftImpl::appendLogLoop() {

    while ( !self->isKill ) {
        // TODO: sleep for few seconds
        {
            MutexLockGuard lock(self->mu); // 上锁
            if ( self->role != leader){
                continue;
            }

            /* 如果还未超时，则返回重新进入循环 */
            TimeStamp now = TimeStamp::now();
            if (!now.Sub(&now, &self->lastActionTime, 100)){
                continue;
            }

            self->lastActionTime = now; // 更新时间
            /* 心跳内容 */
            raft::AppendEntriesRequest args;
            args.set_term(self->currentTerm);
            args.set_leaderid(self->me);
            // TODO: 日志内容

            for (int i=0; i<self->peers.size(); i++) {
                if ( i == self->me) {
                    continue;
                }
                // 启线程发送
                auto go = [this, args] () -> void {
                    // 任期突然发生了变动
                    if ( this->self->currentTerm != args.term() ){
                        return;
                    }
                    // dead lock?
                    MutexLockGuard lock(this->self->mu);
                    raft::AppendEntriesRespond reply;
                    // 同步发送即可
                    // TODO: wrapper AppendEntries
                    AppendEntries(nullptr, &args, &reply, nullptr);

                    if ( reply.term() > this->self->currentTerm ){// 返回的数据表示有更高任期的存在
                        this->self->role = follower; // 退位
                        this->self->leaderID = -1;
                        this->self->currentTerm = reply.term();
                        this->self->voteFor = -1;
                    }
                    // TODO: 日志更新逻辑
                    if ( reply.accept() ){

                    }else {

                    }
                };
                Sthread t(go);
                t.start();
            }
        }
    }

}


void RaftImpl::electionLoop() {

}

