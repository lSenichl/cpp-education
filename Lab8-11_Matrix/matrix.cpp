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

matrix operator+(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.getrows() == matrtemp2.getrows() && matrtemp1.getcolumns() == matrtemp2.getcolumns())
	{
		matrix result;
		result.rows = matrtemp1.getrows();
		result.columns = matrtemp1.getcolumns();
		result.matr = new int[result.rows * result.columns];
		for (int i = 0; i < result.rows * result.columns; i++)
			result.matr[i] = matrtemp2.matr[i] + matrtemp1.matr[i];
		return matrix(result.rows, result.columns, result.matr);
	}
	else
	{
		std::cout << "Invalid size of matrixes." << std::endl;
		int matr[1] = {0};
		return matrix(0, 0, matr);
	}
}

matrix operator-(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.getrows() == matrtemp2.getrows() && matrtemp1.getcolumns() == matrtemp2.getcolumns())
	{
		matrix result;
		result.rows = matrtemp1.getrows();
		result.columns = matrtemp1.getcolumns();
		result.matr = new int[result.rows * result.columns];
		for (int i = 0; i < result.rows * result.columns; i++)
			result.matr[i] = matrtemp1.matr[i] - matrtemp2.matr[i];
		return matrix(result.rows, result.columns, result.matr);
	}
	else
	{
		std::cout << "Invalid size of matrixes." << std::endl;
		int matr[1] = { 0 };
		return matrix(0, 0, matr);
	}
}

matrix operator--(matrix matrtemp)
{
	matrix result;
	result.rows = matrtemp.getrows();
	result.columns = matrtemp.getcolumns();
	result.matr = new int[result.rows * result.columns];
	for (int i = 0; i < matrtemp.getrows() * matrtemp.getcolumns(); i++)
		result.matr[i] = matrtemp.getmatr()[i] * (-1);

	return matrix(result.getrows(), result.getcolumns(), result.matr);

}

matrix operator*(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.getcolumns() == matrtemp2.getrows())
	{
		int rows = matrtemp1.getrows();
		int columns = matrtemp2.getcolumns();

		int *matr = new int[(rows) * (columns)];
		for (int i = 0; i < (rows) * (columns); i++)
			matr[i] = 0;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i * columns + j] = 0;
				for (int k = 0; k < matrtemp1.getcolumns(); k++)
				{
					matr[i * (columns)+j] += matrtemp1.getmatr()[i * matrtemp1.getcolumns() + k] * matrtemp2.getmatr()[k * columns + j];
				}
			}
		}
		return matrix(rows, columns, matr);
	}
	else
	{
		std::cout << "Invalid size of matrixes." << std::endl;
		int matr[1] = { 0 };
		return matrix(0, 0, matr);
	}
}

//std::iostream& operator<<(std::iostream& os, matrix matrtemp)
//{
//	if ((matrtemp.getcolumns != 0) && (matrtemp.getrows != 0))
//	{
//		for (int i = 0; i < matrtemp.getrows; i++)
//		{
//			for (int j = 0; j < matrtemp.getcolumns; j++)
//				std::cout << matrtemp.getmatr[i * matrtemp.getcolumns + j] << " ";
//			std::cout << std::endl;
//		}
//		std::cout << std::endl;
//	}
//}