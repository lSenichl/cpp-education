#include "matrix.h"
#include <iostream>
#include <iostream>

matrix::matrix()
{
}

matrix::~matrix()
{
}

const int matrix::getrows()
{
	return rows;
}

const int matrix::getcolumns()
{
	return columns;
}

const int* matrix::getmatr()
{
	return matr;
}

matrix::matrix(int trows, int tcolumns, int* tmatr)
{
	rows = trows;
	columns = tcolumns;
	matr = new int[rows * columns];
	for (int i = 0; i < rows * columns; i++)
		matr[i] = tmatr[i];
}

void matrix::input()
{
	std::cout << "Number of rows: ";
	std::cin >> rows;
	std::cout << "Number of columns: ";
	std::cin >> columns;
	std::cout << "Elements of matrix: " << std::endl;
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

void matrix::print()
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

matrix matrix::sum(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.getrows() == matrtemp2.getrows() && matrtemp1.getcolumns() == matrtemp2.getcolumns())
	{
		rows = matrtemp1.getrows();
		columns = matrtemp1.getcolumns();
		matr = new int[rows * columns];
		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp2.matr[i] + matrtemp1.matr[i];
		return matrix(rows,columns,matr);
	}
	else
	{
		std::cout << "Invalid size of matrixes." << std::endl;
		return matrix(0, 0, matr);
	}
}

matrix matrix::multiple(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.getcolumns() == matrtemp2.getrows())
	{
		rows = matrtemp1.getrows();
		columns = matrtemp2.getcolumns();

		matr = new int[(rows) * (columns)];
		for (int i = 0; i < (rows) * (columns); i++)
			matr[i] = 0;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i * columns + j] = 0;
				for (int k = 0; k < matrtemp1.getcolumns(); k++)
				{
					matr[i * (columns) + j] += matrtemp1.getmatr()[i * matrtemp1.getcolumns() + k] * matrtemp2.getmatr()[k * columns + j];
				}
			}
		}
		return matrix(rows, columns, matr);
	}
	else
	{
		std::cout << "Invalid size of matrixes." << std::endl;
		return matrix(0, 0, matr);
	}
}

matrix matrix::multiple_on_number(matrix matrtemp1, matrix matrtemp2)
{
	std::cout << "Multiplier: " << std::endl;
	int matrix_q;
	std::cin >> matrix_q;
	std::cout << "Number of matrix: " << std::endl;
	int matrix_number;
	std::cin >> matrix_number;

	switch (matrix_number)
	{
	case 1:
		rows = matrtemp1.getrows();
		columns = matrtemp1.getcolumns();

		matr = new int[rows * columns];

		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp1.getmatr()[i] * matrix_q;

		return matrix(rows, columns, matr);
		break;
	case 2:
		rows = matrtemp2.getrows();
		columns = matrtemp2.getcolumns();

		matr = new int[rows * columns];

		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp2.getmatr()[i] * matrix_q;

		return matrix(rows, columns, matr);
		break;
	default:
		std::cout << "Invalid number of matrix." << std::endl;
		return matrix(0, 0, matr);
	}
}

void matrix::track(matrix matrtemp1, matrix matrtemp2)
{
	std::cout << "Number of matrix: " << std::endl;
	int matrix_number;
	std::cin >> matrix_number;
	int track_result = 0;

	switch (matrix_number)
	{
	case 1:
		if (matrtemp1.getrows() == matrtemp1.getcolumns())
		{
			for (int i = 0; i < matrtemp1.getrows(); i++)
				track_result += matrtemp1.getmatr()[i * (matrtemp1.getcolumns()) + i];
			std::cout << "Track: " << track_result << std::endl;
		}
		else
		{
			std::cout << "Invalid size of matrix. " << std::endl;
		}
		break;
	case 2:
		if (matrtemp2.getrows() == matrtemp2.getcolumns())
		{
			for (int i = 0; i < matrtemp2.getrows(); i++)
				track_result += matrtemp2.getmatr()[i * (matrtemp2.getcolumns()) + i];
			std::cout << "Track: " << track_result << std::endl;
		}
		else
		{ 
			std::cout << "Invalid size of matrix. " << std::endl;
		}
		break;
	default:
		std::cout << "Invalid number of matrix." << std::endl;
	}
}