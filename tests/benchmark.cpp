#include <cstdint>

#include "collatz.hpp"

#define ANKERL_NANOBENCH_IMPLEMENT
#include <nanobench.h>

int main(int argc, char* argv[])
{
   ankerl::nanobench::Bench().run("collatz(1000000)", [&] {
      collatz(100000);
   });

   ankerl::nanobench::Bench().run("verify(1000)", [&] {
      ankerl::nanobench::doNotOptimizeAway(verify(1000));
   });

   return 0;
}
