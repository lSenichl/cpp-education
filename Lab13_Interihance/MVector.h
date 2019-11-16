#pragma once
#include "Matrix.h"
class MVector :
	public Matrix
{
public:
	MVector();
	~MVector();

	MVector(int tcolumns, int* tmatr);

	void length();
	int multipleVector(MVector tvector);
	void vectorInput();
};

