#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
private:
	int columns, rows; // размер матрицы
	T* data; // массив элементов

public:
	Matrix<T>(int r, int c = 1) 
	{
		rows = r;
		columns = c;
		data = new T[r * c];
	}

	Matrix<T>(const Matrix& matrix) // copy constructor
	{
		rows = matrix.rows;
		columns = matrix.columns;
		data = new T[rows * columns];
		for (int i = 0; i < rows*columns; i++)
		{
			data[i] = matrix.data[i];
		}
	}

	// Matrix<T>({data1}, {})
	// {
	// }

	Matrix<T> operator = (const Matrix<T> matrix) {		// пока только для одинаковых типов
		if (rows * columns < matrix.rows * matrix.columns) {
			data = new T[matrix.rows * matrix.columns];
		}
		rows = matrix.rows;
		columns = matrix.columns;
		for (int i = 0; i < rows * columns; i++)
		{
			data[i] = matrix.data[i];
		}
		return matrix;

	}

	friend istream& operator >>(istream& in, Matrix<T> &matrix)
	{
		for (int i = 0; i < matrix.rows; i++)
		{
			for (int j = 0; j < matrix.columns; j++)
			{
				in >> matrix.data[i * matrix.columns + j];
			}
		}
		return in;
	}

	friend ostream& operator <<(ostream& out, Matrix<T> matrix) 
	{
		for (int i = 0; i < matrix.rows; i++)
		{
			for (int j = 0; j < matrix.columns; j++)
			{
				out << matrix.data[i * matrix.columns + j]<<' ';
			}
			out << endl;
		}
		return out;
	}


	~Matrix()
	{
		delete[] data;
	}
};
