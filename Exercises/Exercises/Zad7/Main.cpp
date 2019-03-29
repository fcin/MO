#include <iostream>
#include <vector>
#include "Jacobi.h"
#include "GaussSeidel.h"

int main()
{
	//JacobiMethods::Jacobi();
	GaussSeidelMethods::GaussSeidel();

	std::cin.get();

	return 0;
}