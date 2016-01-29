//
// Created by Diego Borges on 1/28/16.
//

#include "Lock.h"

Lock::Lock()
{
    pthread_mutex_init( &m_lock, NULL );
}

Lock::~Lock()
{
}

void Lock::enter()
{
    pthread_mutex_lock( &m_lock );
}

void Lock::leave()
{
    pthread_mutex_unlock( &m_lock );
}

