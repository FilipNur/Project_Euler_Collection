// ANS : -59231


#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

uint32_t getNextPrime(uint32_t val);
bool isPrime(uint32_t val);
uint32_t primeChain(int32_t a, int32_t b);

int main()
{
	uint32_t b = 2;

	int32_t best_a = -1000;
	int32_t best_b = 2;
	uint32_t longestPrimeChain = 0;

	while (b <= 1000)
	{
		for (int32_t a = -999; a < 1000; a++)
		{
			uint32_t length = primeChain(a, b);

			if(length > longestPrimeChain)
			{
				best_a = a;
				best_b = b;
				longestPrimeChain = length;
			}
		}

		b = getNextPrime(b);
	}

	std::cout << "ANS : " << ((int64_t)best_a * (int64_t)best_b) << '\n';
   
   std::cin.get();
}


uint32_t getNextPrime(uint32_t val)
{
	while (val <= 2000)
	{
		val++;

		for (uint32_t i = 2; i <= (uint32_t)sqrt((double)val); i++)
		{
			uint32_t div = val / i;

			if ((div * i) == val)
			{
				goto label_notPrime;
			}
		}

		return val;

		label_notPrime:;
	}

	std::cout << "ERR : val > 2000!\n";
	std::cin.get();
	return 0;
}

bool isPrime(uint32_t val)
{
	for (uint32_t i = 2; i <= (uint32_t)sqrt((double)val); i++)
	{
		if ((val % i) == 0)
		{
			return false;
		}
	}

	return true;
}

uint32_t primeChain(int32_t a, int32_t b)
{
	int32_t n = 0;
	uint32_t primeChainLength = 0;

	while (true)
	{
		int32_t val = n*n + a*n + b;

		if (isPrime(val) == true)
		{
			primeChainLength++;
		}
		else
		{
			return primeChainLength;
		}

		n++;
	}
}








