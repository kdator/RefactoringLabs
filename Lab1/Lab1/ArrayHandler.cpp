#include <new>
#include <iostream>

using std::cin;
using std::bad_alloc;

#include "ArrayHandler.hpp"

int** ArrayHandler_allocateMemory(int rows, int columns) {
	try {
		int** generatedMatrix = new int* [rows];

		for (auto i = 0; i < rows; i++)
			generatedMatrix[i] = new int[columns];

		return generatedMatrix;
	}
	catch (bad_alloc & ex) {
		return nullptr;
	}
}

void ArrayHandler_fillMatrixWithRandom(int** matrixPtr, int rows, int columns) {
	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++) {
			matrixPtr[i][j] = rand() % 10;
		}
	}
}

void ArrayHandler_fillArrayManually(int** matrixPtr, int rows, int columns) {
	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++) {
			cin >> matrixPtr[i][j];
		}
	}
}

void ArrayHandler_deleteMatrix(int** matrixPtr, int rows) {
	for (auto i = 0; i < rows; i++)
		delete[] matrixPtr[i];
	delete[] matrixPtr;
}