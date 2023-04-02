#include <cstdint>
#include <iostream>

#include "collatz.hpp"

int main(int argc, char* argv[])
{
   if(argc != 2) {
      std::cerr << argv[0] << " n" << std::endl;
      return -1;
   }
   uint64_t n = std::stoull(argv[1]);
   verify(n);
   return 0;
}