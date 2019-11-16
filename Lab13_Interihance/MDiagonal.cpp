#include "MDiagonal.h"
#include <iostream>

MDiagonal::MDiagonal()
{
	//std::cout << "MDiagonal construct." << std::endl;
}

MDiagonal::~MDiagonal()
{
	//std::cout << "MDiagonal destruct." << std::endl;
}

MDiagonal::MDiagonal(int trows, int tcolumns, int* tmatr)
{
	rows = trows;
	columns = tcolumns;
	matr = new int[rows * columns];
	for (int i = 0; i < rows * columns; i++)
		matr[i] = tmatr[i];
}

void MDiagonal::diagonalMatrixInput()
{
	std::cout << "Number of rows: ";
	std::cin >> rows;
	std::cout << "Number of columns: ";
	std::cin >> columns;
	std::cout << "Elements of diagonal of Matrix: " << std::endl;
	matr = new int[rows * columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i == j)
			{
				std::cin >> matr[i * columns + j];
			}
			else
			{
				matr[i * columns + j] = 0;
			}
		}
	}
	std::cout << std::endl;
}
