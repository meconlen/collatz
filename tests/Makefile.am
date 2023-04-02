check_LTLIBRARIES = libgtest.la 

libgtest_la_SOURCES = $(top_srcdir)/googletest/googletest/src/gtest-assertion-result.cc \
   $(top_srcdir)/googletest/googletest/src/gtest-death-test.cc \
   $(top_srcdir)/googletest/googletest/src/gtest-filepath.cc \
   $(top_srcdir)/googletest/googletest/src/gtest-matchers.cc \
   $(top_srcdir)/googletest/googletest/src/gtest-port.cc \
   $(top_srcdir)/googletest/googletest/src/gtest-printers.cc \
   $(top_srcdir)/googletest/googletest/src/gtest-test-part.cc \
   $(top_srcdir)/googletest/googletest/src/gtest-typed-test.cc \
   $(top_srcdir)/googletest/googletest/src/gtest.cc 

libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest
libgtest_la_LDFLAGS = -pthread

test_SOURCES = test.cpp 
test_LDFLAGS = -pthread
test_CPPFLAGS = -I$(top_srcdir)/src/CXX/ -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest -pthread

benchmark_SOURCES = benchmark.cpp 
benchmark_LDFLAGS = -pthread 
benchmark_CPPFLAGS = -I$(top_srcdir)/src/CXX/ -I$(top_srcdir)/nanobench/src/include/ -I$(top_srcdir)/nanobench/src/test/ -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest -pthread

check_PROGRAMS = test
bin_PROGRAMS = benchmark

TESTS = test

