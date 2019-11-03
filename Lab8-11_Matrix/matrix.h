#pragma once
#include <iostream>

template <typename mytype>
class matrix
{
private:
	int rows;
	int columns;
	mytype* matr;

public:
	matrix() {}
	~matrix() {}
	
	matrix(int trows, int tcolumns, mytype* tmatr);
	/*
	void print();
	void input();

	int getrows();
	int getcolumns();
	mytype* getmatr();

	friend matrix operator+ (matrix matrtemp1, matrix matrtemp2);
	friend matrix operator- (matrix matrtemp1, matrix matrtemp2);
	friend matrix operator-- (matrix matrtemp);
	friend matrix operator* (matrix matrtemp1, matrix matrtemp2);
	friend matrix operator++ (matrix matrtemp); 
	friend std::ostream& operator << (std::ostream& out, matrix matrtemp);
	*/
protected:

};