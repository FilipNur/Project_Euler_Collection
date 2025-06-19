// ANS : 9183

#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>
#include <math.h>
#include <unordered_set>

int main()
{
	std::unordered_set<double> values;

	for (uint32_t a = 2; a <= 100; a++)
	{
		for (uint32_t b = 2; b <= 100; b++)
		{
			// no confidence in used method, but answer was correct
			// 100% accurate would be to use integer type that is comprised out of 11 64 bit integers, each having 19 digits
			values.insert(pow((double)a, (double)b));
		}
	}

	std::cout << "ANS : " << values.size() << '\n';

   std::cin.get();
}


