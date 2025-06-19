// ANS = 73682

#include <iostream>
#include <stdint.h>

int main()
{
	uint64_t counter = 0;

	uint32_t vals[] = {1, 2, 5, 10, 20, 50, 100, 200};

	uint32_t coinsCount[8];

	uint64_t sum;

	uint32_t lastIncID = 0;

	bool finished = false;

	uint32_t maxID = 0;

	for (uint32_t i = 0; i < 8; i++)
	{
		coinsCount[i] = 0;
	}

	std::cout << maxID << '\n';

	while (true)
	{
		sum = 0;

		for (uint32_t i = 0; i < 8; i++)
		{
			sum += coinsCount[i] * vals[i];
		}

		if (sum == 200)
		{
			counter++;
			coinsCount[0]++;
			lastIncID = 0;
		}
		else if (sum > 200)
		{
			if (lastIncID == 7)
			{
				break;
			}

			for (uint32_t i = 0; i <= lastIncID; i++)
			{
				coinsCount[i] = 0;
			}

			coinsCount[lastIncID + 1]++;
			lastIncID = lastIncID + 1;

			if (lastIncID > maxID)
			{
				maxID = lastIncID;
				std::cout << maxID << '\n';
			}
		}
		else
		{
			coinsCount[0]++;
			lastIncID = 0;
		}
	}

	std::cout << "ANS : " << counter << '\n';

   std::cin.get();
}


