noinst_LIBRARIES = libcollatz.a
libcollatz_a_SOURCES = collatz.cpp 
libcollatz_a_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest


bin_PROGRAMS = check
check_SOURCES = check.cpp collatz.cpp
check_LDDADD = libcollatz.a 