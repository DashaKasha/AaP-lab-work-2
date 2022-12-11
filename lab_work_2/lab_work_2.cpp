#include "Matrix.h"

int main() {

	Matrix<int> m(2, 3);

	cout << "enter matrix m: \n";
	cin >> m;
	cout << "matrix m:\n" << m;
	cout << "enter matrix summand: \n";
	Matrix<int> summand(2, 3);
	cin >> summand;
	cout << "matrix summand:\n" << summand;
	//Matrix <int> m1(4); // матрица вида: 4 строки и 1 столбец
	//Matrix <int> m2(4, 6); // матрица вида: 4 строки и 6 столбцов
	//Matrix <int> m3(m);  // copy constructor
	//cout << "matrix m3 (copy constructor Matrix <int> m3(m)):\n" << m3;
	//m2 = m;
	//cout << "matrix m2 (operator = (m2 = m)):\n"<< m2;
	//Matrix <int> m5 = { {1, 2, 3}, {4, 5, 6} };
	//Matrix <int> m6 = { {1, 2, 3, 4, 5, 6} };
	//Matrix <int> m7 = { 1,2,3,4,5,6 };
	//Matrix <int> m8 = { {1},{2},{3},{4},{5},{6} };
	// 
	// Перемещающий конструктор
	//Matrix <int> m4 = move(m2);

	//cout << "matrix m2 (move constructor):\n" << m2;
	//cout << "matrix m4 (move constructor):\n" << m4;

	//cout << "m4(0,2) = " << m4(0, 2) << endl;
	//Matrix<int> sum = m + summand;
	//cout << "matrix sum = m + summand:\n" << sum;


	//Matrix<int> minus = m1 - summand;
	//cout << "matrix minus = sum - summand:\n" << minus;
	//m4(0, 2) = 7;

	//Matrix<int> compose = m * summand;
	//cout << "compose = m * summand: \n" << compose << endl;

	m += summand;
	cout << "m += summand:\n" << m << endl;
	m -= summand;
	cout << "m -= summand:\n" << m << endl;
	m *= 4;
	cout << "m *= 4:\n" << m << endl;

	return 0;
}