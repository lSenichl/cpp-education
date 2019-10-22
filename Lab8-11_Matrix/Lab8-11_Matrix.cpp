#include <iostream>
#include "matrix.h"

int main()
{
	matrix matr1, matr2;

	matr1.input();
	matr2.input();

	std::cout << "Entered matrix 1: " << std::endl;
	matr1.print();
	std::cout << "Entered matrix 2: " << std::endl;
	matr2.print();

	matrix resmatr;

	std::cout << "matr1 + matr2 = " << std::endl;
	resmatr = matr1 + matr2;
	resmatr.print();
	std::cout << std::endl;

	std::cout << "--matr1 =  " << std::endl;
	resmatr=--matr1;
	resmatr.print();
	std::cout << std::endl;

	std::cout << "--matr2 =  " << std::endl;
	resmatr = --matr2;
	resmatr.print();
	std::cout << std::endl;

	std::cout << "matr1 - matr2 = " << std::endl;
	resmatr = matr1 - matr2;
	resmatr.print();
	std::cout << std::endl;

	std::cout << "matr1 * matr2 = " << std::endl;
	resmatr = matr1 * matr2;
	resmatr.print();
	std::cout << std::endl;

	//matr1<<matr1;
}