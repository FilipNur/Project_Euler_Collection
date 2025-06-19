// ANS : 233168


#include <iostream>
#include <stdint.h>

int main()
{
   uint32_t sum = 0;

   // (uint32_t i = 3) first non 0 multiple will be 3

   for(uint32_t i = 3; i < 1000; i++)
   { 
      
      if(((i % 3) == 0) || ((i % 5) == 0))
      {
         sum += i;
      }
   }

   std::cout << "ans : " << sum << '\n';
   std::cin.get();
   return 0;
}
