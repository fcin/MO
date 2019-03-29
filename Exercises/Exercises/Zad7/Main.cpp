#include <iostream>
#include <vector>
#include "Jacobi.h"
#include "GaussSeidel.h"
#include "SOR.h"

int main()
{
	std::cout << "Metoda Jacobiego" << std::endl << std::endl;
	JacobiMethods::Jacobi();

	std::cout << std::endl << std::endl << "Metoda Gaussa-Seidela" << std::endl << std::endl;
	GaussSeidelMethods::GaussSeidel();

	std::cout << std::endl << "Metoda SOR" << std::endl << std::endl;
	SORMethods::SOR();

	std::cin.get();

	return 0;
}