#pragma once
#include <iostream>
using namespace std;

template <typename T>//, typename T2>
class Matrix
{
private:
	int cols, rows; // размер матрицы
	T* data; // массив элементов

public:
	Matrix<T>(int r, int c = 1) 
	{
		rows = r;
		cols = c;
		data = new T[r * c];
	}

	Matrix<T>(const Matrix& matrix) // copy constructor
	{
		rows = matrix.rows;
		cols = matrix.cols;
		data = new T[rows * cols];
		for (int i = 0; i < rows*cols; i++)
		{
			data[i] = matrix.data[i];
		}
	}


	Matrix<T>(Matrix&& other) // move constructor
	{
		rows = other.rows;
		cols = other.cols;
		data = other.data;
		other.data = nullptr;
		other.rows = other.cols = 0;
	}

	// Matrix<T>({data1}, {})
	// {
	// }

	Matrix<T> operator = (const Matrix<T> matrix) {		// пока только для одинаковых типов
		if (rows * cols < matrix.rows * matrix.cols) {
			data = new T[matrix.rows * matrix.cols];
		}
		rows = matrix.rows;
		cols = matrix.cols;
		for (int i = 0; i < rows * cols; i++)
		{
			data[i] = matrix.data[i];
		}
		return matrix;

	}

	friend istream& operator >>(istream& in, Matrix<T> &matrix)
	{
		for (int i = 0; i < matrix.rows; i++)
		{
			for (int j = 0; j < matrix.cols; j++)
			{
				in >> matrix.data[i * matrix.cols + j];
			}
		}
		return in;
	}

	friend ostream& operator <<(ostream& out, Matrix<T> matrix) 
	{
		for (int i = 0; i < matrix.rows; i++)
		{
			for (int j = 0; j < matrix.cols; j++)
			{
				out << matrix.data[i * matrix.cols + j]<<' ';
			}
			out << endl;
		}
		return out;
	}

	T operator () (int r, int c) { // не сделано для m(0,2) = 5
		return data[r * cols + c];
	}


	Matrix<T> operator + ( const Matrix<T> summand)  // сложение матриц
	{
		if (rows != summand.rows || cols != summand.cols)
		{
			cout << "the sizes of the matrices do not match\n";
			return Matrix<T> (0,0);
		}
		Matrix <T> summ(rows, cols); 
		for (int i = 0; i < rows*cols; i++)
		{
			summ.data[i] = data[i] + summand.data[i];
		}
		return summ;
	}

	Matrix<T> operator - (const Matrix<T> a) // вычитание матриц 
	{
		if (rows != a.rows || cols != a.cols)
		{
			cout << "the sizes of the matrices do not match\n";
			return Matrix<T>(0, 0);
		}
		Matrix <T> minus(rows, cols);
		for (int i = 0; i < rows * cols; i++)
		{
			minus.data[i] = data[i] - a.data[i];
		}
		return minus;
	}

	Matrix<T> operator *(const T n)   // умножение на число
	{
		Matrix <T> m(rows, cols);
		for (int i = 0; i < rows * cols; i++)
		{
			m.data[i] = data[i] * n;
		}
		return m;
	}

	Matrix <T> operator * (const Matrix<T> b)   // умножение матриц
	{
		if (cols != b.rows) {
		cout << "incorrect sizes of the matrices \n";
		return Matrix<T>(0, 0);
		}
		Matrix<T> c(rows, b.cols); // матрица произведения
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < b.cols; j++)
			{
				c.data[i * b.cols + j] = 0;
				for (int k = 0; k < cols; k++)
				{
					c.data[i * b.cols + j] += data[i * cols + k] * b.data[k * b.cols + j];
				}
			}
		}
		return c;
	}

	Matrix <T> operator += (const Matrix<T> summand)
	{
		if (rows != summand.rows || cols != summand.cols)
		{
			cout << "the sizes of the matrices do not match\n";
			return Matrix<T>(0, 0);
		}
		
		for (int i = 0; i < rows * cols; i++)
		{
			data[i] += summand.data[i];
		}

		return *this;
	}

	Matrix <T> operator -= (const Matrix<T> a)
	{
		if (rows != a.rows || cols != a.cols)
		{
			cout << "the sizes of the matrices do not match\n";
			return Matrix<T>(0, 0);
		}
		for (int i = 0; i < rows * cols; i++)
		{
			data[i] -= a.data[i];
		}
		return *this;
	}

	Matrix <T> operator *= (const T n)
	{
		for (int i = 0; i < rows * cols; i++)
		{
			data[i] = data[i] * n;
		}
		return *this;
	}
	 
	~Matrix()
	{
		delete[] data;
	}
};
