/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

ANSWER : 142913828922
*/

#include <iostream>
#include <math.h>
#include <stdint.h>

bool is_prime(uint64_t num);

int main()
{  
   uint64_t sum = 0;

   for(uint64_t i = 2; i < 2000000; i++)
   {
      if(is_prime(i))
      {
         sum += i;
      }
   }

   std::cout << "ans : " << sum << '\n';
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
