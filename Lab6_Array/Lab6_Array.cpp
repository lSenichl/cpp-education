
#include <iostream>
#include <locale.h> 
#include <algorithm>

void matrix_input(int * &matrix_1, int * &matrix_2, int * columns_1, int * columns_2, int * rows_1, int * rows_2)
{
	std::cout << "Введите размеры матрицы №1: " << std::endl;
	std::cin >> *rows_1 >> *columns_1;
	std::cout << "Введите размеры матрицы №2: " << std::endl;
	std::cin >> *rows_2 >> *columns_2;

	matrix_1 = new int[(*rows_1) * (*columns_1)];
	matrix_2 = new int[(*rows_2) * (*columns_2)];

	std::cout << "Введите элементы матрицы №1: " << std::endl;
	for (int i = 0; i < (*rows_1) * (*columns_1); i++)
		std::cin >> matrix_1[i];

	std::cout << "Введите элементы матрицы №2: " << std::endl;
	for (int i = 0; i < (*rows_2) * (*columns_2); i++)
		std::cin >> matrix_2[i];
}

void matrix_output(int*& matrix, int rows, int columns)
{
	std::cout << "Полученная матрица: " << std::endl;
	if (columns > rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cout << matrix[i * columns + j] << " ";
			std::cout << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cout << matrix[i * columns + j] << " ";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void sum(int*& matrix_1, int*& matrix_2, int*& matrix_result, int * columns_1, int * columns_2, int * columns_result, int * rows_1, int * rows_2, int *rows_result)
{
	if (*rows_1 == *rows_2 && *columns_1 == *columns_2)
	{
		*rows_result = *rows_2;
		*columns_result = *columns_2;

		matrix_result = new int[(*rows_result) * (*columns_result)];

		for (int i = 0; i < (*rows_result) * (*columns_result); i++)
			matrix_result[i] = matrix_1[i] + matrix_2[i];

		matrix_output(matrix_result, *rows_result, *columns_result);

		delete[] matrix_result;
	}
	else
	{
		std::cout << "Матрицы имеют разную размерность. Операция не может быть выполнена. Завершение программы." << std::endl;
	}
}

void multiple(int*& matrix_1, int*& matrix_2, int*& matrix_result, int* columns_1, int* columns_2, int* columns_result, int* rows_1, int* rows_2, int* rows_result)
{
	if (*columns_1 == *rows_2)
	{
		*rows_result = *rows_1;
		*columns_result = *columns_2;
		
		matrix_result = new int[(*rows_result) * (*columns_result)];
		for (int i = 0; i < (*rows_result) * (*columns_result); i++)
			matrix_result[i] = 0;

		for (int i = 0; i < *rows_result; i++)
		{
			for (int j = 0; j < *columns_result; j++)
			{
				matrix_result[i * (*columns_result) + j] = 0;
				for (int k = 0; k < *columns_1; k++)
				{
					matrix_result[i * (*columns_result) + j] += matrix_1[i * (*columns_1) + k] * matrix_2[k * (*columns_2) + j];
				}
			}
		}

		matrix_output(matrix_result, *rows_result, *columns_result);

		delete[] matrix_result;
	}
	else
	{
		std::cout << "Матрицы имеют недопустимый для данного действия размер. Умножение матриц невозможно. Завершение программы." << std::endl;
	}
}

void multiple_on_number(int*& matrix_1, int*& matrix_2, int*& matrix_result, int* columns_1, int* columns_2, int* columns_result, int* rows_1, int* rows_2, int* rows_result)
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
		*rows_result = *rows_1;
		*columns_result = *columns_1;

		matrix_result = new int[(*rows_result) * (*columns_result)];

		for (int i = 0; i < (*rows_result) * (*columns_result); i++)
			matrix_result[i] = matrix_1[i] * matrix_q;

		matrix_output(matrix_result, *rows_result, *columns_result);

		delete[] matrix_result;
		break;
	case 2:
		*rows_result = *rows_2;
		*columns_result = *columns_2;

		matrix_result = new int[(*rows_result) * (*columns_result)];

		for (int i = 0; i < (*rows_result) * (*columns_result); i++)
			matrix_result[i] = matrix_2[i] * matrix_q;

		matrix_output(matrix_result, *rows_result, *columns_result);

		delete[] matrix_result;
		break;
	default:
		std::cout << "Введён неверный номер матрицы. Завершение программы." << std::endl;
	}
}

void determinant(int*& matrix_1, int*& matrix_2, int*& matrix_result, int* rows_1, int* rows_2, int* columns_1, int* columns_2)
{
	std::cout << "Введите номер матрицы, определитель которой необходимо найти: " << std::endl;
	int matrix_number;
	std::cin >> matrix_number;

	switch (matrix_number)
	{
	case 1:
		if (*rows_1 = *columns_1)
		{

		}
		else
		{
			std::cout << "Матрица имеет отличную от квадратной форму. Действие невозможно. Завершение прграммы. " << std::endl;
		}
		break;
	case 2:
		if (*rows_2 = *columns_2)
		{

		}
		else
		{
			std::cout << "Матрица имеет отличную от квадратной форму. Действие невозможно. Завершение прграммы. " << std::endl;
		}
		break;
	default:
		std::cout << "Введён неверный номер матрицы. Завершение программы." << std::endl;
	}
}

void track(int*& matrix_1, int*& matrix_2, int*& matrix_result, int* columns_1, int* columns_2, int* columns_result, int* rows_1, int* rows_2, int* rows_result)
{
	std::cout << "Введите номер матрицы, след которой необходимо найти: " << std::endl;
	int matrix_number;
	std::cin >> matrix_number;
	int track_result = 0;

	switch (matrix_number)
	{
	case 1:
		if (*rows_1 == *columns_1)
		{
			for (int i = 0; i < *rows_1; i++)
				track_result += matrix_1[i * (*columns_1) + i];
			std::cout << "След матрицы: " << track_result << std::endl;			
		}
		else
		{
			std::cout << "Матрица имеет отличную от квадратной форму. Завершение программы. " << std::endl;
		}
		break;
	case 2:
		if (*rows_2 == *columns_2)
		{
			for (int i = 0; i < *rows_2; i++)
				track_result += matrix_2[i*(*columns_2) + i];
			std::cout << "След матрицы: " << track_result << std::endl;
		}
		else
		{
			std::cout << "Матрица имеет отличную от квадратной форму. Нахождение следа невозможно. Завершение программы. " << std::endl;
		}
		break;
	default:
		std::cout << "Введён неверный номер матрицы. Завершение программы." << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int * matrix_1, * matrix_2, * matrix_result;
	int columns_1, columns_2, columns_result, rows_1, rows_2, rows_result;

	matrix_input(matrix_1, matrix_2, &columns_1, &columns_2, &rows_1, &rows_2);

	std::cout << "Введите номер необходимой операции: \n"
		<< "1. Сложение двух матриц. \n"
		<< "2. Ужножение двух матриц. \n"
		<< "3. Умножение одной матрицы на число. \n"
		<< "4. Нахождение обределителя. \n"
		<< "5. Нахождение следа. \n" << std::endl;

	int task_number = 0;

	std::cin >> task_number;

	std::cout << std::endl;

	switch (task_number)
	{
	case 1:
		sum(matrix_1, matrix_2, matrix_result, &columns_1, &columns_2, &columns_result, &rows_1, &rows_2, &rows_result);
		break;
	case 2:
		multiple(matrix_1, matrix_2, matrix_result, &columns_1, &columns_2, &columns_result, &rows_1, &rows_2, &rows_result);
		break;
	case 3:
		multiple_on_number(matrix_1, matrix_2, matrix_result, &columns_1, &columns_2, &columns_result, &rows_1, &rows_2, &rows_result);
		break;
	case 4:
		//determinant();
		break;
	case 5:
		track(matrix_1, matrix_2, matrix_result, &columns_1, &columns_2, &columns_result, &rows_1, &rows_2, &rows_result);
		break;
	}

	delete[] matrix_1;
	delete[] matrix_2;
}