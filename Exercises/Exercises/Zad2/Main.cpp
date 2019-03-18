#include <fstream>
#include <string>
#include <iostream>
#include "Data.h"

unsigned int factorial(unsigned int n)
{
	if (n == 0)
		return 1;

	unsigned int ret = 1;
	for (unsigned int i = 1; i <= n; ++i)
		ret *= i;
	return ret;
}

double f(double x)
{
	const double val = 1;
	return (val - exp(-x)) / x;
}

double f2(double x, int n)
{
	double result = 0;
	// E (x^n)/n!
	for (int k = 0; k < n; k++)
	{
		for (int k2 = 0; k2 < k; k2++)
		{
			result += x * x / factorial(k2);
		}
	}

	// (1 - 1 /E(x^n)/n!) / x
	return ((double)1 - (1 / result)) / x;
}

int main()
{
	std::cout.precision(12);

	for (size_t index = 0; index < values.size(); index++)
	{
		double x = values[index];
		double valueAccurate = exact[index];
		double fResult = f(x);
		double f2Result = f2(x, 50);
		double absoluteError = abs(f2Result - valueAccurate);
		double relativeError = absoluteError / valueAccurate;

		std::cout
			<< x
			<< " , "
			<< valueAccurate
			<< " , "
			<< fResult
			<< " , "
			<< f2Result
			<< " , "
			<< relativeError
			<< std::endl;
	}

	std::cin.get();
	return 0;
}

