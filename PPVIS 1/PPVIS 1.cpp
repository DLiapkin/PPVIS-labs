#include <iostream>
#include "Matrix.cpp"
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

void menu()
{
	/*!
	  \brief Функция, выводящая в консоль варианты действий с матрицей
	 */
	cout << "1: Create matrix" << endl;
	cout << "2: ++matrix" << endl;
	cout << "3: matrix++" << endl;
	cout << "4: --matrix" << endl;
	cout << "5: matrix--" << endl;
	cout << "6: Transpon" << endl;
	cout << "7: Define matrix type" << endl;
	cout << "8: SubMatrix" << endl;
	cout << "9: Matrix+n" << endl;
	cout << "10: Matrix-n" << endl;
	cout << "11: Submatrix extraction" << endl;
	cout << "12: Exit" << endl;
}

int main()
{
	srand((time(NULL)));

	int t;
	Matrix first(0, 0);
	while (true)
	{
		menu();

		cin >> t;
		system("cls");
		switch (t)
		{
		case 1:
			cout << "Do you want create matrix from the file? \n  1-Yes   2-No(by hand) " << endl;
			int quick;
			cin >> quick;
			if (quick == 1)
			{
				vector<string> path = { "matr.txt", "matr1.txt", "matr2.txt" };
				int option;
				cout << "Choose from 3 files: ";
				cin >> option;
				first.loadmatrix(path[option - 1]);
				print(first);
			}
			else
			{
				int cols, lines;
				cout << "Enter columns: " << endl;
				cin >> cols;
				cout << "Enter lines: " << endl;
				cin >> lines;
				system("cls");
				cout << "col= " << cols << " lines= " << lines << endl;
				first.createMatrix(cols, lines);
				print(first);
			}
			break;
		case 2:
			first.incPo();
			print(first);
			break;
		case 3:
			first.incPr();
			print(first);
			break;
		case 4:
			first.dicPre();
			print(first);
			break;
		case 5:
			first.dicPo();
			print(first);
			break;
		case 6:
			first.Transpon();
			print(first);
			break;
		case 7:
			cout << first.getMatrixType(first);
			break;
		case 8:
			int ncol, nlines;
			cin >> ncol;
			cin >> nlines;
			first.resize(ncol, nlines);
			break;
		case 9:
			int a;
			cin >> a;
			first.Matr_plus_n(a);
			print(first);
			break;
		case 10:
			int b;
			cin >> b;
			first.Matr_plus_n(-b);
			print(first);
			break;
		case 11:
			int l, c;
			cin >> l;
			cin >> c;
			first.Submatrix_extraction(l, c, first);
			break;
		case 12:
			return 0;
			break;
		case 13:
			print(first);
			break;
		}
	}
}