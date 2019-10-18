#include <iostream>
#include "matrix.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	matrix matr1, matr2;

	matr1.input();
	matr2.input();
	matr1.print();
	matr2.print();
	
	matrix resmatr;
	resmatr.sum(matr1, matr2);
	resmatr.print();
	
 }