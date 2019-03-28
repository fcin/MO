#include <iostream>
#include <vector>

int main()
{
	std::cout.precision(12);

	std::vector<std::vector<double>> matrix =
	{
		{ 100,	1,		-2,		3 },
		{ 4,	300,	-5,		6 },
		{ 7,	-8,		400,	9 },
		{ -10,	11,		-12,	200 }
	};

	std::vector<std::vector<double>> matrixL =
	{
		{ 0,	 0,		 0,		0 },
		{ 4,	 0,		 0,		0 },
		{ 7,	-8,		 0,		0 },
		{ -10,	11,		-12,	0 }
	};

	std::vector<std::vector<double>> matrixD =
	{
		{ 100,	0,		 0,		0 },
		{ 0,	300,	 0,		0 },
		{ 0,	0,		400,	0 },
		{ 0,	0,		  0,	200 }
	};

	std::vector<std::vector<double>> matrixU =
	{
		{ 0,	1,		-2,		3 },
		{ 0,	0,		-5,		6 },
		{ 0,	0,		 0,		9 },
		{ 0,	0,		 0,		0 }
	};

	std::vector<double> b = { 395, 603, -415, -606 };
	std::vector<double> x = { 1, 1, 1, 1 };

	for (int iterations = 0; iterations < 100; iterations++)
	{
		std::vector<double> newX = std::vector<double>(x.size());

		for (int index = 0; index < x.size(); index++)
		{
			double d = 1.0 / matrixD[index][index];
			double lu = 0;

			for (int luIndex = 0; luIndex < x.size(); luIndex++)
				lu += (matrixL[index][luIndex] + matrixU[index][luIndex]) * x[index];

			double m = -d * lu;
			double c = d * b[index];
			newX[index] = m + c;
			std::cout << newX[index] << ", ";
		}

		x = newX;
		std::cout << std::endl;
	}

	std::cin.get();

	return 0;
}