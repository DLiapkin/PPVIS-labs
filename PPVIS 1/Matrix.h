#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

class Matrix
{
  /*!
  \brief Класс Матрица, содержащий методы пре(пост)де(ин)кремента, сложение матрицы и числа, транспонирования, изменения размера матрицы и нахождения типа матрицы
  */

	int columns;
	int lines;
	int** arr = new int* [lines];

	bool identityType(const Matrix& matrix, bool diagonal);
	bool nullType(const Matrix& matrix);
	bool symmetricType(const Matrix& matrix, bool square);
	bool upTriangleType(const Matrix& matrix, bool square);
	bool downTriangleType(const Matrix& matrix, bool square);
	bool squareType(const Matrix& matrix);
	bool diagonalType(const Matrix& matrix, bool square);

public:
	Matrix(int lines_p, int columns_p);
	Matrix();
	~Matrix();

	int getLines();

	int getColumns();

	friend void print(Matrix& mat);

	string getMatrixType(const Matrix& matrix);

	void createMatrix(int columns, int lines);

	void Submatrix_extraction(int line, int col, Matrix mat);

	void incPo();

	void Matr_plus_n(int n);

	void incPr();

	void dicPo();

	void dicPre();

	void resize(int ncol, int nlines);

	void loadmatrix(string path);

	void Transpon();

};
#endif