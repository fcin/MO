#pragma once
#include <iostream>
#include "Consts.h"

// Sposoby zakonczenia iteracji
// 1. X* == X
// 2. Xn-1 == Xn
// 3. |O'(x)| > (1)

namespace PicardMethods
{

	static double fi(double x)
	{
#ifdef SIN
		double result = sin(x / 4) * sin(x / 4);
#else
		double result = tan(2 * x);
#endif
		return result;
	}

	static double fiPrim(double x)
	{
#ifdef SIN
		double result = 0.5 * sin(x / 4.0) * cos(x / 4.0);
#else
		double result = 2 / (cos(2 * x) * cos(2 * x));
#endif
		return result;
	}


	static void run()
	{
		double ksi = 1.0;
		double previousKsi = 0.0;
		const double increment = 0.1;
		const int TOLX = 5000;
		int iterations = 0;

		while (ksi != fi(ksi) && fiPrim(ksi) != fiPrim(previousKsi) && fiPrim(ksi) < TOLX)
		{
			iterations++;
			previousKsi = ksi;
			ksi = fiPrim(ksi);
			std::cout << ksi << std::endl;
			ksi += increment;
		}
	}
}