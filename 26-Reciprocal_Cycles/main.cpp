// ANS : 983

#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>


int main()
{
	uint64_t lastSeen[1000];

	uint32_t longest = 0;
	uint32_t longest_n = 0;;

	for (uint32_t n = 2; n <= 1000; n++)
	{
		for (uint32_t i = 0; i < 1000; i++)
		{
			lastSeen[i] = 0;
		}

		uint32_t num = 1;

		uint32_t digit = 1;

		while (true)
		{
			while (num < n)
			{
				digit++;
				num *= 10;
			}

			while (num > n)
			{
				num -= n;
			}

			if (lastSeen[num - 1] != 0)
			{
				if(digit - lastSeen[num - 1] > longest)
				{
					longest = digit - lastSeen[num - 1];
					longest_n = n;
				}
				break;
			}
			else
			{
				lastSeen[num - 1] = digit;
			}
		}
	}

	std::cout << "ANS : " << longest_n << '\n';

   std::cin.get();
}


