/*
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is

3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

ANSWER : 25164150
*/

#include <iostream>
#include <stdint.h>

int main()
{  
   uint64_t s_sq = 0;
   uint64_t sq_s = 0;

   for(uint64_t i = 1; i <= 100; i++)
   {
      s_sq += i;
      sq_s += (i * i);
   }

   s_sq *= s_sq;

   if(s_sq > sq_s)
   {
      std::cout << "ans : " << (s_sq - sq_s) << '\n';
   }
   else
   {
      std::cout << "ans : " << (sq_s - s_sq) << '\n';
   }

   std::cin.get();
   return 0;
}

