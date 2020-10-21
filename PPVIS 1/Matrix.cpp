#include "Matrix.h"

using namespace std;

    Matrix::Matrix(int lines_p, int columns_p)
	{	/*!
		Конструктор принимает количество строк и столбцов матрицы
		\param lines_p количество строк в содаваемой матрице
		\param columns_p количество столбцов в создаваемой матрице
		*/
		this->columns = columns_p;
		this->lines = lines_p;
	}

	Matrix::Matrix()
	{/*!
	 \brief Конструктор по умолчанию, который устанавливает начальное положение объекта. Не принимает параметров
	 */
		this->columns = 0;
		this->lines = 0;
	}

	Matrix::~Matrix()
	{/*!
		Деструктор освобождает память, выделенную для матрицы. Не принимает параметров
	 */
		for (int i = 0; i < lines; i++)
			delete[] arr[i];
	}

	int Matrix::getLines()
	{
		/*!
			Геттер для получения количества строк данной матрицы. Не принимает параметров
			\return Количество строк данной матрицы
		*/
		return this->lines;
	}

	int Matrix::getColumns()
	{
		/*!
			Геттер для получения столбцов данной матрицы. Не принимает параметров
			\return Количество столбцов данной матрицы
		*/
		return this->columns;
	}

	bool Matrix::identityType(const Matrix& matrix, bool diagonal)
	{
		/*!
		  \brief Дружественная функция Определяет, является ли матрица единичной, путём сравнения единиц в диагональной матрице
		  \details матрица называется единичной, если она диагональная и все её элементы на главной диагонали равны единице
		  \param matrix матрица, исследование которой проводится
		  \param diagonal булево значение, диагональная ли матрица
		  \return Булево значение true, если матрица единичная и false в ином случае
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
		  \brief Дружественная функция Определяет, является ли матрица нулевой, путём сравнения количества нулей в матрице
		  \details матрица называется нулевой, если все её равны нулю
		  \param matrix матрица, исследование которой проводится
		  \return Булево значение true, если матрица нулевая и false в ином случае
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
		  \brief Дружественная функция Определяет, является ли матрица симметричной, путём сравнения елементов с обратными индексами
		  \details матрица называется симметричной, если транспанированная матрица равна исходной
		  \param matrix матрица, исследование которой проводится
		  \param square булево значения, является ли матрица квадратной
		  \return Булево значение true, если матрица симметричная и false в ином случае
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
		  \brief Дружественная функция Определяет, является ли матрица верхней треугольной, путём сравнения елементов выше главой диагонали с нулём
		  \details матрица называется верхней треугольной, если её элементы ниже главной диагонали равны нулю
		  \param matrix матрица, исследование которой проводится
		  \param square булево значения, является ли матрица квадратной
		  \return Булево значение true, если матрица верхняя треугольная и false в ином случае
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
		  \brief Дружественная функция Определяет, является ли матрица нижней треугольной, путём сравнения елементов ниже главой диагонали с нулём
		  \details матрица называется верхней треугольной, если её элементы выше главной диагонали равны нулю
		  \param matrix матрица, исследование которой проводится
		  \param square булево значения, является ли матрица квадратной
		  \return Булево значение true, если матрица нижняя треугольная и false в ином случае
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
			\brief Дружественная функция Определяет, является ли матрица квадратной, путём сравнения количества строк и столбцов
			\param matrix матрица, исследование которой проводится
			\return Булево значение true, если матрица квадратная и false в ином случае
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
			\brief Дружественная функция Определяет, является ли матрица диагональной, путём сравнения количества нулей в матрице
			\details матрица называется диагональной, если она квадратная и все её элементы, кроме главной диагонали, равны нулю
			\param matrix матрица, исследование которой проводится
			\param square булево значение, является ли матрица квадратной
			\return Булево значение true, если матрица диагональная и false в ином случае
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
		Дружественная функция, выводящая матрицу в консоль
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
		\details Новая матрицы получается путём "обрезания" данной. Элементы и индексы сохраняются, если они соответсвуют новым заданным размерам
		\brief Извлекает подматрицу заданных размеров
		\param line число строк новой матрицы
		\param col число столбцов новой матрицы
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
		  \brief определяет тип матрицы
		  \details возможные типы: квадратная, диагональная, единичная, нулевая, верхняя треугольная, нижняя треугольная, симметричная либо ни одна из перечсиленных
		  \param matrix матрица, исследование которой производится
		  \return строку, которая содержит информацию о типе переданой матрицы
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
		Заполняет матрицу случайными числами в диапазоне от -10 до 10
		\param lines количество строк в содаваемой матрице
		\param columns количество столбцов в создаваемой матрице
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
		Постфиксный инкремент увеличивает каждый элемент матрицы на единицу
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
		Прибавление/вычитание числа к матрице
		/param n число которое прибавляют/вычитают
		*/
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < columns; j++)
				arr[i][j] += n;
	}

	void Matrix::incPr()
	{
		/*!
		Префиксный инкремент увеличивает каждый элемент матрицы на единицу
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
		Постфиксный декремент уменьшает каждый элемент матрицы на единицу
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
		Префиксный декремент уменьшает каждый элемент матрицы на единицу
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
		Изменение количества строк матрицы
		\param nlines число строк в новой матрице
		\param ncol число столбцов в новой матрице
		\details в ходе выполнения метода создаётся новая матрица, элементы с одинаковым индексом от предыдущей матрицы остаются теми же. В дополнительные ячейки, если введено число строк, превосходящее число строк изначальной матрицы, помещяются случайные числа.
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
		\brief Загрузка матрицы из файла
		\details файл представляет собой набор чисел, первые два которые означают число столбцов и строк матрицы, а последующие элементы матрицы, записанные через пробел и переносы строк, соответсвенно строкам и столбцам получаемой матрицы
		\param path строка передаётся по ссылке, содержащая путь (имя) файла, из которого считывается матрица
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
		\brief выполняется операция транспонирования
		\details элемент индекса [i][j] становится элементом [j][i], что соответсвует "переворачиванию" матрицы
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