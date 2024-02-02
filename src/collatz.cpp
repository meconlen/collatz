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
std::cout << value << ", " << counts.size() << ", " << collatz_memo.size() << ", " << 0 << ", " << collatz_memo.begin()->first << std::endl;
         return collatz_memo[value];
      }
      ++count;
   }
   return count;
}

bool collatz_validate(uint64_t value)
{
   if(value == 0) { return false; }
   uint64_t n = value;
   static std::unordered_map<uint64_t, bool> collatz_memo{ {1, true} };
   static uint64_t tested = 0;
   if(n <= tested || collatz_memo.find(n) != collatz_memo.end()) {
      return true;
   }
   std::list<uint64_t> checked_values; 
   while(n != 1) {
      checked_values.push_back(n); 
      if(n%2 == 0) {
         n = n/2;
      } else {
         n = 3*n + 1; 
      }
      if(n <= tested || collatz_memo.find(n) != collatz_memo.end()) {
         for(const auto& k : checked_values) {
            collatz_memo[k] = true;
         }
         while(collatz_memo.find(tested+1) != collatz_memo.end()) {
            collatz_memo.erase(tested+1);
            ++tested;
         }
std::cout << value << ", " << checked_values.size() << ", " << collatz_memo.size() << ", " << tested << ", " << tested - value << std::endl;
         return true;
      }
   }
   return true;
}

bool collatz_sequential(uint64_t value)
{
   if(value == 0) { return false; }
   if(value == 1) { return true; }
   uint64_t n = value;
   while(n >= value) {
      if(n%2 == 0) {
         n = n/2;
      } else {
         if(n >= 6148914691236517205) { return false; }
         n = (3*n + 1)/2; 
      }
   }
   return true;
}

bool verify(uint64_t n) {
   // we know every even number will be valid because it automatically goes to i/2 which will have
   // been verified. 
   for(uint64_t i = 1; i < n; i+=2) {
      if(collatz_sequential(i) == false) { 
         std::cout << "stopped at " << i << std::endl;
         return false; 
      }
   }
   return true;
}