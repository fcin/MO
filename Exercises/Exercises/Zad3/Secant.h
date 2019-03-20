#pragma once
#include <iostream>

namespace SecantMethods
{
	static double f(double x)
	{
#ifdef SIN
		double result = (sin(x / 4.0) * sin(x / 4.0)) - x;
#else
		double result = tan(2.0 * x) - x - 1.0;
#endif
		return result;
	}

	static double fPrim(double x)
	{
#ifdef SIN
		double result = (0.5 * sin(x / 4.0) * cos(x / 4.0)) - 1.0;
#else
		double result = -1.0 + (2.0 / (cos(2.0 * x) * cos(2.0 * x)));
#endif
		return result;
	}

	static void run()
	{
		const int maxIterations = 1000;
		const double TOLF = 0.01;

		int currentIteration = 0;
		double xn = 6; // Wartosc od ktorej zaczyna liczyc
		double xn2 = 5; // Wartosc od ktorej zaczyna liczyc
		while (currentIteration < maxIterations)
		{
			currentIteration++;
			double approximation = (f(xn) - f(xn2)) / (xn - xn2);
			xn = xn - (f(xn) / approximation);
			std::cout
				<< "Iteracja: "
				<< currentIteration
				<< " Wartosc: "
				<< xn
				<< " Reziduum: "
				<< abs(f(xn))
				<< std::endl;

			if (abs(f(xn)) <= TOLF)
			{
				std::cout << "Pierwiastek: " << xn << std::endl;
				return;
			}
		}

		std::cout << "NIE ZNALEZIONO PIERWIASTKA" << std::endl;
	}
}
