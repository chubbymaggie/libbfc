#include <stddef.h>

#include <regex.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/times.h>

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

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__GETPID
pid_t
getpid(void)
{
    return 0;
}
#endif

#ifndef SYM_PROVIDED__ISATTY
int
isatty(int fd)
{
    (void) fd;

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

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__KILL
pid_t
wait(int *status)
{
    (void) status;

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

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__UNLINK
int
unlink(const char *file)
{
    (void) file;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__FORK
pid_t
fork(void)
{
    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__SBRK
void *
sbrk(ptrdiff_t __incr)
{
    (void) __incr;

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

    return REG_NOMATCH;
}
#endif

#ifndef SYM_PROVIDED__GETTIMEOFDAY
int
gettimeofday(struct timeval *tp, void *tzp)
{
    (void) tp;
    (void) tzp;

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

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__EXIT
void
_exit(int status)
{
    (void) status;

    while(1);
}
#endif

#ifndef SYM_PROVIDED__OPEN
int
open(const char *file, int mode, ...)
{
    (void) file;
    (void) mode;

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__REGFREE
void
regfree(regex_t *preg)
{
    (void) preg;
}
#endif

#ifndef SYM_PROVIDED__FCNTL
int
fcntl(int fd, int cmd, ...)
{
    (void) fd;
    (void) cmd;

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

    errno = -ENOSYS;
    return -1;
}
#endif

#ifndef SYM_PROVIDED__MKDIR
int
posix_memalign(void **memptr, size_t alignment, size_t size)
{
    (void) memptr;
    (void) alignment;
    (void) size;

    return NULL;
}
#endif

#ifndef SYM_PROVIDED__CLOSE
int
close(int fd)
{
    (void) fd;

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

    errno = -ENOSYS;
    return -1;
}
#endif

#ifdef MALLOC_PROVIDED

void *_malloc_r(size_t size);
void _free_r(void *ptr);
void *_calloc_r(size_t nmemb, size_t size);
void *_realloc_r(void *ptr, size_t size);

#ifndef SYM_PROVIDED__MALLOC
void *
_malloc_r(size_t size)
{
    (void) size;

    return NULL;
}
#endif

#ifndef SYM_PROVIDED__FREE
void
_free_r(void *ptr)
{
    (void) ptr;
}
#endif

#ifndef SYM_PROVIDED__CALLOC
void *
_calloc_r(size_t nmemb, size_t size)
{
    (void) nmemb;
    (void) size;

    return NULL;
}
#endif

#ifndef SYM_PROVIDED__REALLOC
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
    return _malloc_r(size);
}

void
free(void *ptr)
{
    _free_r(ptr);
}

void *
calloc(size_t nmemb, size_t size)
{
    return _calloc_r(nmemb, size);
}

void *
realloc(void *ptr, size_t size)
{
    return _realloc_r(ptr, size);
}

#endif
