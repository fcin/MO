#include <iostream>
#include <vector>



void reduceRow(std::vector<std::vector<double>>& a, int rowIndex, int iter)
{
	int rowWidth = a[0].size();
	int start = iter;

	std::vector<double> currentRow = a[rowIndex];

	for (int colIndex = start; colIndex < rowWidth; colIndex++)
	{
		double currentValue = currentRow[colIndex];
		double firstRowValueAbove = a[start][colIndex];
		double firstCurrentRowValue = currentRow[start];
		double firstValue = a[start][start];
		double result = currentValue - (firstRowValueAbove * (firstCurrentRowValue / firstValue));
		a[rowIndex][colIndex] = result;
	}
}

int main()
{

	std::vector<std::vector<double>> a =
	{
		{  1, 2, 5 }, // a[x][y], x - row, y - col
		{  3, 4, 6 },
		{  7, 8, 9 }
	};


	for (int iter = 0; iter < a.size() - 1; iter++)
	{
		for (int index = 1 + iter; index < a.size(); index++)
		{
			reduceRow(a, index, iter);
		}
	}

	for (int y = 0; y < a.size(); y++)
	{
		for (int z = 0; z < a.size(); z++)
		{
			std::cout << a[y][z] << ", ";
		}

		std::cout << std::endl;
	}


	std::cin.get();
}