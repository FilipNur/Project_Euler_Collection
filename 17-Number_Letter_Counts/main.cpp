/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

ANSWER : 21124
*/

#include <iostream>
#include <stdint.h>

uint32_t get_number(uint64_t num);

int main()
{
   uint8_t nums[4] = {2, 0 ,0 ,0}; // [0] is one's
   uint8_t carry;
   uint64_t count = 14; // 1 and 1000

   uint64_t add;

   while(nums[3] != 1)
   {
      if(nums[2] != 0)
      {
         if(nums[1] == 1)
         {
            add = get_number(nums[2]);
            add += 7; // hundred
            add += 3; // and
            add += get_number(10 + nums[0]);


            if((UINT64_MAX - count) < add)
            {
               std::cout << "Value bigger than (2^64 - 1)\n";
               std::cin.get();
            }

            count += add;
         }
         else
         {
            add = get_number(nums[2]);
            add += 7; // hundred

            if((nums[0] != 0) || (nums[1] != 0))
            {
               add += 3; // and
               add += get_number(nums[0]);
               add += get_number(nums[1] * 10);
            }

            if((UINT64_MAX - count) < add)
            {
               std::cout << "Value bigger than (2^64 - 1)\n";
               std::cin.get();
            }

            count += add;
         }
      }
      else
      {
         if(nums[1] == 1)
         {
            add = get_number(10 + nums[0]);

            if((UINT64_MAX - count) < add)
            {
               std::cout << "Value bigger than (2^64 - 1)\n";
               std::cin.get();
            }

            count += add;
         }
         else
         {
            add = get_number(nums[0]);
            add += get_number(nums[1] * 10);

            if((UINT64_MAX - count) < add)
            {
               std::cout << "Value bigger than (2^64 - 1)\n";
               std::cin.get();
            }

            count += add;
         }
      }

      nums[0]++;
      carry = (nums[0] / 10);
      nums[0] = (nums[0] % 10);

      nums[1] += carry;
      carry = (nums[1] / 10);
      nums[1] = (nums[1] % 10);

      nums[2] += carry;
      carry = (nums[2] / 10);
      nums[2] = (nums[2] % 10);

      nums[3] += carry;
   }

   std::cout << "ans : " << count << '\n';
   std::cin.get();
   return 0;
}


uint32_t get_number(uint64_t num)
{
   switch(num)
   {
      case 0:
         return 0;
      case 1:
         return 3;
      case 2:
         return 3;
      case 3:
         return 5;
      case 4:
         return 4;
      case 5:
         return 4;
      case 6:
         return 3;
      case 7:
         return 5;
      case 8:
         return 5;
      case 9:
         return 4;
      case 10:
         return 3;
      case 11:
         return 6;
      case 12:
         return 6;
      case 13:
         return 8;
      case 14:
         return 8;
      case 15:
         return 7;
      case 16:
         return 7;
      case 17:
         return 9;
      case 18:
         return 8;
      case 19:
         return 8;
      case 20:
         return 6;
      case 30:
         return 6;
      case 40:
         return 5;
      case 50:
         return 5;
      case 60:
         return 5;
      case 70:
         return 7;
      case 80:
         return 6;
      case 90:
         return 6;
      default:
         return 0;
   }
}


