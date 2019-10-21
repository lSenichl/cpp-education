#pragma once
class matrix
{
private:
	int rows;
	int columns;
	int* matr;

public:
	matrix();
	~matrix();

	matrix(int trows, int tcolumns, int * tmatr);

	void print();
	void input();

	const int getrows();
	const int getcolumns();
	const int * getmatr();

	matrix sum(matrix matrtemp1, matrix matrtemp2);

	matrix multiple(matrix matrtemp1, matrix matrtemp2);

	matrix multiple_on_number(matrix matrtemp1, matrix matrtemp2);
	
	void track(matrix matrtemp1, matrix matrtemp2);

protected:
	
};

