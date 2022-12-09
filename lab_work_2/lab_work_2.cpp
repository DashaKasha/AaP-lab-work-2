#include "Matrix.h"

int main() {

	Matrix<int> m(2, 3);
	cin >> m;
	cout << "matrix m:\n" << m;
	Matrix <int> m1(4); // ������� ����: 4 ������ � 1 �������
	Matrix <int> m2(4, 6); // ������� ����: 4 ������ � 6 ��������
	Matrix <int> m3(m);  // copy constructor
	cout << "matrix m3 (copy constructor Matrix <int> m3(m)):\n" << m3;
	m2 = m;
	cout << "matrix m2 (operator = (m2 = m)):\n"<< m2;
	//Matrix <int> m5 = { {1, 2, 3}, {4, 5, 6} };
	//Matrix <int> m6 = { {1, 2, 3, 4, 5, 6} };
	//Matrix <int> m7 = { 1,2,3,4,5,6 };
	//Matrix <int> m8 = { {1},{2},{3},{4},{5},{6} };

	return 0;
}