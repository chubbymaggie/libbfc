# Bareflank C Library

## Description

The Bareflank C Library is a simple library that contains empty symbols that
are needed when using newlib. Most operating systems will need to implement
all of these functions, but some will only need a couple, if any. The goal of
this library is to provide the bare minimum support to get newlib up and
running.

If your operating system implements one of the functions in this library,
simply remove the symbol from this library by defining it's associated
SYM_PROVIDED__XXX macros.

Note that the symbols in this library assume that newlib has been compiled
using the following:

```
export PREFIX="$HOME/opt/cross"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"
export CFLAGS="-fpic -D_HAVE_LONG_DOUBLE -D_LDBL_EQ_DBL -D_POSIX_TIMERS -U__STRICT_ANSI__"
../newlib/configure --target=$TARGET --prefix=$PREFIX
make all
```

This library also contains the symbols needed if newlib was compiled with
MALLOC_PROVIDED. If this is defined, this library provides the malloc
symbols and the _xxx_r versions can be overridden as needed.

## Compilation Instructions

## Contributing

If you would like to participate in the development of this project, the
following Wiki page provides more information on how to do so:

https://github.com/Bareflank/hypervisor/wiki/Contributing

## License

The Bareflank Hypervisor is licensed under the GNU Lesser General Public
License v2.1 (LGPL).
