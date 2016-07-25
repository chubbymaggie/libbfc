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

#include <stddef.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/times.h>
#include <regex.h>

#define UNHANDLED() \
    { \
        const char *str_text = "\033[1;33mWARNING\033[0m: unsupported libc function called = "; \
        const char *str_func = __PRETTY_FUNCTION__; \
        const char *str_endl = "\n"; \
        write(0, str_text, strlen(str_text)); \
        write(0, str_func, strlen(str_func)); \
        write(0, str_endl, strlen(str_endl)); \
    }

// Supported Symbols
//
// Note, these symbols were identified by extracting the object files from
// newlib's libc.a, and then linking them together into a shared object using
// ld. Finally, using readelf, you can grep for the undefined symbols, which
// provides a list of all of the symbols that newlib needs you to provide. If
// a symbol is missing, try the following:
//
// ~/opt/cross/bin/x86_64-elf-ar x libc.a
// ~/opt/cross/bin/x86_64-elf-ld -shared -o libc.so *.o
// readelf libc.so -aW | grep UND
//
// These are the symbols that we have identified that need to be implemented.
// Note that there might be more depending on how you configure newlib to
// compile, and they might be in a different order
//
// times
// execve
// getpid
// isatty
// lseek
// _init
// write
// fstat
// kill
// wait
// read
// unlink
// fork
// sbrk
// regcomp
// gettimeofday
// clock_gettime
// regexec
// _fini
// stat
// link
// _exit
// open
// regfree
// fcntl
// mkdir
// posix_memalign
// close
// sigprocmask
// _malloc_r
// _free_r
// _calloc_r
// _realloc_r

#ifndef SYM_PROVIDED__TIMES
clock_t
times(struct tms *buf)
{
    (void) buf;

    UNHANDLED();

    return 0;
}
#endif

#ifndef SYM_PROVIDED__EXECVE
int
execve(const char *path, char *const argv[], char *const envp[])
{
    (void) path;
    (void) argv;
    (void) envp;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__GETPID
pid_t
getpid(void)
{
    UNHANDLED();

    return 0;
}
#endif

#ifndef SYM_PROVIDED__ISATTY
int
isatty(int fd)
{
    (void) fd;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__LSEEK
off_t
lseek(int fd, off_t offset, int whence)
{
    (void) fd;
    (void) offset;
    (void) whence;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__INIT
void _init(void)
{
}
#endif

#ifndef SYM_PROVIDED__WRITE
_READ_WRITE_RETURN_TYPE
write(int file, const void *buffer, size_t count)
{
    (void) file;
    (void) buffer;
    (void) count;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__FSTAT
int
fstat(int file, struct stat *sbuf)
{
    (void) file;
    (void) sbuf;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__KILL
int
kill(pid_t _pid, int _sig)
{
    (void) _pid;
    (void) _sig;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__WAIT
pid_t
wait(int *status)
{
    (void) status;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__READ
_READ_WRITE_RETURN_TYPE
read(int fd, void *buffer, size_t length)
{
    (void) fd;
    (void) buffer;
    (void) length;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__UNLINK
int
unlink(const char *file)
{
    (void) file;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__FORK
pid_t
fork(void)
{
    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__SBRK
void *
sbrk(ptrdiff_t __incr)
{
    (void) __incr;

    UNHANDLED();

    errno = -ENOSYS;
    return (void *)-1;
}
#endif

#ifndef SYM_PROVIDED__REGCOMP
int
regcomp(regex_t *preg, const char *regex, int cflags)
{
    (void) preg;
    (void) regex;
    (void) cflags;

    UNHANDLED();

    return REG_NOMATCH;
}
#endif

#ifndef SYM_PROVIDED__GETTIMEOFDAY
int
gettimeofday(struct timeval *tp, void *tzp)
{
    (void) tp;
    (void) tzp;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__CLOCK_GETTIME
int
clock_gettime(clockid_t clk_id, struct timespec *tp) __THROW
{
    (void) clk_id;
    (void) tp;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__REGEXEC
int
regexec(const regex_t *preg, const char *string,
        size_t nmatch, regmatch_t pmatch[], int eflags)
{
    (void) preg;
    (void) string;
    (void) nmatch;
    (void) pmatch;
    (void) eflags;

    UNHANDLED();

    return REG_NOMATCH;
}
#endif

#ifndef SYM_PROVIDED__FINI
void _fini(void)
{
}
#endif

#ifndef SYM_PROVIDED__STAT
int
stat(const char *pathname, struct stat *buf)
{
    (void) pathname;
    (void) buf;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__LINK
int
link(const char *oldpath, const char *newpath)
{
    (void) oldpath;
    (void) newpath;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__EXIT
void
_exit(int status)
{
    (void) status;

    UNHANDLED();

    while(1);
}
#endif

#ifndef SYM_PROVIDED__OPEN
int
open(const char *file, int mode, ...)
{
    (void) file;
    (void) mode;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__REGFREE
void
regfree(regex_t *preg)
{
    UNHANDLED();

    (void) preg;
}
#endif

#ifndef SYM_PROVIDED__FCNTL
int
fcntl(int fd, int cmd, ...)
{
    (void) fd;
    (void) cmd;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__MKDIR
int
mkdir(const char *path, mode_t mode)
{
    (void) path;
    (void) mode;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__MEMALIGN
int
posix_memalign(void **memptr, size_t alignment, size_t size)
{
    (void) memptr;
    (void) alignment;
    (void) size;

    UNHANDLED();

    return NULL;
}
#endif

#ifndef SYM_PROVIDED__CLOSE
int
close(int fd)
{
    (void) fd;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__SIGPROCMASK
int
sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
    (void) how;
    (void) set;
    (void) oldset;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}
#endif

long
sysconf(int name)
{
    (void) name;

    UNHANDLED();

    errno = -EINVAL;
    return -1;
}

int
nanosleep(const struct timespec *req, struct timespec *rem)
{
    (void) req;
    (void) rem;

    UNHANDLED();

    errno = -ENOSYS;
    return -1;
}

#ifdef MALLOC_PROVIDED

#ifndef SYM_PROVIDED__MALLOC
void *
_malloc_r(struct _reent *reent, size_t size)
{
    (void) reent;
    (void) size;

    UNHANDLED();

    return NULL;
}
#endif

#ifndef SYM_PROVIDED__FREE
void
_free_r(struct _reent *reent, void *ptr)
{
    (void) reent;
    (void) ptr;

    UNHANDLED();
}
#endif

#ifndef SYM_PROVIDED__CALLOC
void *
_calloc_r(struct _reent *reent, size_t nmemb, size_t size)
{
    (void) reent;
    (void) nmemb;
    (void) size;

    UNHANDLED();

    return NULL;
}
#endif

#ifndef SYM_PROVIDED__REALLOC
void *
_realloc_r(struct _reent *reent, void *ptr, size_t size)
{
    (void) reent;
    (void) ptr;
    (void) size;

    UNHANDLED();

    return NULL;
}
#endif

void *
malloc(size_t size)
{
    return _malloc_r(0, size);
}

void
free(void *ptr)
{
    _free_r(0, ptr);
}

void *
calloc(size_t nmemb, size_t size)
{
    return _calloc_r(0, nmemb, size);
}

void *
realloc(void *ptr, size_t size)
{
    return _realloc_r(0, ptr, size);
}

#endif
