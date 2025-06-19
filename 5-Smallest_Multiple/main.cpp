/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

ANSWER : 232792560
*/

#include <iostream>
#include <stdint.h>

int main()
{  
   // (i != 0) against loop around of unsigned value
   // (i += 2) only even values will be suitable
   for(uint64_t i = 20; i != 0; i += 2)
   {
      for(uint32_t d = 2; d <= 20; d++)
      {
         if((i % d) != 0)
         {
            goto next;
         }
      }

      std::cout << "ans : " << i << '\n';
      std::cin.get();

      next:;
   }

   std::cout << "Value bigger than (2^64 - 1)\n";
   std::cin.get();
   return 0;
}

