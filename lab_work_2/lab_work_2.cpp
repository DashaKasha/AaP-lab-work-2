#include "Matrix.h"

int main() {

	Matrix<> m1(4); // matrix with 4 rows and 1 columns
	Matrix<> m2(2, 4); // matrix with 4 rows and 6 columns
	Matrix<> m3 = { {2, 3.5, 9},{3.4, 1, 3},{0, 10.1, 1} };
	Matrix<> m4 = { {1, 0, 0},{0, 1, 0},{0, 0, 1} };
	Matrix<double> m5 = { {1, 2, 3}, {4, 5, 6} };
	Matrix<int> m6 = { {1, 2, 3, 4, 5, 6} };
	Matrix<int> m7 = { 1,2,3,4,5,6 };
	Matrix<int> m8 = { {1},{2},{3},{4},{5},{6} };

	cout << "enter matrix m1(4): \n";
	cin >> m1;
	cout << "enter matrix m2(2, 4): \n";
	cin >> m2;
	cout << "matrix m1:\n" << m1 << "matrix m2:\n" << m2 << "matrix m5:\n" << m5 << "matrix m6:\n" << m6 << "matrix m7:\n" << m7 << "matrix m8:\n" << m8;

	try {
		cout << "m2 * m1 =  \n"<< m2 * m1;
	}
	catch (const exception &e) {
			cerr << e.what() << '\n';
			}

	try {
		cout << "m3 + m4 =  \n" << m3 + m4;
	}
	catch (const exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		m3 += m5;
	}
	catch (const exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		m3 += m4;
	}
	catch (const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << "matrix m3 after m3+=m4: \n" << m3;


	try {
		m3 -= m4;
	}
	catch (const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << "matrix m3 after m3-=m4: \n" << m3;

	try {
		cout << m4(100, 5);
	}
	catch (const exception& e) {
		cerr << e.what() << '\n';
	}
	try {
		cout << "m4(2, 2): " << m4(2, 2) << endl;
		m4(2, 2) = 5;
		cout << "m4(2,2) after m4(2,2) = 5: " << m4(2, 2) << endl;
	}
	catch (const exception& e) {
		cerr << e.what() << '\n';
	}

	cout << "m4*5:\n" << m4 * 5 << endl;


	return 0;
}