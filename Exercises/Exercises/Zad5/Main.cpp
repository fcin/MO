#include <iostream>
#include <vector>
#include <iomanip>
#include "RowDetails.h"

void printResult(std::vector<std::vector<double>>& a, std::vector<double>& b, std::vector<std::vector<double>>& l, std::vector<double>& x)
{
	std::cout << "A:" << std::endl;

	for (int y = 0; y < a.size(); y++)
	{
		for (int z = 0; z < a.size(); z++)
		{
			std::cout << std::setw(8) << a[y][z] << ", ";
		}

		std::cout << " | " << b[y];

		std::cout << std::endl;
	}

	std::cout << "L:" << std::endl;

	for (int y = 0; y < l.size(); y++)
	{
		for (int z = 0; z < l.size(); z++)
		{
			std::cout << std::setw(10) << l[y][z] << ", ";
		}

		std::cout << std::endl;
	}

	std::cout << "WYNIK:" << std::endl;

	for (int i = 0; i < x.size(); i++)
	{
		std::cout << x[i] << std::endl;
	}
}

RowDetails reduceRow(std::vector<std::vector<double>>& a, int rowIndex, int iter)
{
	int rowWidth = (int)a[0].size();
	int start = iter;

	std::vector<double> currentRow = a[rowIndex];

	double firstCurrentRowValue = currentRow[start];
	double firstValue = a[start][start];
	double rowCoefficient = (firstCurrentRowValue / firstValue);

	for (int colIndex = start; colIndex < rowWidth; colIndex++)
	{
		double currentValue = currentRow[colIndex];
		double firstRowValueAbove = a[start][colIndex];
		double value = (firstRowValueAbove * rowCoefficient);
		double result = currentValue - value;
		a[rowIndex][colIndex] = result;
	}

	return { currentRow[start], rowCoefficient };
}

void swapRowsIfNeeded(std::vector<std::vector<double>>& a, std::vector<double>& b)
{
	for (int rowIndex = 1; rowIndex < a.size() - 1 /* ignore last row*/; rowIndex++)
	{
		double firstRowValue = a[rowIndex][rowIndex];

		if (firstRowValue == 0)
		{
			double max = firstRowValue;
			int maxIndex = rowIndex;
			for (int i = rowIndex; i < a.size(); i++)
			{
				if (a[i][rowIndex] > max)
				{
					max = a[i][rowIndex];
					maxIndex = i;
				}
			}
			if (max != firstRowValue)
			{
				std::vector<double> tempA = a[maxIndex];
				a[maxIndex] = a[rowIndex];
				a[rowIndex] = tempA;

				// Pamietaj zeby jeszcze zamienic wektor b
				double tempB = b[maxIndex];
				b[maxIndex] = b[rowIndex];
				b[rowIndex] = tempB;
			}

			std::cout
				<< std::endl
				<< "[MAX: "
				<< max
				<< " AT "
				<< maxIndex
				<< " SWAP WITH ROW "
				<< rowIndex
				<< "]"
				<< std::endl;
		}
	}
}

void reduceVectorB(std::vector<double>& b, int rowIndex, int startColumn, double firstValueInRow, double firstValueInA)
{
	double currentB = b[rowIndex];
	double firstValueInB = b[startColumn];
	double newB = b[rowIndex] - (firstValueInB * (firstValueInRow / firstValueInA));
	b[rowIndex] = newB;
}

int main()
{

	std::vector<std::vector<double>> a =
	{
		{  6, 2, 2,  4 }, // a[x][y], x - row, y - col
		{ -1, 2, 2, -3 },
		{  0, 1, 1, 4 },
		{  1, 0, 2, 3 }
	};

	//std::vector<std::vector<double>> a =
	//{
	//	{  1, 4,-3 }, // a[x][y], x - row, y - col
	//	{ -2, 8, 5 },
	//	{  3, 4, 7 }
	//};

	std::vector<double> b =
	{
		1, -1, 2, 1
	};

	std::vector<std::vector<double>> l =
	{
		{  1, 0, 0, 0 },
		{  0, 1, 0, 0 },
		{  0, 0, 1, 0 },
		{  0, 0, 0, 1 }
	};

	for (int startColumn = 0; startColumn < a.size() - 2; startColumn++)
	{
		double firstValueInA = a[startColumn][startColumn];

		for (int rowIndex = 1 + startColumn; rowIndex < a.size(); rowIndex++)
		{
			RowDetails rowDetails = reduceRow(a, rowIndex, startColumn);
			l[rowIndex][startColumn] = rowDetails.Coefficient;
			reduceVectorB(b, rowIndex, startColumn, rowDetails.FirstValue, firstValueInA);
		}
	}

	swapRowsIfNeeded(a, b);
	
	std::vector<double> y = std::vector<double>(b.size());
	std::vector<double> x = std::vector<double>(b.size());

	{
		double xn = pow(b[b.size() - 1], b.size() - 1) / pow(a[a.size() - 1][a.size() - 1], b.size() - 1);

		for (int i = (int)b.size() - 2; i >= 0; i--)
		{
			double sum = 0;
			for (int j = i + 1; j < a.size(); j++)
			{
				sum += pow(a[i][j], i - 1) * y[j];
			}
			y[i] = (pow(b[i], i - 1) - sum) / pow(a[i][i], i - 1);
		}
	}

	{
		double xn = pow(y[y.size() - 1], y.size() - 2) / pow(a[a.size() - 1][a.size() - 1], a.size() - 2);
		double previous = xn;

		for (int i = (int)y.size() - 2; i >= 0; i--)
		{
			double sum = 0;
			for (int j = i + 1; j < a.size(); j++)
			{
				sum += pow(a[i][j], i - 1) * y[j];
			}
			x[i] = (pow(y[i], i - 1) - sum) / pow(a[i][i], i - 1);
		}
	}

	printResult(a, b, l, x);

	std::cin.get();
}