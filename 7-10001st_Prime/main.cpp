/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

ANSWER : 104743
*/

#include <iostream>
#include <math.h>
#include <stdint.h>

bool is_prime(uint64_t num);

int main()
{  
   uint32_t prime = 0;

   // (i != 0) to avoid loo around of insigned value
   for(uint64_t i = 2; i != 0; i++)
   {
      if(is_prime(i))
      {
         prime++;

         if(prime == 10001)
         {
            std::cout << "ans : " << i << '\n';
            std::cin.get();
         }
      }
   }

   std::cout << "Value bigger than (2^64 - 1)\n";
   std::cin.get();
   return 0;
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

bool is_prime(uint64_t num)
{
   if((num == 0) || (num == 1))
   {
      return false;
   }

   if((num == 2) || (num == 3))
   {
      return true;
   }

   uint64_t lim = std::sqrt(num);

   for(uint64_t i = 2; i <= lim; i++)
   {
      if((num % i) == 0)
      {
         return false;
      }
   }

   return true;
}