#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <utility>

#include "collatz.hpp"

uint64_t collatz(uint64_t value)
{
   uint64_t n = value;
   if(n == 0) { return 0; }

   static std::unordered_map<uint64_t, uint64_t> collatz_memo{ {1, 1} };
   if(collatz_memo.find(n) != collatz_memo.end()) {
      return collatz_memo[n];
   }
   uint64_t count = 1;
   // list of <n, count> 
   // so that we can push all the values we learn when we memoize
   // the counts are forward counts so we push <n, 1>, ...

   std::list<std::pair<uint64_t, uint64_t>> counts;
   while(n != 1) {
      counts.push_back(std::make_pair(n, count));
      if(n%2 == 0) { 
         n = n/2; 
      } else {
         n = (3*n + 1);
      }
      if(collatz_memo.find(n) != collatz_memo.end()) {
         for(const auto& n_count : counts) {
            // the n_count is a forward count, so we need to adjust the current count by k-1
            collatz_memo[n_count.first] = collatz_memo[n] + count - (n_count.second - 1);
         }
         return collatz_memo[value];
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