#include <iostream>
#include <vector>
#include <iomanip>

std::pair<double, double> reduceMatrix(std::vector<std::vector<double>>& matrix, int index)
{
	double previousN;
	double previousU;

	if (index == 1)
	{
		previousN = matrix[0][0];
		previousU = matrix[0][1];
	}
	else
	{
		previousN = matrix[index - 1][index - 1];
		previousU = matrix[index - 1][index];
	}

	double d = matrix[index][index];
	double l = matrix[index][index - 1];

	matrix[index][index] = d - (l * (1 / previousN) * previousU);
	matrix[index][index - 1] = 0;

	return std::pair<double, double>(l, previousN);
}

void reduceVector(std::vector<double>& b, double d, double l, double previousN, int index)
{
	double r = d - (l * (1.0 / previousN) * b[index - 1]);
	b[index] = r;
}

std::vector<double> calculateResult(std::vector<std::vector<double>>& matrix, std::vector<double>& b)
{
	double xn = matrix[b.size() - 1][b.size() - 1] * b[b.size() - 1];
	std::vector<double> x = std::vector<double>(b.size());
	x[b.size() - 1] = xn;
	for (int index = (int)(b.size() - 2); index > 0; index--)
	{
		double r = b[index];
		double u = matrix[index - 1][index];

		x[index] = (1 / matrix[index][index]) * (r - (u * x[index - 1]));
	}

	return x;
}

void printSetup(std::vector<std::vector<double>>& matrix, std::vector<double>& b)
{
	std::cout << "Macierz " << matrix.size() << " X " << matrix[0].size() << ": " << std::endl;

	for (int index = 0; index < matrix.size(); index++)
	{
		for (int index2 = 0; index2 < matrix[0].size(); index2++)
		{
			std::cout << std::setw(8) << matrix[index][index2];
		}

		std::cout << std::endl;
	}

	std::cout << std::endl << "Wektor: " << std::endl;

	for (int index = 0; index < b.size(); index++)
	{
		std::cout << b[index] << ", ";
	}

	std::cout << std::endl;
}

int main()
{
	std::vector<std::vector<double>> matrix =
	{
		{ 30,   2 / 3,	0, 0, 0, 0 },
		{ 3 / 4, 20,  5 / 6, 0, 0, 0 },
		{ 0, 7 / 8, 10, 9 / 10, 0, 0 },
		{ 0, 0,	11 / 12, 10, 13 / 14, 0 },
		{ 0, 0,	0, 15 / 16, 20, 17 / 18 },
		{ 0, 0,	0, 0, 19 / 29, 30 }
	};

	std::vector<double> b = 
	{ 
		94/3,
		173/4,
		581/20,
		-815/28,
		-6301/144,
		-319/10
	};

	printSetup(matrix, b);

	for (int index = 1; index < matrix[0].size(); index++)
	{
		std::pair<double, double> result = reduceMatrix(matrix, index);
		double l = result.first;
		double previousN = result.second;

		reduceVector(b, matrix[index][index], l, previousN, index);
	}

	std::cout << std::endl << std::endl << "Po redukcji: " << std::endl;
	printSetup(matrix, b);

	std::vector<double> x = calculateResult(matrix, b);

	std::cout << "Rozwiazanie: " << std::endl;

	for (int index = 0; index < x.size(); index++)
	{
		std::cout << x[index] << ", " << std::endl;
	}

	std::cin.get();
	return 0;
}