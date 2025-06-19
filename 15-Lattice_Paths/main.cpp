/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

   __    _      
     |    |_
     |      | ...

How many such routes are there through a 20×20 grid?

ANSWER : 137846528820
*/


/*
   only horizontal lines:

   if first is n spaces from top (0-20) then next can be m spaces (n-20)
*/

#include <iostream>
#include <stdint.h>

int main()
{
   uint64_t div[20];

   for(uint32_t i = 0; i < 20; i++)
   {
      div[i] = (i + 1);
   }

   uint64_t nom = 1;
   for(uint32_t i = 40; i > 20; i--)
   {
      if(nom > (UINT64_MAX / i))
      {
         for(uint32_t i = 0; i < 20; i++)
         {
            if((nom % div[i]) == 0)
            {
               nom /= div[i];
               div[i] = 1;
            }
         }

         if(nom > (UINT64_MAX / i))
         {
            std::cout << "Value bigger than (2^64 - 1)\n";
            std::cin.get();
         }
      }
      nom *= i;
   }

   for(uint32_t i = 0; i < 20; i++)
   {
      nom /= div[i];
   }

   std::cout << "ans : " << nom << '\n';
   std::cin.get();
   return 0;
}

/* int main()
{  
   // 20 - 1
   uint32_t positions[18]; // 0 - lowest, index 0 is third from the right
   uint64_t combinations = 0;
   uint32_t col = 0;

   for(uint32_t i = 0; i < 18; i++)
   {
      positions[i] = 0;
   }

   again:
   
/*    for(uint32_t i = 1; i <= positions[0]; i++)
   {
      combinations += i;
   }

   combinations += (positions[0] + 1); *//*
// VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
   combinations += ((positions[0] + 1) * (positions[0] + 2)) / 2;

   col = 0;

   while((col < 17) && (positions[col] == positions[col + 1]))
   {
      positions[col] = 0;
      col++;
   }

   if((col == 17) && (positions[17] == 20))
   {
      std::cout << "ans : " << combinations << '\n';
      std::cin.get();
   }

   positions[col]++;

   goto again;

   std::cin.get();
   return 0;
} */