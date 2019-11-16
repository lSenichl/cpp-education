#pragma once
#include "matrix.h"

template <typename mytype>
matrix<mytype>::matrix()
{
}

template <typename mytype>
matrix<mytype>::~matrix()
{
}

template <typename mytype>
matrix<mytype>::matrix(int trows, int tcolumns, mytype* tmatr)
{
	rows = trows;
	columns = tcolumns;
	matr = new mytype[rows * columns];
	for (int i = 0; i < rows * columns; i++)
		matr[i] = tmatr[i];
}

template <typename mytype>
int matrix<mytype>::getrows()
{
	return rows;
}

template <typename mytype>
int matrix<mytype>::getcolumns()
{
	return columns;
}

template <typename mytype>
mytype* matrix<mytype>::getmatr()
{
	return matr;
}

template <typename mytype>
void matrix<mytype>::input()
{
	std::cout << "Number of rows: ";
	std::cin >> rows;
	std::cout << "Number of columns: ";
	std::cin >> columns;
	std::cout << "Elements of matrix: " << std::endl;
	matr = new mytype[rows * columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i * columns + j];
		}
	}
	std::cout << std::endl;
}

template <typename mytype>
void matrix<mytype>::print()
{
	if ((columns != 0) && (rows != 0))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cout << matr[i * columns + j] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}