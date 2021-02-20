#include <iostream>
#include <ctime>

#include "ArrayHandler.hpp"
#include "MatrixHandler.hpp"

using std::cout;
using std::cin;
using std::endl;

/**
 * \brief ����������� ������� matrixPtr �� �����.
 * \param rows ���-�� �����.
 * \param columns ���-�� ��������.
 * \param msg ���������, ������� ����� ���������� ����� ������� �������.
 */
static void printMatrix(int** matrixPtr, int rows, int columns, const char* msg);

int main(void) {
	srand(time(NULL));
	system("chcp 1251");

	int firstMatrixRows, firstMatrixColumns; // ���-�� �����/�������� ��� ������ �������.
	int secondMatrixRows, secondMatrixColumns; // ���-�� �����/������� ��� ������ �������.
	int userSelection; // ������ ���������� �������, ��������� �������������.

	int matrixMinSize = 2; // ��������� ��� ������������ ������� �������.

	cout << "��� ������������ ��������� �������� ������������ ������ ������� ���������." << endl << endl;

	///////////////////////////////////////////////////////////////////////////////
	////////////////////���� �������� ������� �������������////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "������� ������� ������ �������: ";
	cin >> firstMatrixRows >> firstMatrixColumns;
	if (cin.fail() || firstMatrixRows <= 0 || firstMatrixColumns <= 0) {
		cin.ignore();
		cin.clear();
		cout << "������� ������� ������ �������: ";
		cin >> firstMatrixRows >> firstMatrixColumns;
	}

	cout << "������� ������� ������ �������: ";
	cin >> secondMatrixRows >> secondMatrixColumns;
	if (cin.fail() || secondMatrixRows <= 0 || secondMatrixColumns <= 0) {
		cin.ignore();
		cin.clear();
		cout << "������� ������� ������ �������: ";
		cin >> secondMatrixRows >> secondMatrixColumns;
	}

	int** firstMatrix = ArrayHandler_allocateMemory(firstMatrixRows,
													firstMatrixColumns);
	int** secondMatrix = ArrayHandler_allocateMemory(secondMatrixRows,
													 secondMatrixColumns);

	if (!firstMatrix || !secondMatrix)
		return 0;

	///////////////////////////////////////////////////////////////////////////////
	////////////////����� ������� ���������� � ���������� ������///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do {
		cout << "�������� ������ ���������� ������ (1 - �������, 2 - ��������� �������): ";
		cin >> userSelection;
	} while (userSelection < 1 || userSelection > 2);

	switch (userSelection) {
		case 1:
			MatrixHandler_fillMatrixManually(firstMatrix, firstMatrixRows, firstMatrixColumns);
			MatrixHandler_fillMatrixManually(secondMatrix, secondMatrixRows, secondMatrixColumns);

			printMatrix(firstMatrix, firstMatrixRows, firstMatrixColumns, "\n������� 1\n\n");
			printMatrix(secondMatrix, secondMatrixRows, secondMatrixColumns, "\n������� 2\n\n");
			break;
		case 2:
			MatrixHandler_fillMatrixWithRandom(firstMatrix, firstMatrixRows, firstMatrixColumns);
			MatrixHandler_fillMatrixWithRandom(secondMatrix, secondMatrixRows, secondMatrixColumns);

			printMatrix(firstMatrix, firstMatrixRows, firstMatrixColumns, "\n������� 1\n\n");
			printMatrix(secondMatrix, secondMatrixRows, secondMatrixColumns, "\n������� 2\n\n");
			break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////���������� ������ � ���������� �������////////////////////////
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

	cout << endl << "����������� �������\n";
	printMatrix(M3, matrixMinSize, matrixMinSize, "\n������� 1\n\n");
	printMatrix(M4, matrixMinSize, matrixMinSize, "\n������� 2\n\n");

	///////////////////////////////////////////////////////////////////////////////
	///////////////��������� ������ �� ���������� � �� ����������//////////////////
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
	////////////////////////�������� ������������� ������//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** intermediate1 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate2 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate3 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate4 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate5 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate6 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** intermediate7 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////���������� �������� ������������� ������///////////////////
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
	///////////////////////�������� ��������������� ������/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat9 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** mat10 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** mat11 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);
	int** mat12 = ArrayHandler_allocateMemory(halfMatrixMinSize, halfMatrixMinSize);

	///////////////////////////////////////////////////////////////////////////////
	////////////������� �������� ��������������� ������ �� �������������///////////
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
	///////////////////�������� �������������� �������/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = ArrayHandler_allocateMemory(matrixMinSize, matrixMinSize);

	///////////////////////////////////////////////////////////////////////////////
	///////��������� ���������� �� ��������������� ������ � ��������������/////////
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
	////////////////������������ ������ �������������� �������/////////////////////
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
	///////////////////����� �������������� �������////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	printMatrix(resultMatrix, f, s, "\n�������������� �������\n\n");
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////������� ������������ ������///////////////////////////////
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