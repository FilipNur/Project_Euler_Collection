/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

ANSWER : 648
*/

#include <iostream>
#include <stdint.h>

int main()
{
   uint32_t sum = 0;

   uint8_t digits[100] = {1}; // [0] = 1, index [0]  is one's
   uint32_t digits_count = 1;
   uint32_t temp;
   uint32_t carry = 0;

   digits[0] = 1;

   for(uint32_t i = 2; i <= 100; i++)
   {
      carry = 0;
      for(uint32_t d = 0; d < digits_count; d++)
      {
         temp = (i * (uint32_t)(digits[d])) + carry;
         carry = (temp / 10);
         digits[d] = (temp % 10);
      }

      while(carry != 0)
      {
         digits[digits_count] = (carry % 10);
         digits_count++;
         carry = (carry / 10);
      }
   }

   for(uint32_t i = 0; i < digits_count; i++)
   {
      sum += digits[i];
   }
   
   std::cout << "ans : " << sum << '\n';
   std::cin.get();
   return 0;
}


