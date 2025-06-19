/*
The Fibonacci sequence is defined by the recurrence relation:
F(n) = F(n-1) + F(n-2) , where F(1) = 1 and F(2) = 1.

The 12th term, F(12), is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

ANS = 4782
*/

#include <iostream>
#include <vector>

void add_vectors(std::vector<uint8_t> &vec1, std::vector<uint8_t> &vec2);

int main()
{
   std::vector<std::vector<uint8_t>> nums;

   nums.resize(2);

   for(uint32_t i = 0; i < nums.size(); i++)
   {
      nums[i].resize(1000);

      for(uint32_t n = 0 ; n < nums[i].size(); n++)
      {
         nums[i][n] = 0;
      }
   }

   nums[0][0] = 1;
   nums[1][0] = 1;

   uint32_t calculating_index = 3;

   while(true)
   {
      add_vectors(nums[(calculating_index + 1) % 2], nums[(calculating_index) % 2]);

      if(nums[(calculating_index + 1) % 2][999] != 0)
      {
         break;
      }

      calculating_index++;
   } 

   std::cout << "ANS = " << calculating_index << '\n';

   std::cin.get();
   return 0;
}

void add_vectors(std::vector<uint8_t> &vec1, std::vector<uint8_t> &vec2)
{
   // vec1 will contain sum

   uint8_t sum = 0;
   uint8_t carry = 0;

   for(uint32_t i = 0; i < 1000; i++)
   {
      sum = carry + vec1[i] + vec2[i];
      carry = 0;

      if(sum >= 10)
      {
         sum -= 10;
         carry = 1;
      }

      vec1[i] = sum;
   }
}






