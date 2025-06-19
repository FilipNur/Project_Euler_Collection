/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

ANSWER : 906609
*/

#include <iostream>
#include <stdint.h>
#include <string>

bool is_palindrome(uint32_t num);

int main()
{  
   uint32_t largest = 0;
   uint32_t n;

   for(uint32_t a = 999; a >= 100; a--)
   {
      for(uint32_t b = a; b >= 100; b--)
      {
         n = a * b;
         if(is_palindrome(n))
         {
            if(n > largest)
            {
               largest = n;
            }
         }
      }
   }

   std::cout << "ans : " << largest << '\n';
   std::cin.get();
   return 0;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

bool is_palindrome(uint32_t num)
{  
   std::string str = std::to_string(num);

   uint32_t l = str.length();

   uint32_t l_2 = l / 2;

   for(uint32_t i = 0; i <= l_2; i++)
   {
      if(str[i] != str[l - 1 - i])
      {
         return false;
      }
   }

   return true;
}

