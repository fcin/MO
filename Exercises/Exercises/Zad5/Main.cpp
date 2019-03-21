#include <iostream>
#include <vector>



void reduceRow(std::vector<std::vector<double>>& a, int rowIndex)
{
	int rowWidth = a[0].size();

	std::vector<double> currentRow = a[rowIndex];

	for (int colIndex = 0; colIndex < rowWidth; colIndex++)
	{
		double currentValue = currentRow[colIndex];
		double firstRowValueAbove = a[0][colIndex];
		double firstCurrentRowValue = currentRow[0];
		double firstValue = a[0][0];
		double result = currentValue - (firstRowValueAbove * (firstCurrentRowValue / firstValue));
		a[rowIndex][colIndex] = result;
	}

	for (int i = 0; i < rowWidth; i++)
		std::cout << a[rowIndex][i] << ", ";
}

int main()
{
	std::vector<std::vector<double>> a =
	{
						  // a[x][y], x - row, y - col
		{  6, 2, 2,  4 }, // a[0][0] == 6
		{ -1, 2, 2, -3 }, // a[1][0] == -1
		{  0, 1, 1,  4 },
		{  1, 0, 2,  3 }
	};

	for (int index = 1; index < a.size(); index++)
	{
		reduceRow(a, index);
		std::cout << std::endl;
	}


	std::cin.get();
}