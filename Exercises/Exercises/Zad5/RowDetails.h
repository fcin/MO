#pragma once

struct RowDetails
{
	double FirstValue;
	double Coefficient;

	RowDetails(double firstValue, double coefficient) 
		: FirstValue(firstValue), Coefficient(coefficient) {}
};
