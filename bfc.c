#include <stddef.h>

#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef ATEXIT_PROVIDED
int
atexit(void (*func)(void)) __THROW
{
    (void) func;

    return 0;
}
#endif

#ifndef _EXIT_PROVIDED
void
_exit(int status)
{
    (void) status;

    while(1);
}
#endif

#ifndef LSEEK_PROVIDED
off_t
lseek(int fd, off_t offset, int whence)
{
    (void) fd;
    (void) offset;
    (void) whence;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef GETPID_PROVIDED
pid_t
getpid(void)
{
    return 0;
}
#endif

#ifndef FSTAT_PROVIDED
int
fstat(int file, struct stat *sbuf)
{
    (void) file;
    (void) sbuf;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef CLOCK_GETTIME_PROVIDED
int
clock_gettime(clockid_t clk_id, struct timespec *tp) __THROW
{
    (void) clk_id;
    (void) tp;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef OPEN_PROVIDED
int
open(const char *file, int mode, ...)
{
    (void) file;
    (void) mode;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef CLOSE_PROVIDED
int
close(int fd)
{
    (void) fd;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef KILL_PROVIDED
int
kill(pid_t _pid, int _sig)
{
    (void) _pid;
    (void) _sig;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef ISATTY_PROVIDED
int
isatty(int fd)
{
    (void) fd;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef READ_PROVIDED
_READ_WRITE_RETURN_TYPE
read(int fd, void *buffer, size_t length)
{
    (void) fd;
    (void) buffer;
    (void) length;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef WRITE_PROVIDED
_READ_WRITE_RETURN_TYPE
write(int file, const void *buffer, size_t count)
{
    (void) file;
    (void) buffer;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef MALLOC_PROVIDED
void *
_malloc_r(size_t size)
{
    (void) size;

    return NULL;
}

void
_free_r(void *ptr)
{
    (void) ptr;
}

void *
_calloc_r(size_t nmemb, size_t size)
{
    (void) nmemb;
    (void) size;

    return NULL;
}

void *
_realloc_r(void *ptr, size_t size)
{
    (void) ptr;
    (void) size;

    return NULL;
}
#endif

void *
malloc(size_t size)
{
    (void) size;

    return NULL;
}

void
free(void *ptr)
{
    (void) ptr;
}

void *
calloc(size_t nmemb, size_t size)
{
    (void) nmemb;
    (void) size;

    return NULL;
}

void *
realloc(void *ptr, size_t size)
{
    (void) ptr;
    (void) size;

    return NULL;
}
