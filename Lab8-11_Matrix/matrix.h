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
	matrix() 
	{
	}
	
	~matrix() 
	{
	}
	
	matrix(int trows, int tcolumns, mytype* tmatr)
	{
		rows = trows;
		columns = tcolumns;
		matr = new mytype[rows * columns];
		for (int i = 0; i < rows * columns; i++)
			matr[i] = tmatr[i];
	}

	int getrows()
	{
		return rows;
	}

	int getcolumns()
	{
		return columns;
	}

	mytype* getmatr()
	{
		return matr;
	}

	void input()
	{
		std::cout << "Number of rows: ";
		std::cin >> rows;
		std::cout << "Number of columns: ";
		std::cin >> columns;
		std::cout << "Elements of matrix: " << std::endl;
		matr = new mytype[rows * columns];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cin >> matr[i * columns + j];
			}
		}
		std::cout << std::endl;
	}

	void print()
	{
		if ((columns != 0) && (rows != 0))
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
					std::cout << matr[i * columns + j] << " ";
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}

	friend matrix<mytype> operator+(matrix<mytype> matrtemp1, matrix<mytype> matrtemp2)
	{
		if (matrtemp1.getrows() == matrtemp2.getrows() && matrtemp1.getcolumns() == matrtemp2.getcolumns())
		{
			matrix<mytype> result;
			result.rows = matrtemp1.getrows();
			result.columns = matrtemp1.getcolumns();
			result.matr = new mytype[result.rows * result.columns];
			for (int i = 0; i < result.getrows() * result.getcolumns(); i++)
				result.matr[i] = matrtemp2.getmatr()[i] + matrtemp1.getmatr()[i];
			return matrix<mytype>(result.getrows(), result.getcolumns(), result.matr);
		}
		else
		{
			std::cout << "Invalid size of matrixes." << std::endl;
			int matr[1] = { 0 };
			return matrix<mytype>(0, 0, matr);
		}
	}

	friend matrix<mytype> operator-(matrix<mytype> matrtemp1, matrix<mytype> matrtemp2)
	{
		if (matrtemp1.getrows() == matrtemp2.getrows() && matrtemp1.getcolumns() == matrtemp2.getcolumns())
		{
			matrix<mytype> result;
			result.rows = matrtemp1.getrows();
			result.columns = matrtemp1.getcolumns();
			result.matr = new mytype[result.rows * result.columns];
			for (int i = 0; i < result.rows * result.columns; i++)
				result.matr[i] = matrtemp1.matr[i] - matrtemp2.matr[i];
			return matrix<mytype>(result.rows, result.columns, result.matr);
		}
		else
		{
			std::cout << "Invalid size of matrixes." << std::endl;
			int matr[1] = { 0 };
			return matrix<mytype>(0, 0, matr);
		}
	}

	friend matrix<mytype> operator--(matrix<mytype> matrtemp)
	{
		matrix<mytype> result;
		result.rows = matrtemp.getrows();
		result.columns = matrtemp.getcolumns();
		result.matr = new mytype[result.rows * result.columns];
		for (int i = 0; i < matrtemp.getrows() * matrtemp.getcolumns(); i++)
			result.matr[i] = matrtemp.getmatr()[i] * (-1);

		return matrix<mytype>(result.getrows(), result.getcolumns(), result.matr);

	}

	friend matrix<mytype> operator*(matrix<mytype> matrtemp1, matrix<mytype> matrtemp2)
	{
		if (matrtemp1.getcolumns() == matrtemp2.getrows())
		{
			int rows = matrtemp1.getrows();
			int columns = matrtemp2.getcolumns();

			int* matr = new mytype[(rows) * (columns)];
			for (int i = 0; i < (rows) * (columns); i++)
				matr[i] = 0;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					matr[i * columns + j] = 0;
					for (int k = 0; k < matrtemp1.getcolumns(); k++)
					{
						matr[i * (columns)+j] += matrtemp1.getmatr()[i * matrtemp1.getcolumns() + k] * matrtemp2.getmatr()[k * columns + j];
					}
				}
			}
			return matrix<mytype>(rows, columns, matr);
		}
		else
		{
			std::cout << "Invalid size of matrixes." << std::endl;
			int matr[1] = { 0 };
			return matrix<mytype>(0, 0, matr);
		}
	}

	friend matrix<mytype> operator++(matrix<mytype> matrtemp)
	{
		std::cout << "Multiplier: " << std::endl;
		int matrix_q;
		std::cin >> matrix_q;

		int rows = matrtemp.getrows();
		int columns = matrtemp.getcolumns();

		mytype* matr = new mytype[rows * columns];

		for (int i = 0; i < rows * columns; i++)
			matr[i] = matrtemp.getmatr()[i] * matrix_q;

		return matrix<mytype>(rows, columns, matr);
	}

	friend std::ostream& operator<<(std::ostream& out, matrix<mytype> matrtemp)
	{
		if ((matrtemp.columns != 0) && (matrtemp.getrows() != 0))
		{
			for (int i = 0; i < matrtemp.getrows(); i++)
			{
				for (int j = 0; j < matrtemp.columns; j++)
					out << matrtemp.matr[i * matrtemp.columns + j] << " ";
				out << std::endl;
			}
			out << std::endl;
		}
		return out;
	}
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