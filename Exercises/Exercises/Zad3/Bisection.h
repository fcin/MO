#pragma once
#include <iostream>
#include "Consts.h"

namespace BisectionMethods
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
		const int maxIterations = 100;
		int currentIteration = 1;
		while (a < b && currentIteration < maxIterations)
		{
			double midPoint = (a + b) / 2.0;
			std::cout 
				<< "Iteracja: " 
				<< currentIteration 
				<< " Wartosc: "
				<< midPoint 
				<< " Estymator bledu: "
				<< (b - a) / 2.0
				<< std::endl;

			if (f(midPoint) == 0)
			{
				std::cout << "Znaleziony pierwiastek: " << midPoint << std::endl;
				return;
			}

			if (sign(f(midPoint)) == sign(f(a)))
				a = midPoint;
			else
				b = midPoint;

			currentIteration++;
		}

		std::cout << "NIE ZNALEZIONO PIERWIASTKA" << std::endl;
	}
}


/*double middle = (abs(b) - abs(a)) / 2;
			double debug = f(a);
			if (sign(f(a)) != sign(f(middle)))
			{
				a = a;
				b = middle;
			}
			else
			{
				a = middle;
				b = b;
			}

			std::cout << middle << std::endl;*/