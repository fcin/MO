#include <iostream>
#include "Picard.h"
#include "Bisection.h"
#include "Falsi.h"
#include "Newton.h"
#include "Secant.h"

int main()
{
	std::cout.precision(12);

	//PicardMethods::run();
	//BisectionMethods::run(-15, 5);
	//FalsiMethods::run(15, 5);
	//NewtonMethods::run();
	SecantMethods::run();

	std::cin.get();
	return 0;
}