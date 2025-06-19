// ANS : 443839

#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

int main()
{
	std::string num;
	uint32_t sum;
	uint32_t digit;
	uint64_t sumsum = 0;

	for (uint32_t i = 10; i <= 354294; i++)
	{
		num = std::to_string(i);
		sum = 0;

		for (uint32_t j = 0; j < num.length(); j++)
		{
			digit = num[j] - '0';

			sum += digit * digit * digit * digit * digit;
		}

		if(sum == i)
		{
			sumsum += i;
		}
	}

	std::cout << "ANS : " << sumsum << '\n';

   std::cin.get();
}


