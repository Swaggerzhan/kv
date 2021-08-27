//
// Created by Swagger on 2021/8/27.
//

#ifndef KV_MUTEX_H
#define KV_MUTEX_H

class Mutex{
public:
    Mutex();
    ~Mutex();

    void lock();

    void unlock();

private:


};


class MutexLockGuard{

};


#endif //KV_MUTEX_H
