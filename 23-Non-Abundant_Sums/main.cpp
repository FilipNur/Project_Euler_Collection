/**
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example,
 * the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number. 
 * 
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two
 * abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as
 * the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is
 * known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 * 
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 * 
 * 
 * ANS : 4179871
*/

#include <iostream>

#include <stdint.h>
#include <vector>

bool isAbundant(uint32_t num);
bool canBeSum(uint32_t num);

int main()
{
	uint32_t sum = 0;

	for(uint32_t num = 1; num <= 28123; num++)
	{
		if((num % 1000) == 0)
		{
			std::cout<<num<<'\n';
		}

		if(canBeSum(num) == false)
		{
			sum += num;
		}
	}

	std::cout << "ANS : " << sum << '\n';
   
   std::cin.get();
}


bool isAbundant(uint32_t num)
{
	uint32_t sum = 0;

	for(uint32_t div = 1; div <= (num / 2); div++)
	{
		uint32_t result = num / div;
		if((result * div) == num)
		{
			sum += div;
		}
	}

	if(sum > num)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool canBeSum(uint32_t num)
{
	for(uint32_t num1 = 1; num1 <= (num / 2); num1++)
	{
		uint32_t num2 = num - num1;

		if((isAbundant(num1) == true) && (isAbundant(num2) == true))
		{
			return true;
		}
	}

	return false;
}




