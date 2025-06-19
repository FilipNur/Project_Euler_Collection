/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

ANSWER : 31626
*/

#include <iostream>
#include <math.h>
#include <stdint.h>

uint32_t is_amicable(uint32_t num);

int main()
{

   uint8_t used[10000] = {0};
   uint32_t a;
   uint32_t sum = 0;
   
   for(uint32_t i = 1; i <= 10000; i++)
   {
      if(used[i - 1] == 1)
      {
         continue;
      }

      a = is_amicable(i);

      if((a != 0) && (used[a - 1] == 0) && (a != i))
      {
         used[a - 1] = 1;
         used[i - 1] = 1;
         sum += a + i;
      }
   }
   
   std::cout << "ans : " << sum << '\n';
   std::cin.get();
   return 0;
}

uint32_t is_amicable(uint32_t num)
{
   uint32_t lim = std::sqrt(num);

   uint32_t s = 1; // 1 is divisor

   uint32_t s2 = 1; // 1 is divisor

   for(uint32_t i = 2; i <= lim; i++)
   {
      if((num % i) == 0)
      {
         s += i;
         s += (num / i);
      }
   }

   if((lim * lim) == num)
   {
      s -= lim;
   }

   lim = std::sqrt(s);

   for(uint32_t i = 2; i <= lim; i++)
   {
      if((s % i) == 0)
      {
         s2 += i;
         s2 += (s / i);
      }
   }

   if((lim * lim) == s)
   {
      s2 -= lim;
   }

   if(num == s2)
   {
      return s;
   }

   return 0;
}
