#include <cstdint>
#include <iostream>
#include <map>

#include "collatz.hpp"

uint64_t collatz(uint64_t value)
{
   uint64_t n = value;
   if(n == 0) { return 0; }

   static std::map<uint64_t, uint64_t> collatz_memo{ {1, 1} };
   if(collatz_memo.find(n) != collatz_memo.end()) {
      return collatz_memo[n];
   }
   uint64_t count = 1;
   while(n != 1) {
      if(n%2 == 0) { 
         n = n/2; 
      } else {
         n = (3*n + 1);
      }
      if(collatz_memo.find(n) != collatz_memo.end()) {
         collatz_memo[value] = collatz_memo[n] + count;
         return collatz_memo[n] + count;
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