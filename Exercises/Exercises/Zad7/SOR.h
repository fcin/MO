#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

namespace SORMethods
{
	static double Error = 0.000000001;

	static double GetBiggestResiduum(const std::vector<std::vector<double>>& matrix,
		const std::vector<double>& x, const std::vector<double>& b)
	{
		double max = 0;
		for (int i = 0; i < matrix[0].size(); i++)
			max += matrix[0][i] * x[i];
		max -= abs(b[0]);

		for (int i = 1; i < matrix[0].size(); i++)
		{
			double current = 0;
			for (int c = 0; c < matrix[0].size(); c++)
				current += matrix[0][c] * x[c];

			if (current - abs(b[0]) > max)
				max = current;
		}

		return max;
	}

	static double GetBiggestDifference(const std::vector<double>& x, const std::vector<double>& x2)
	{
		double max = abs(x[0]) - abs(x2[0]);
		for (int i = 1; i < x.size(); i++)
		{
			if (abs(x[i]) - abs(x2[i]) > max)
				max = x[i];
		}

		return max;
	}

	static void SOR()
	{
		std::vector<std::vector<double>> matrix =
		{
			{ 100,	1,		-2,		3 },
			{ 4,	300,	-5,		6 },
			{ 7,	-8,		400,	9 },
			{ -10,	11,		-12,	200 }
		};

		std::vector<double> b = { 395, 603, -415, -606 };
		std::vector<double> x = { 1, 1, 1, 1 };
		double w = 2;

		std::vector<double> previousX = std::vector<double>(x.size());

		for (int iterations = 0; iterations < 100; iterations++)
		{
			for (int index = 0; index < matrix[0].size(); index++)
			{
				double ux = 0.0;
				for (int uIndex = 0; uIndex < matrix[0].size(); uIndex++)
				{
					if (uIndex != index)
					{
						ux += matrix[index][uIndex] * x[uIndex];
					}
				}

				previousX[index] = x[index];

				x[index] = (1.0 - (1 / w)) * x[index] + (( 1 / w) / matrix[index][index]) * (b[index] - ux);
			}

			for (int i = 0; i < x.size(); i++)
				std::cout << std::setprecision(8) << std::setw(14) << x[i];

			double difference = GetBiggestDifference(previousX, x);
			double residuum = GetBiggestResiduum(matrix, x, b);
			std::cout << " Estymator: " << std::setprecision(7) << std::setw(7) << difference;
			std::cout << ", Residuum: " << std::setprecision(7) << std::setw(7) << residuum;

			if (difference < Error || abs(residuum) < Error)
				return;

			std::cout << std::endl;
		}
	}
}
