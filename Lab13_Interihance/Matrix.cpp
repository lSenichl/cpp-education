#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	//std::cout << "Matrix construct." << std::endl;
}

Matrix::~Matrix()
{
	//std::cout << "Matrix destruct." << std::endl;
}

const int Matrix::getrows()
{
	return rows;
}

const int Matrix::getcolumns()
{
	return columns;
}

const int* Matrix::getmatr()
{
	return matr;
}

Matrix::Matrix(int trows, int tcolumns, int* tmatr)
{
	rows = trows;
	columns = tcolumns;
	matr = new int[rows * columns];
	for (int i = 0; i < rows * columns; i++)
		matr[i] = tmatr[i];
}

void Matrix::input()
{
	std::cout << "Number of rows: ";
	std::cin >> rows;
	std::cout << "Number of columns: ";
	std::cin >> columns;
	std::cout << "Elements of Matrix: " << std::endl;
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

void Matrix::print()
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

Matrix Matrix::sum(Matrix matrtemp1, Matrix matrtemp2)
{
	if (matrtemp1.getrows() == matrtemp2.getrows() && matrtemp1.getcolumns() == matrtemp2.getcolumns())
	{
		rows = matrtemp1.getrows();
		columns = matrtemp1.getcolumns();
		matr = new int[rows * columns];
		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp2.matr[i] + matrtemp1.matr[i];
		return Matrix(rows, columns, matr);
	}
	else
	{
		std::cout << "Invalid size of Matrixes." << std::endl;
		return Matrix(0, 0, matr);
	}
}

Matrix Matrix::multiple(Matrix matrtemp1, Matrix matrtemp2)
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
					matr[i * (columns)+j] += matrtemp1.getmatr()[i * matrtemp1.getcolumns() + k] * matrtemp2.getmatr()[k * columns + j];
				}
			}
		}
		return Matrix(rows, columns, matr);
	}
	else
	{
		std::cout << "Invalid size of Matrixes." << std::endl;
		return Matrix(0, 0, matr);
	}
}

Matrix Matrix::multiple_on_number(Matrix matrtemp1, Matrix matrtemp2)
{
	std::cout << "Multiplier: " << std::endl;
	int Matrix_q;
	std::cin >> Matrix_q;
	std::cout << "Number of Matrix: " << std::endl;
	int Matrix_number;
	std::cin >> Matrix_number;

	switch (Matrix_number)
	{
	case 1:
		rows = matrtemp1.getrows();
		columns = matrtemp1.getcolumns();

		matr = new int[rows * columns];

		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp1.getmatr()[i] * Matrix_q;

		return Matrix(rows, columns, matr);
		break;
	case 2:
		rows = matrtemp2.getrows();
		columns = matrtemp2.getcolumns();

		matr = new int[rows * columns];

		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp2.getmatr()[i] * Matrix_q;

		return Matrix(rows, columns, matr);
		break;
	default:
		std::cout << "Invalid number of Matrix." << std::endl;
		return Matrix(0, 0, matr);
	}
}

void Matrix::track(Matrix matrtemp1, Matrix matrtemp2)
{
	std::cout << "Number of Matrix: " << std::endl;
	int Matrix_number;
	std::cin >> Matrix_number;
	int track_result = 0;

	switch (Matrix_number)
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
			std::cout << "Invalid size of Matrix. " << std::endl;
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
			std::cout << "Invalid size of Matrix. " << std::endl;
		}
		break;
	default:
		std::cout << "Invalid number of Matrix." << std::endl;
	}
}