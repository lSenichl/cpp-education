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
	std::cout << "���������� �������: " << std::endl;
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
	std::cout << "������� ���-�� �����: " << std::endl;
	std::cin >> rows;
	std::cout << "������� ���-�� ��������: " << std::endl;
	std::cin >> columns;
	std::cout << "������� �������� �������: " << std::endl;
	matr = new int[rows * columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i * columns + j];
		}
	}
}

matrix matrix::sum(matrix matrtemp1)
{
	if (rows == matrtemp1.rows && columns == matrtemp1.columns)
	{
		matrix tmatr;
		tmatr.matr = new int[rows * matrtemp1.columns];
		for (int i = 0; i < rows * columns; i++)
			matr[i] = matr[i] + matrtemp1.matr[i];
		return matrix(rows,columns,matr);
	}
	else
	{
		std::cout << "������� ����� ������ �����������. �������� �� ����� ���� ���������. ���������� ���������." << std::endl;
	}
}

matrix matrix::sum2(matrix matrtemp1, matrix matrtemp2)
{
	if (matrtemp1.rows == matrtemp2.rows && matrtemp1.columns == matrtemp2.columns)
	{
		matr = new int[matrtemp1.rows * matrtemp1.columns];
		rows = matrtemp1.rows;
		columns = matrtemp1.columns;
		for (int i = 0; i < matrtemp1.rows * matrtemp1.columns; i++)
			matr[i] = matrtemp2.matr[i] + matrtemp1.matr[i];
		return matrix(rows,columns,matr);
	}
	else
	{
		std::cout << "������� ����� ������ �����������. �������� �� ����� ���� ���������. ���������� ���������." << std::endl;
	}
}