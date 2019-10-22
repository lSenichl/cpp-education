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

	matrix(int trows, int tcolumns, int* tmatr);

	void print();
	void input();

	const int getrows();
	const int getcolumns();
	const int* getmatr();

	friend matrix operator+ (matrix matrtemp1, matrix matrtemp2);
	friend matrix operator- (matrix matrtemp1, matrix matrtemp2);
	friend matrix operator-- (matrix matrtemp);
	friend matrix operator* (matrix matrtemp1, matrix matrtemp2);
	//friend matrix operator** (matrix matrtemp1, int k;
	//friend matrix operator= (matrix matrtemp1, matrix matrtemp2);
	//friend std::iostream & operator << (std::iostream& os, matrix matrtemp);
protected:

};

