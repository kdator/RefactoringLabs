#include <iostream>
#include <ctime>

#include "ArrayHandler.hpp"
#include "MatrixHandler.hpp"

using std::cout;
using std::cin;
using std::endl;

/**
 * \brief Распечатать матрицу matrixPtr на экран.
 * \param rows кол-во строк.
 * \param columns кол-во столбцов.
 * \param msg сообщение, которое будет печататься перед выводом матрицы.
 */
static void printMatrix(int** matrixPtr, int rows, int columns, const char* msg);

int main(void) {
	srand(time(NULL));
	system("chcp 1251");

	int firstMatrixRows, firstMatrixColumns; // кол-во строк/столбцов для первой матрицы.
	int secondMatrixRows, secondMatrixColumns; // кол-во строк/стобцов для второй матрицы.
	int userSelection; // способ заполнения матрицы, выбранный пользователем.

	int matrixMinSize = 2; // множитель для минимального размера матрицы.

	cout << "Вас приветствует программа быстрого перемножения матриц методом Штрассена." << endl << endl;

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "Введите размеры первой матрицы: ";
	cin >> firstMatrixRows >> firstMatrixColumns;
	if (cin.fail() || firstMatrixRows <= 0 || firstMatrixColumns <= 0) {
		cin.ignore();
		cin.clear();
		cout << "Введите размеры первой матрицы: ";
		cin >> firstMatrixRows >> firstMatrixColumns;
	}

	cout << "Введите размеры второй матрицы: ";
	cin >> secondMatrixRows >> secondMatrixColumns;
	if (cin.fail() || secondMatrixRows <= 0 || secondMatrixColumns <= 0) {
		cin.ignore();
		cin.clear();
		cout << "Введите размеры второй матрицы: ";
		cin >> secondMatrixRows >> secondMatrixColumns;
	}

	int** firstMatrix = ArrayHandler_allocateMemory(firstMatrixRows, firstMatrixColumns);
	int** secondMatrix = ArrayHandler_allocateMemory(secondMatrixRows, secondMatrixColumns);

	if (!firstMatrix || !secondMatrix)
		return 0;

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do {
		cout << "Выберите способ заполнения матриц (1 - Вручную, 2 - Случайным образом): ";
		cin >> userSelection;
	} while (userSelection < 1 || userSelection > 2);

	switch (userSelection) {
		case 1:
			MatrixHandler_fillMatrixManually(firstMatrix, firstMatrixRows, firstMatrixColumns);
			MatrixHandler_fillMatrixManually(secondMatrix, secondMatrixRows, secondMatrixColumns);

			printMatrix(firstMatrix, firstMatrixRows, firstMatrixColumns, "\nМатрица 1\n\n");
			printMatrix(secondMatrix, secondMatrixRows, secondMatrixColumns, "\nМатрица 2\n\n");
			break;
		case 2:
			MatrixHandler_fillMatrixWithRandom(firstMatrix, firstMatrixRows, firstMatrixColumns);
			MatrixHandler_fillMatrixWithRandom(secondMatrix, secondMatrixRows, secondMatrixColumns);

			printMatrix(firstMatrix, firstMatrixRows, firstMatrixColumns, "\nМатрица 1\n\n");
			printMatrix(secondMatrix, secondMatrixRows, secondMatrixColumns, "\nМатрица 2\n\n");
			break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (matrixMinSize < firstMatrixRows || matrixMinSize < secondMatrixRows
		   || matrixMinSize < firstMatrixColumns || matrixMinSize < secondMatrixColumns)
		matrixMinSize *= 2;

	int halfMatrixMinSize = matrixMinSize / 2;

	int** M3 = ArrayHandler_allocateMemory(matrixMinSize, matrixMinSize);
	MatrixHandler_fillMatrixWithZeros(M3, matrixMinSize, matrixMinSize);

	int** M4 = ArrayHandler_allocateMemory(matrixMinSize, matrixMinSize);
	MatrixHandler_fillMatrixWithZeros(M4, matrixMinSize, matrixMinSize);

	MatrixHandler_copyMatrix(firstMatrix, M3, firstMatrixRows, firstMatrixColumns, 0, 0);
	MatrixHandler_copyMatrix(secondMatrix, M4, secondMatrixRows, secondMatrixColumns, 0, 0);

	cout << endl << "Приведенные матрицы\n";
	printMatrix(M3, matrixMinSize, matrixMinSize, "\nМатрица 1\n\n");
	printMatrix(M4, matrixMinSize, matrixMinSize, "\nМатрица 2\n\n");

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** submatrix1 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M3, submatrix1, halfMatrixMinSize, halfMatrixMinSize, 0, 0);
	
	int** submatrix2 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M3, submatrix2, halfMatrixMinSize, halfMatrixMinSize, 0, halfMatrixMinSize);

	int** submatrix3 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M3, submatrix3, halfMatrixMinSize, halfMatrixMinSize, halfMatrixMinSize, 0);

	int** submatrix4 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M3, submatrix4, halfMatrixMinSize, halfMatrixMinSize, halfMatrixMinSize, halfMatrixMinSize);

	int** submatrix5 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M4, submatrix5, halfMatrixMinSize, halfMatrixMinSize, 0, 0);

	int** submatrix6 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M4, submatrix6, halfMatrixMinSize, halfMatrixMinSize, 0, halfMatrixMinSize);

	int** submatrix7 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M4, submatrix7, halfMatrixMinSize, halfMatrixMinSize, halfMatrixMinSize, 0);

	int** submatrix8 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	MatrixHandler_copyMatrix(M4, submatrix8, halfMatrixMinSize, halfMatrixMinSize, halfMatrixMinSize, halfMatrixMinSize);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** intermediate1 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate2 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate3 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate4 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate5 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate6 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate7 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < halfMatrixMinSize; i++) {
		for (int j = 0; j < halfMatrixMinSize; j++) {
			intermediate1[i][j] = 0;
			for (int z = 0; z < halfMatrixMinSize; z++)
				intermediate1[i][j] += (submatrix1[i][z] + submatrix4[i][z]) * (submatrix5[z][j] + submatrix8[z][j]);

			intermediate2[i][j] = 0;
			for (int z = 0; z < halfMatrixMinSize; z++)
				intermediate2[i][j] += (submatrix3[i][z] + submatrix4[i][z]) * submatrix5[z][j];

			intermediate3[i][j] = 0;
			for (int z = 0; z < halfMatrixMinSize; z++)
				intermediate3[i][j] += submatrix1[i][z] * (submatrix6[z][j] - submatrix8[z][j]);

			intermediate4[i][j] = 0;
			for (int z = 0; z < halfMatrixMinSize; z++)
				intermediate4[i][j] += submatrix4[i][z] * (submatrix7[z][j] - submatrix5[z][j]);

			intermediate5[i][j] = 0;
			for (int z = 0; z < halfMatrixMinSize; z++)
				intermediate5[i][j] += (submatrix1[i][z] + submatrix2[i][z]) * submatrix8[z][j];

			intermediate6[i][j] = 0;
			for (int z = 0; z < halfMatrixMinSize; z++)
				intermediate6[i][j] += (submatrix3[i][z] - submatrix1[i][z]) * (submatrix5[z][j] + submatrix6[z][j]);

			intermediate7[i][j] = 0;
			for (int z = 0; z < halfMatrixMinSize; z++)
				intermediate7[i][j] += (submatrix2[i][z] - submatrix4[i][z]) * (submatrix7[z][j] + submatrix8[z][j]);
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat9 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** mat10 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** mat11 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** mat12 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);

	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < halfMatrixMinSize; i++) {
		for (int j = 0; j < halfMatrixMinSize; j++) {
			mat9[i][j] = intermediate1[i][j] + intermediate4[i][j] - intermediate5[i][j] + intermediate7[i][j];
			mat10[i][j] = intermediate3[i][j] + intermediate5[i][j];
			mat11[i][j] = intermediate2[i][j] + intermediate4[i][j];
			mat12[i][j] = intermediate1[i][j] - intermediate2[i][j] + intermediate3[i][j] + intermediate6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = ArrayHandler_allocateMemory(matrixMinSize, matrixMinSize);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < halfMatrixMinSize; i++) {
		for (int j = 0; j < halfMatrixMinSize; j++) {
			M5[i][j] = mat9[i][j];
			M5[i][j + halfMatrixMinSize] = mat10[i][j];
			M5[i + halfMatrixMinSize][j] = mat11[i][j];
			M5[i + halfMatrixMinSize][j + halfMatrixMinSize] = mat12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 100, s = 100;
	for (int i = 0; i < matrixMinSize; i++) {
		x = 0;
		for (int j = 0; j < matrixMinSize; j++) {
			if (M5[i][j] != 0) {
				x++;
				f = 100;
			}
		}
		if (x == 0 && i < f)
			f = i;
	}
	for (int i = 0; i < matrixMinSize; i++) {
		x = 0;
		for (int j = 0; j < matrixMinSize; j++) {
			if (M5[j][i] != 0) {
				x++;
				s = 100;
			}
		}
		if (x == 0 && i < s)
			s = i;
	}

	int** resultMatrix = ArrayHandler_allocateMemory(f, s);
	MatrixHandler_copyMatrix(M5, resultMatrix, f, s, 0, 0);

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	printMatrix(resultMatrix, f, s, "\nРезультирующая матрица\n\n");
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	ArrayHandler_deleteMatrix(firstMatrix, firstMatrixRows);
	ArrayHandler_deleteMatrix(secondMatrix, secondMatrixRows);
	ArrayHandler_deleteMatrix(M3, matrixMinSize);
	ArrayHandler_deleteMatrix(M4, matrixMinSize);
	ArrayHandler_deleteMatrix(M5, matrixMinSize);
	ArrayHandler_deleteMatrix(resultMatrix, f);
	ArrayHandler_deleteMatrix(submatrix1, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(submatrix2, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(submatrix3, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(submatrix4, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(submatrix5, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(submatrix6, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(submatrix7, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(submatrix8, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(mat9, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(mat10, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(mat11, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(mat12, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(intermediate1, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(intermediate2, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(intermediate3, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(intermediate4, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(intermediate5, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(intermediate6, halfMatrixMinSize);
	ArrayHandler_deleteMatrix(intermediate7, halfMatrixMinSize);

	return 0;
}

static void printMatrix(int** matrixPtr, int rows, int columns, const char* msg) {
	cout << msg << endl;

	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++)
			cout << matrixPtr[i][j] << " ";
		cout << endl;
	}
}
