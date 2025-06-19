// ANS : 1533776805

#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

uint64_t Triangular(uint64_t n);
uint64_t Pentagonal(uint64_t n);
uint64_t Hexagonal(uint64_t n);

int main()
{
	uint64_t T_ID = 285;
	uint64_t P_ID = 165;
	uint64_t H_ID = 143;

	while (true)
	{
		T_ID++;

		P_ID = 165;
		while (true)
		{
			P_ID++;

			if (Triangular(T_ID) == Pentagonal(P_ID))
			{
				// good
				break;
			}
			else if (Triangular(T_ID) < Pentagonal(P_ID))
			{
				goto label_notFound;
			}
		}

		H_ID = 143;
		while (true)
		{
			H_ID++;

			if (Triangular(T_ID) == Hexagonal(H_ID))
			{
				// good
				break;
			}
			else if (Triangular(T_ID) < Hexagonal(H_ID))
			{
				goto label_notFound;
			}
		}

		break;

		label_notFound:;
	}

	std::cout << "ANS : " << Triangular(T_ID) << '\n';
   
   std::cin.get();
}

uint64_t Triangular(uint64_t n)
{
	return ((n * (n + 1)) / 2);
}

uint64_t Pentagonal(uint64_t n)
{
	return ((n * ((3 * n) - 1)) / 2);
}


uint64_t Hexagonal(uint64_t n)
{
	return (n * ((2 * n) - 1));
}


