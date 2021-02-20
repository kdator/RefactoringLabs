#include <iostream>

#include "MatrixHandler.hpp"

using std::cin;

void MatrixHandler_fillMatrixWithRandom(int** matrixPtr, const int rows, const int columns) {
	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++) {
			matrixPtr[i][j] = rand() % 10;
		}
	}
}

void MatrixHandler_fillMatrixManually(int** matrixPtr, const int rows, const int columns) {
	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++) {
			cin >> matrixPtr[i][j];
		}
	}
}

void MatrixHandler_fillMatrixWithZeros(int** matrixPtr, const int rows, const int columns) {
	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++)
			matrixPtr[i][j] = 0;
	}
}

void MatrixHandler_copyMatrix(int** fromMatrixPtr, int** toMatrixPtr, const int rows,
							  const int columns, const int row_offset, const int column_offset) {
	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++) {
			toMatrixPtr[i][j] = fromMatrixPtr[i + row_offset][j + column_offset];
		}
	}
}