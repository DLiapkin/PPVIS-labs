#include "Matrix.h"

using namespace std;

    Matrix::Matrix(int lines_p, int columns_p)
	{	/*!
		����������� ��������� ���������� ����� � �������� �������
		\param lines_p ���������� ����� � ���������� �������
		\param columns_p ���������� �������� � ����������� �������
		*/
		this->columns = columns_p;
		this->lines = lines_p;
	}

	Matrix::Matrix()
	{/*!
	 \brief ����������� �� ���������, ������� ������������� ��������� ��������� �������. �� ��������� ����������
	 */
		this->columns = 0;
		this->lines = 0;
	}

	Matrix::~Matrix()
	{/*!
		���������� ����������� ������, ���������� ��� �������. �� ��������� ����������
	 */
		for (int i = 0; i < lines; i++)
			delete[] arr[i];
	}

	int Matrix::getLines()
	{
		/*!
			������ ��� ��������� ���������� ����� ������ �������. �� ��������� ����������
			\return ���������� ����� ������ �������
		*/
		return this->lines;
	}

	int Matrix::getColumns()
	{
		/*!
			������ ��� ��������� �������� ������ �������. �� ��������� ����������
			\return ���������� �������� ������ �������
		*/
		return this->columns;
	}

	bool Matrix::identityType(const Matrix& matrix, bool diagonal)
	{
		/*!
		  \brief ������������� ������� ����������, �������� �� ������� ���������, ���� ��������� ������ � ������������ �������
		  \details ������� ���������� ���������, ���� ��� ������������ � ��� � �������� �� ������� ��������� ����� �������
		  \param matrix �������, ������������ ������� ����������
		  \param diagonal ������ ��������, ������������ �� �������
		  \return ������ �������� true, ���� ������� ��������� � false � ���� ������
		 */
		if (diagonal)
		{
			int ones = 0;
			int k = 0;
			for (int i = 0; i < matrix.lines; i++)
			{
				if (matrix.arr[i][k] == 1)
				{
					ones++;
				}
				k++;
			}

			if (ones == matrix.columns)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	bool Matrix::nullType(const Matrix& matrix)
	{
		/*!
		  \brief ������������� ������� ����������, �������� �� ������� �������, ���� ��������� ���������� ����� � �������
		  \details ������� ���������� �������, ���� ��� � ����� ����
		  \param matrix �������, ������������ ������� ����������
		  \return ������ �������� true, ���� ������� ������� � false � ���� ������
		 */
		for (int i = 0; i < matrix.lines; i++)
		{
			for (int k = 0; k < matrix.columns; k++)
			{
				if (matrix.arr[i][k] != 0)
				{
					return false;
				}
			}
		}

		return true;
	}

	bool Matrix::symmetricType(const Matrix& matrix, bool square)
	{
		/*!
		  \brief ������������� ������� ����������, �������� �� ������� ������������, ���� ��������� ��������� � ��������� ���������
		  \details ������� ���������� ������������, ���� ����������������� ������� ����� ��������
		  \param matrix �������, ������������ ������� ����������
		  \param square ������ ��������, �������� �� ������� ����������
		  \return ������ �������� true, ���� ������� ������������ � false � ���� ������
		 */
		if (square)
		{
			for (int i = 0; i < matrix.lines; i++)
			{
				for (int j = 0; j < matrix.columns; j++)
				{
					if (i == j)
					{
						continue;
					}

					if (matrix.arr[j][i] != matrix.arr[i][j])
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	bool Matrix::upTriangleType(const Matrix& matrix, bool square)
	{
		/*!
		  \brief ������������� ������� ����������, �������� �� ������� ������� �����������, ���� ��������� ��������� ���� ������ ��������� � ����
		  \details ������� ���������� ������� �����������, ���� � �������� ���� ������� ��������� ����� ����
		  \param matrix �������, ������������ ������� ����������
		  \param square ������ ��������, �������� �� ������� ����������
		  \return ������ �������� true, ���� ������� ������� ����������� � false � ���� ������
		 */
		if (square)
		{
			for (int i = 0; i < matrix.lines; i++)
			{
				for (int j = 0; j < matrix.columns; j++)
				{
					if (i > j && matrix.arr[i][j] != 0)
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	bool Matrix::downTriangleType(const Matrix& matrix, bool square)
	{
		/*!
		  \brief ������������� ������� ����������, �������� �� ������� ������ �����������, ���� ��������� ��������� ���� ������ ��������� � ����
		  \details ������� ���������� ������� �����������, ���� � �������� ���� ������� ��������� ����� ����
		  \param matrix �������, ������������ ������� ����������
		  \param square ������ ��������, �������� �� ������� ����������
		  \return ������ �������� true, ���� ������� ������ ����������� � false � ���� ������
		 */
		if (square)
		{
			for (int i = 0; i < matrix.lines; i++)
			{
				for (int j = 0; j < matrix.columns; j++)
				{
					if (i < j && matrix.arr[i][j] != 0)
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	bool Matrix::squareType(const Matrix& matrix)
	{
		/*!
			\brief ������������� ������� ����������, �������� �� ������� ����������, ���� ��������� ���������� ����� � ��������
			\param matrix �������, ������������ ������� ����������
			\return ������ �������� true, ���� ������� ���������� � false � ���� ������
		 */
		if (matrix.columns == matrix.lines)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Matrix::diagonalType(const Matrix& matrix, bool square)
	{
		/*!
			\brief ������������� ������� ����������, �������� �� ������� ������������, ���� ��������� ���������� ����� � �������
			\details ������� ���������� ������������, ���� ��� ���������� � ��� � ��������, ����� ������� ���������, ����� ����
			\param matrix �������, ������������ ������� ����������
			\param square ������ ��������, �������� �� ������� ����������
			\return ������ �������� true, ���� ������� ������������ � false � ���� ������
		 */
		if (!square)
		{
			return false;
		}
		else
		{
			int zeros = 0;
			for (int i = 0; i < matrix.lines; i++)
			{
				for (int k = 0; k < matrix.columns; k++)
				{
					if (i == k)
					{
						continue;
					}

					if (matrix.arr[i][k] == 0)
					{
						zeros++;
					}
				}
			}

			if (zeros == matrix.lines * matrix.columns - matrix.columns)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	void print(Matrix& mat)
	{
		/*!
		������������� �������, ��������� ������� � �������
		*/
		for (int i = 0; i < mat.lines; i++)
		{
			for (int j = 0; j < mat.columns; j++)
			{
				cout << mat.arr[i][j] << "\t";
			}
			cout << endl;
		}
		return;
	}

	void Matrix::Submatrix_extraction(int line, int col, Matrix mat)
	{
		/*!
		\details ����� ������� ���������� ���� "���������" ������. �������� � ������� �����������, ���� ��� ������������ ����� �������� ��������
		\brief ��������� ���������� �������� ��������
		\param line ����� ����� ����� �������
		\param col ����� �������� ����� �������
		*/
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << mat.arr[i][j] << "\t";
			}
			cout << endl;
		}
	}

	string Matrix::getMatrixType(const Matrix& matrix)
	{
		/*!
		  \brief ���������� ��� �������
		  \details ��������� ����: ����������, ������������, ���������, �������, ������� �����������, ������ �����������, ������������ ���� �� ���� �� �������������
		  \param matrix �������, ������������ ������� ������������
		  \return ������, ������� �������� ���������� � ���� ��������� �������
		*/
		string result = "";
		bool square = squareType(matrix);
		bool diagonal = diagonalType(matrix, square);
		bool identity = identityType(matrix, diagonal);
		bool nullM = nullType(matrix);
		bool symmetricM = symmetricType(matrix, square);
		bool upTriangle = upTriangleType(matrix, square);
		bool downTriangle = downTriangleType(matrix, square);

		if (downTriangle && !nullM)
		{
			result += "Down Triangle ";
		}
		else if (upTriangle && !nullM)
		{
			result += "UpperTriangle ";
		}

		if (symmetricM && !diagonal)
		{
			result += "Symmetric ";
		}

		if (identity)
		{
			result += "Identity ";
		}

		if (nullM)
		{
			result = "Null ";
		}

		if (diagonal && !nullM && !identity)
		{
			result += "Diagonal ";
		}

		if (square && !diagonal && !identity && !symmetricM && !downTriangle && !upTriangle)
		{
			result += "Square ";
		}

		if (result == "")
		{
			result = "None";
		}

		return "Matrix type is " + result + "\n";
	}

	void Matrix::createMatrix(int columns, int lines)
	{/*!
		��������� ������� ���������� ������� � ��������� �� -10 �� 10
		\param lines ���������� ����� � ���������� �������
		\param columns ���������� �������� � ����������� �������
	 */
		this->columns = columns;
		this->lines = lines;
		for (int i = 0; i < lines; i++)
		{
			arr[i] = new int[columns];
			for (int j = 0; j < columns; j++)
			{
				arr[i][j] = rand() % 20 - 10;
			}
		}
	}

	void Matrix::incPo()
	{
		/*!
		����������� ��������� ����������� ������ ������� ������� �� �������
		*/
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				++arr[i][j];
			}

		}
	}

	void Matrix::Matr_plus_n(int n)
	{
		/*!
		�����������/��������� ����� � �������
		/param n ����� ������� ����������/��������
		*/
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < columns; j++)
				arr[i][j] += n;
	}

	void Matrix::incPr()
	{
		/*!
		���������� ��������� ����������� ������ ������� ������� �� �������
		*/
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[i][j]++;
			}

		}
	}

	void Matrix::dicPo()
	{
		/*!
		����������� ��������� ��������� ������ ������� ������� �� �������
		*/
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				arr[i][j]--;
			}

		}
	}

	void Matrix::dicPre()
	{
		/*!
		���������� ��������� ��������� ������ ������� ������� �� �������
		*/
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				--arr[i][j];
			}

		}
	}

	void Matrix::resize(int ncol, int nlines)
	{
		/*!
		��������� ���������� ����� �������
		\param nlines ����� ����� � ����� �������
		\param ncol ����� �������� � ����� �������
		\details � ���� ���������� ������ �������� ����� �������, �������� � ���������� �������� �� ���������� ������� �������� ���� ��. � �������������� ������, ���� ������� ����� �����, ������������� ����� ����� ����������� �������, ���������� ��������� �����.
		*/
		int** arrn = new int* [nlines];
		for (int i = 0; i < nlines; i++)
			arrn[i] = new int[ncol];

		if (ncol < columns || nlines < lines)
		{
			for (int i = 0; i < nlines; i++)
			{
				for (int j = 0; j < ncol; j++)
				{
					arrn[i][j] = arr[i][j];
				}
			}

		}
		else
		{
			for (int i = 0; i < nlines; i++)
			{
				if (i < lines)
				{
					for (int j = 0; j < ncol; j++)
					{
						if (j < columns)
						{
							arrn[i][j] = arr[i][j];
						}
						else arrn[i][j] = rand() % 10;
					}
				}
				else
					for (int j = 0; j < ncol; j++)
					{
						arrn[i][j] = rand() % 10;
					}
			}

		}

		this->arr = arrn;
		this->columns = ncol;
		this->lines = nlines;
		delete[] arrn;
	}

	void Matrix::loadmatrix(string path)
	{
		/*!
		\brief �������� ������� �� �����
		\details ���� ������������ ����� ����� �����, ������ ��� ������� �������� ����� �������� � ����� �������, � ����������� �������� �������, ���������� ����� ������ � �������� �����, ������������� ������� � �������� ���������� �������
		\param path ������ ��������� �� ������, ���������� ���� (���) �����, �� �������� ����������� �������
		*/
		ifstream f(path, ios_base::in);

		int col, line;
		if (!f) {
			return;
		}
		f >> col;
		f >> line;
		this->columns = col;
		this->lines = line;
		/*this->arr = new int* [lines];*/
		for (int i = 0; i < lines; i++)
			this->arr[i] = new int[columns];
		int n;
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				f >> n;
				this->arr[i][j] = n;
			}
		}
		f.close();
	}

	void Matrix::Transpon()
	{
		/*!
		\brief ����������� �������� ����������������
		\details ������� ������� [i][j] ���������� ��������� [j][i], ��� ������������ "���������������" �������
		*/
		int col = lines;
		int lines = columns;
		int** arrtr = new int* [lines];
		for (int i = 0; i < lines; i++)
			arrtr[i] = new int[col];

		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < col; j++)
			{
				arrtr[i][j] = arr[j][i];
			}
		}

		this->arr = arrtr;
		this->columns = col;
		this->lines = lines;
		delete[] arrtr;
	}