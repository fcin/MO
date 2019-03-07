#include <iostream>

#define TYPE double

int main()
{
	int bits = 0;
	TYPE value = 1;
	while (1 + value * (TYPE)0.5 > (TYPE)1)
	{
		bits++;
		value *= (TYPE)0.5;
		std::cout
			<< "Rozmiar mantysy: "
			<< bits
			<< std::endl
			<< "Epsilon: "
			<< value
			<< std::endl;
	}

	std::cin.get();
	return 0;
}