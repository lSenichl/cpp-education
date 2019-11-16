#include "MVector.h"
#include <iostream>

MVector::MVector()
{
	//std::cout << "MVector construct." << std::endl;
}

MVector::~MVector()
{
	//std::cout << "MVector destruct." << std::endl;
}

MVector::MVector(int tcolumns, int* tmatr)
{
	rows = 1;
	columns = tcolumns;
	matr = new int[rows * columns];
	for (int i = 0; i < rows * columns; i++)
		matr[i] = tmatr[i];
}

void MVector::length()
{
	std::cout << "Length of vector: " << columns << std::endl;
}

int MVector::multipleVector(MVector tvector)
{
	int res1 = 0;

	if (columns == tvector.columns)
	{
		for (int i = 0; i < columns; i++)
		{
			res1 += matr[i] * tvector.getmatr()[i];
		}
	}
	else
	{
		std::cout << "Error" << std::endl;
		res1 = 0;
	}

	return res1;
}

void MVector::vectorInput()
{
	rows = 1;
	std::cout << "Number of elements: ";
	std::cin >> columns;
	std::cout << "Elements of vector: " << std::endl;
	matr = new int[rows * columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i * columns + j];
		}
	}
	std::cout << std::endl;
}

