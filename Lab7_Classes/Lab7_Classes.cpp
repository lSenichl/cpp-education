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
	
	std::cout << "Number of operation: \n"
		<< "1. Sum. \n"
		<< "2. Multiple. \n"
		<< "3. Multiple on number. \n"
		<< "4. Determinant (dont work). \n"
		<< "5. Track. \n" << std::endl;

	int task_number = 0;

	std::cin >> task_number;

	std::cout << std::endl;

	switch (task_number)
	{
	case 1:
		resmatr.sum(matr1, matr2);
		resmatr.print();
		break;
	case 2:
		resmatr.multiple(matr1, matr2);
		resmatr.print();
		break;
	case 3:
		resmatr.multiple_on_number(matr1, matr2);
		resmatr.print();
		break;
	case 4:
		//resmatr.determinant;
		break;
	case 5:
		resmatr.track(matr1, matr2);
		break;
	}
 }