AC_PREREQ(2.61)
AC_INIT([collatz], [0.1], [mike@conlen.org])
AC_CONFIG_SRCDIR([src/collatz.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])
AC_PROG_CXX([g++])
AC_HEADER_STDC

AM_PROG_AR
LT_INIT
AC_CONFIG_MACRO_DIRS([m4])

CXXFLAGS="$CXXFLAGS --std=c++20"
LDFLAGS="$LDFLAGS"
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([malloc.h])
AC_CHECK_HEADERS([sys/malloc.h])
AC_CHECK_HEADERS([malloc/malloc.h])
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([fstat])
AC_CONFIG_FILES([Makefile
	src/Makefile
	tests/Makefile])

AC_OUTPUT

