#pragma once
class matrix
{
private:
	
public:
	
	matrix();
	~matrix();

	matrix(int trows, int tcolumns, int * tmatr);

	int getrows();
	int getcolumns();
	int* getmatr();

	void print();
	void input();

	matrix sum(matrix matrtemp1);

	matrix sum2(matrix matrtemp1, matrix matrtemp2);

protected:
	int rows;
	int columns;
	int* matr;
};

