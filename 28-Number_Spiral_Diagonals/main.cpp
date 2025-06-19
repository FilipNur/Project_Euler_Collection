// ANS : 669171001


#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>


int main()
{
	uint64_t sum = 1;
	uint64_t prevVal = 1;
	uint64_t diff = 2;
	uint32_t size = 1;

	while(size < 1001)
	{
		for(uint32_t i = 0; i < 4; i++)
		{
			prevVal += diff;
			sum += prevVal;
		}

		size += 2;

		diff += 2;
	}

	std::cout << "ANS : " << sum << '\n';
   
   std::cin.get();
}


