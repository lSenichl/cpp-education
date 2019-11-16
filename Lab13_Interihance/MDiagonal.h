#pragma once
#include "Matrix.h"
class MDiagonal :
	public Matrix
{
public:
	MDiagonal();
	~MDiagonal();

	MDiagonal(int trows, int tcolumns, int* tmatr);
	void diagonalMatrixInput();
};

