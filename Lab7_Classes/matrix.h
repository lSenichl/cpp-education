#pragma once
class matrix
{
private:
	
public:
	
	matrix();
	~matrix();

	matrix(int trows, int tcolumns, int * tmatr);

	void print();
	void input();

	matrix sum(matrix matrtemp1, matrix matrtemp2);

protected:
	int rows;
	int columns;
	int* matr;
};

