//
// Bareflank C Library
//
// Copyright (C) 2015 Assured Information Security, Inc.
// Author: Rian Quinn        <quinnr@ainfosec.com>
// Author: Brendan Kerrigan  <kerriganb@ainfosec.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#include <pthread.h>

#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

// We allocate a page for FS BASE which is used for TLS. We need to 
// store the FS BASE as the first element, so this means that the 
// max number of elements that can be used for TLS is 511. 
#define MAX_THREAD_SPECIFIC_DATA 511

extern "C" uint64_t __tls_base(void) noexcept;

#define UNHANDLED() \
    { \
        const char *str_text = "\033[1;33mWARNING\033[0m: unsupported pthread function called = "; \
        const char *str_func = __PRETTY_FUNCTION__; \
        const char *str_endl = "\n"; \
        write(0, str_text, strlen(str_text)); \
        write(0, str_func, strlen(str_func)); \
        write(0, str_endl, strlen(str_endl)); \
    }

#define ARG_UNSUPPORTED(a) \
    { \
        const char *str_text = "\033[1;33mWARNING\033[0m: " a " not supported for function called = "; \
        const char *str_func = __PRETTY_FUNCTION__; \
        const char *str_endl = "\n"; \
        write(0, str_text, strlen(str_text)); \
        write(0, str_func, strlen(str_func)); \
        write(0, str_endl, strlen(str_endl)); \
    }

#ifndef USE_FS_FOR_THREAD_LOCAL_STORAGE
void* threadSpecificData[MAX_THREAD_SPECIFIC_DATA] = {0};
#endif

extern "C" int
pthread_attr_destroy(pthread_attr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getdetachstate(const pthread_attr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getguardsize(const pthread_attr_t *, size_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getinheritsched(const pthread_attr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getschedparam(const pthread_attr_t *, struct sched_param *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getschedpolicy(const pthread_attr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getscope(const pthread_attr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getstackaddr(const pthread_attr_t *, void **)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_getstacksize(const pthread_attr_t *, size_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_init(pthread_attr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setdetachstate(pthread_attr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setguardsize(pthread_attr_t *, size_t)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setinheritsched(pthread_attr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setschedparam(pthread_attr_t *, const struct sched_param *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setschedpolicy(pthread_attr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setscope(pthread_attr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setstackaddr(pthread_attr_t *, void *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_attr_setstacksize(pthread_attr_t *, size_t)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_cancel(pthread_t)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" void
pthread_cleanup_push(void*, void *)
{
    UNHANDLED();
}

extern "C" void
pthread_cleanup_pop(int)
{
    UNHANDLED();
}

extern "C" int
pthread_cond_broadcast(pthread_cond_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_cond_destroy(pthread_cond_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_cond_init(pthread_cond_t *, const pthread_condattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_cond_signal(pthread_cond_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *, const struct timespec *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_condattr_destroy(pthread_condattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_condattr_getpshared(const pthread_condattr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_condattr_init(pthread_condattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_condattr_setpshared(pthread_condattr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_create(pthread_t *, const pthread_attr_t *, void *(*)(void *), void *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_detach(pthread_t)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_equal(pthread_t, pthread_t)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" void
pthread_exit(void *)
{
    UNHANDLED();
}

extern "C" int
pthread_getconcurrency(void)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_getschedparam(pthread_t, int *, struct sched_param *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" void *
pthread_getspecific(pthread_key_t key)
{
    if (key > MAX_THREAD_SPECIFIC_DATA)
        return nullptr;

#ifdef USE_FS_FOR_THREAD_LOCAL_STORAGE
    auto threadSpecificData = (void **)__tls_base();
#endif

    return threadSpecificData[key];
}

extern "C" int
pthread_join(pthread_t, void **)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_key_create(pthread_key_t *key, void (*destructor)(void *))
{
    if (destructor)
        ARG_UNSUPPORTED("destructor");

    if (!key)
        return -EINVAL;

    static uint64_t g_keys = 0;
    *key = g_keys++;

    return 0;
}

extern "C" int
pthread_key_delete(pthread_key_t)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutex_destroy(pthread_mutex_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutex_getprioceiling(const pthread_mutex_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
{
    if (attr)
        ARG_UNSUPPORTED("destructor");

    if (!mutex)
        return -EINVAL;

    *mutex = 0;
    return -ENOSYS;
}

extern "C" int
pthread_mutex_lock(pthread_mutex_t *mutex)
{
    if (!mutex)
        return -EINVAL;

    while(__sync_lock_test_and_set(mutex, 1));

    return 0;
}

extern "C" int
pthread_mutex_setprioceiling(pthread_mutex_t *, int, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutex_trylock(pthread_mutex_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutex_unlock(pthread_mutex_t *mutex)
{
    if (!mutex)
        return -EINVAL;

    __sync_lock_release(mutex);

    return 0;
}

extern "C" int
pthread_mutexattr_destroy(pthread_mutexattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_getprotocol(const pthread_mutexattr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_getpshared(const pthread_mutexattr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_gettype(const pthread_mutexattr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_init(pthread_mutexattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_setprioceiling(pthread_mutexattr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_setprotocol(pthread_mutexattr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_setpshared(pthread_mutexattr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_mutexattr_settype(pthread_mutexattr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_once(pthread_once_t *once, void (*init)(void))
{
    if (!once || !init)
        return -EINVAL;

    if (*once == 0)
    {
        (*init)();
        *once = 1;
    }

    return 0;
}

extern "C" int
pthread_rwlock_destroy(pthread_rwlock_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlock_init(pthread_rwlock_t *, const pthread_rwlockattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlock_rdlock(pthread_rwlock_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlock_tryrdlock(pthread_rwlock_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlock_trywrlock(pthread_rwlock_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlock_unlock(pthread_rwlock_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlock_wrlock(pthread_rwlock_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlockattr_destroy(pthread_rwlockattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlockattr_init(pthread_rwlockattr_t *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" pthread_t
pthread_self(void)
{
    UNHANDLED();
    return 1;
}

extern "C" int
pthread_setcancelstate(int, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_setcanceltype(int, int *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_setconcurrency(int)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_setschedparam(pthread_t, int, const struct sched_param *)
{
    UNHANDLED();
    return -ENOSYS;
}

extern "C" int
pthread_setspecific(pthread_key_t key, const void *data)
{
    if (key > MAX_THREAD_SPECIFIC_DATA)
        return -EINVAL;

#ifdef USE_FS_FOR_THREAD_LOCAL_STORAGE
    auto threadSpecificData = (void **)__tls_base();
#endif

    threadSpecificData[key] = (void *)data;
    return 0;
}

extern "C" void
pthread_testcancel(void)
{
    UNHANDLED();
}

extern "C" int
sched_yield(void)
{
    return 0;
}
