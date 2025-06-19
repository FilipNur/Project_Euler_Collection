/**
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
 * 
 * 012   021   102   120   201   210
 * 
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 * 
 * 
 * ANS : 2783915460
*/

#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

uint32_t factorial(uint32_t val);

int main()
{
	std::string nums = "0123456789";

	std::string ans = "0000000000";

	uint32_t num = 9;

	uint32_t million = 1000000;

	uint32_t permutation = million;

	uint32_t ansID = 0;

	while (num > 0)
	{
		uint32_t f = factorial(num);

		uint32_t div = permutation / f;

		if (f * div < permutation)
		{
			div += 1;
		}

		div -= 1;

		permutation -= f * div;

		ans[ansID] = nums[div];

		nums.erase(nums.begin() + div);

		num--;
		ansID++;
	}

	ans[9] = nums[0];

	std::cout << "ANS : " << ans.c_str() << '\n';
   
   std::cin.get();
}


uint32_t factorial(uint32_t val)
{
	uint32_t out = 1;

	for (uint32_t num = 2; num <= val; num++)
	{
		out *= num;
	}

	return out;
}






