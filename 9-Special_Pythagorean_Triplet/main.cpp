/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^22 + 4^22 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

ANSWER : 31875000
*/

#include <iostream>
#include <stdint.h>

int main()
{  
   uint64_t a;

   for(uint64_t c = 1000; c > 0; c--)
   {
      for(uint64_t b = (1000 - c); b > 0; b--)
      {
         a = ((1000 - c) - b);
         if((a < b) && (a < c) && (b < c))
         {
            if(((a * a) + (b * b)) == (c * c))
            {
               std::cout << "ans : " << (a * b * c) << '\n';
               std::cin.get();
            }
         }
      }
   }

   std::cin.get();
   return 0;
}
