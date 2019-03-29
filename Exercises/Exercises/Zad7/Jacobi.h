#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

namespace JacobiMethods
{
	static double Error = 0.000001;

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

	static void Jacobi()
	{
		std::cout.precision(12);

		std::vector<std::vector<double>> matrix =
		{
			{ 100,	1,		-2,		3 },
			{ 4,	300,	-5,		6 },
			{ 7,	-8,		400,	9 },
			{ -10,	11,		-12,	200 }
		};

		std::vector<double> b = { 395, 603, -415, -606 };
		std::vector<double> x = { 1, 1, 1, 1 };

		for (int iterations = 0; iterations < 15; iterations++)
		{
			std::cout << "Iteracja: " << std::setw(3) << iterations;

			std::vector<double> newX = std::vector<double>(x.size());

			for (int index = 0; index < x.size(); index++)
			{
				double d = 1.0 / matrix[index][index];
				double lu = 0;

				for (int luIndex = 0; luIndex < x.size(); luIndex++)
				{
					if (index != luIndex)
						lu += matrix[index][luIndex] * x[luIndex];
				}

				double m = -d * lu;
				double c = d * b[index];
				newX[index] = m + c;
				std::cout << std::setprecision(8) << std::setw(12) << x[index] << ", ";
			}

			double difference = GetBiggestDifference(x, newX);
			double residuum = GetBiggestResiduum(matrix, x, b);
			std::cout << "Estymator: " << std::setprecision(7) << std::setw(7) << difference;
			std::cout << ", Residuum: " << std::setprecision(7) << std::setw(7) << residuum;

			if (difference < Error || abs(residuum) < Error)
				return;

			x = newX;
			std::cout << std::endl;
		}
	}
}
