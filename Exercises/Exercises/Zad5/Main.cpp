#include <iostream>
#include <vector>

void printResult(std::vector<std::vector<double>>& a)
{
	for (int y = 0; y < a.size(); y++)
	{
		for (int z = 0; z < a.size(); z++)
		{
			std::cout << a[y][z] << ", ";
		}

		std::cout << std::endl;
	}
}

void reduceRow(std::vector<std::vector<double>>& a, int rowIndex, int iter)
{
	int rowWidth = (int)a[0].size();
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
		{  6, 2, 2,  4 }, // a[x][y], x - row, y - col
		{ -1, 2, 2, -3 },
		{  0, 1, 1, 4 },
		{  1, 0, 2, 3 }
	};

	std::vector<double> b =
	{
		1, -1, 2, 1
	};

	for (int startColumn = 0; startColumn < a.size() - 2; startColumn++)
	{
		for (int rowIndex = 1 + startColumn; rowIndex < a.size(); rowIndex++)
		{
			reduceRow(a, rowIndex, startColumn);

		}
	}

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
					// Pamietaj zeby jeszcze zamienic wektor b
					max = a[i][rowIndex];
					maxIndex = i;
				}
			}
			if (max != firstRowValue)
			{
				std::vector<double> tempA = a[maxIndex];
				a[maxIndex] = a[rowIndex];
				a[rowIndex] = tempA;

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

	int n = (int)b.size();
	double lastB = b[n - 1];
	double lastA = a[n - 1][n - 1];
	double xn = pow(lastB, n - 1) / pow(lastA, n - 1);

	printResult(a);

	std::cin.get();
}