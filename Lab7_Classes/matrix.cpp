#include "matrix.h"
#include <iostream>
#include <iostream>

matrix::matrix()
{
}

matrix::~matrix()
{
}

matrix::matrix(int trows, int tcolumns, int* tmatr)
{
	rows = trows;
	columns = tcolumns;
	matr = new int[rows * columns];
	for (int i = 0; i < rows * columns; i++)
		matr[i] = tmatr[i];
}

void matrix::print()
{
	std::cout << "Полученная матрица: " << std::endl;
	if (columns > rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cout << matr[i * columns + j] << " ";
			std::cout << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cout << matr[i * columns + j] << " ";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void matrix::input()
{
	std::cout << "Rows: " << std::endl;
	std::cin >> rows;
	std::cout << "Columns: " << std::endl;
	std::cin >> columns;
	std::cout << "Matrix: " << std::endl;
	matr = new int[rows * columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i * columns + j];
		}
	}
}

matrix matrix::sum(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.rows == matrtemp2.rows && matrtemp1.columns == matrtemp2.columns)
	{
		rows = matrtemp1.rows;
		columns = matrtemp1.columns;
		matr = new int[rows * columns];
		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp2.matr[i] + matrtemp1.matr[i];
		return matrix(rows,columns,matr);
	}
	else
	{
		std::cout << "Invalid." << std::endl;
	}
}

matrix matrix::multiple(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.columns == matrtemp2.rows)
	{
		rows = matrtemp1.rows;
		columns = matrtemp2.columns;

		std::cout << rows << " " << columns << std::endl;

		matr = new int[(rows) * (columns)];
		for (int i = 0; i < (rows) * (columns); i++)
			matr[i] = 0;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i * columns + j] = 0;
				for (int k = 0; k < matrtemp1.columns; k++)
				{
					matr[i * (columns) + j] += matrtemp1.matr[i * matrtemp1.columns + k] * matrtemp2.matr[k * columns + j];
				}
			}
		}

		return matrix(rows, columns, matr);
	}
	else
	{
		std::cout << "Invalid." << std::endl;
	}
}

matrix matrix::multiple_on_number(matrix matrtemp1, matrix matrtemp2)
{
	std::cout << "Введите число, на которое необходимо умножить матрицу: " << std::endl;
	int matrix_q;
	std::cin >> matrix_q;
	std::cout << "Введите номер матрицы, которую необходимо умножить на число: " << std::endl;
	int matrix_number;
	std::cin >> matrix_number;

	switch (matrix_number)
	{
	case 1:
		rows = matrtemp1.rows;
		columns = matrtemp1.columns;

		matr = new int[rows * columns];

		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp1.matr[i] * matrix_q;

		return matrix(rows, columns, matr);
		break;
	case 2:
		rows = matrtemp2.rows;
		columns = matrtemp2.columns;

		matr = new int[rows * columns];

		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp2.matr[i] * matrix_q;

		return matrix(rows, columns, matr);
		break;
	default:
		std::cout << "Введён неверный номер матрицы. Завершение программы." << std::endl;
	}
}
