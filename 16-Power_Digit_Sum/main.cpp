/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

ANSWER : 1366
*/

#include <iostream>
#include <stdint.h>

int main()
{  
   uint8_t digits[1000] = {2};
   uint32_t power = 1;
   uint32_t carry;
   uint32_t current_digits = 1;
   

   again:

   carry = 0;
   for(uint32_t i = 0; i < current_digits; i++)
   {
      digits[i] *= 2;
      digits[i] += carry;
      carry = (digits[i] / 10);
      digits[i] = (digits[i] % 10);
   }

   if(carry != 0)
   {
      if(current_digits == 1000)
      {
         std::cout << "Too little space for digits!\n";
         std::cin.get();
      }

      digits[current_digits] = carry;
      current_digits++;  
   }

   power++;

   if(power != 1000)
   {
      goto again;
   }

   uint32_t sum = digits[0];

   for(uint32_t i = 1 ; i < current_digits; i++)
   {
      sum += digits[i];
   }

   std::cout << "ans : " << sum << '\n';

   std::cin.get();
   return 0;
}