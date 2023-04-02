#include <cstdint>

#include "collatz.hpp"

uint64_t collatz(uint64_t n)
{
   if(n == 0) { return 0; }
   uint64_t count = 1;
   while(n != 1) {
      if(n%2 == 0) { 
         n = n/2; 
      } else {
         n = (3*n + 1);
      }
      ++count;
   }
   return count;
}

bool verify(uint64_t n) {
   bool okay = true;
   for(uint64_t i = 1; i < n; i++) {
      if(collatz(i) == 0) { okay = false; }
   }
   return okay;
}