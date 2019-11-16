#pragma once
class Matrix
{
private:

public:
	Matrix();
	~Matrix();

	Matrix(int trows, int tcolumns, int* tmatr);

	void print();
	void input();

	const int getrows();
	const int getcolumns();
	const int* getmatr();

	Matrix sum(Matrix matrtemp1, Matrix matrtemp2);

	Matrix multiple(Matrix matrtemp1, Matrix matrtemp2);

	Matrix multiple_on_number(Matrix matrtemp1, Matrix matrtemp2);

	void track(Matrix matrtemp1, Matrix matrtemp2);

protected:
	int rows;
	int columns;
	int* matr;

};

