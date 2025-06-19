/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

ANSWER : 6857
*/

#include <iostream>
#include <math.h>
#include <stdint.h>

bool is_prime(uint64_t num);

int main()
{
   uint64_t num = 600851475143;

   if(is_prime(num))
   {
      std::cout << "ans : " << num <<'\n';
      std::cin.get();
   }

   uint64_t sq = (uint64_t)std::sqrt(num);

   for(uint64_t i = sq; i >= 2; i--)
   {
      if(((num % i) == 0) && (is_prime(i)))
      {
         std::cout << "ans : " << i <<'\n';
         std::cin.get();
      }
   }

   std::cin.get();
   return 0;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

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

