#include <iostream>
#include "matrix.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	matrix matr1, matr2;

	matr1.input();
	matr2.input();
	matr1.print();
	matr2.print();
	
	matrix resmatr;
	
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
		resmatr.sum(matr1, matr2);
		break;
	case 2:
		resmatr.multiple(matr1, matr2);
		break;
	case 3:
		resmatr.multiple_on_number(matr1, matr2);
		break;
	case 4:
		//resmatr.determinant;
		break;
	case 5:
		//resmatr.track;
		break;
	}

	resmatr.print();
 }