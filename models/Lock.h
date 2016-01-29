#pragma once

#include <pthread.h>
#include <semaphore.h>

class Lock {
public:
    Lock();
    ~Lock();
    void enter();
    void leave();

private:
    pthread_mutex_t m_lock;
};