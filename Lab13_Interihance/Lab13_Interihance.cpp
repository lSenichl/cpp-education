#include <iostream>
#include "Matrix.h"
#include "MDiagonal.h"
#include "MVector.h"

int main()
{
	std::cout << "Task: Vectors." << std::endl;
	MVector vec1, vec2;
	
	vec1.vectorInput();
	std::cout << "Vector 1: " << std::endl;
	vec1.print();
	vec1.length();

	vec2.vectorInput();
	std::cout << "Vector 2: " << std::endl;
	vec2.print();
	vec2.length();

	int result = vec1.multipleVector(vec2);
	std::cout << "Result of multiple: " << result << std::endl;

	std::cout << std::endl;
	std::cout << "Task: Diagonal matrixes." << std::endl;
	MDiagonal dMatr1;
	dMatr1.diagonalMatrixInput();
	std::cout << "Diagonal matrix: " << std::endl;
	dMatr1.print();

}