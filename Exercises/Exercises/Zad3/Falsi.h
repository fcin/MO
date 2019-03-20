#pragma once
#include <iostream>

namespace FalsiMethods
{
	static double f(double x)
	{
#ifdef SIN
		double result = sin(x / 4) * sin(x / 4) - x;
#else
		double result = tan(2 * x) - x - 1;
#endif
		return result;
}

	static int sign(double x)
	{
		return x >= 0 ? 1 : -1;
	}

	static void run(double a, double b)
	{
		const double epsilon = 10000;

		double x = 0.0;
		double iteration = 0;
		do
		{
			iteration++;

			x = (a * f(b) - b * f(a)) / (f(b) - f(a));

			std::cout << "Iteracja: " << iteration << " Wartosc: " << x << std::endl;

			if (f(x) == 0)
			{
				std::cout << "Pierwiastek: " << x << std::endl;
				return;
			}

			if (f(a) * f(x) > 0)
				a = x;
			else
				b = x;
		} while (a != b && abs(f(x)) < epsilon);
	}
}
