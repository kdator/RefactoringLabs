#pragma once

/**
 * \brief Интерфейс для работы с матрицами.
 * \date 2021-02-20
 * \author kolpakov dmitrii
 * i don't have any license, bitch. :\
 */

/**
 * \brief Заполнить матрицу рандомными значениями.
 * \param matrixPtr указатель на матрицу.
 * \param rows кол-во строк.
 * \param columns кол-во столбцов.
 */
void MatrixHandler_fillMatrixWithRandom(int** matrixPtr, const int rows, const int columns);

/**
 * \brief Заполнить матрицу ручными значениями.
 * \param matrixPtr указатель на матрицу.
 * \param rows кол-во строк.
 * \param columns кол-во столбцов.
 */
void MatrixHandler_fillMatrixManually(int** matrixPtr, const int rows, const int columns);

/**
 * \brief Заполнить матрицу нулевыми значениями.
 * \param matrixPtr указатель на матрицу.
 * \param rows кол-во строк.
 * \param columns кол-во столбцов.
 */
void MatrixHandler_fillMatrixWithZeros(int** matrixPtr, const int rows, const int columns);

/**
 * \brief Скопировать часть матрицы fromMatrixPtr в toMatrixPtr.
 * \param fromMatrixPtr указатель на матрицу, откуда производится копирование.
 * \param toMatrixPtr указатель на матрицу, куда копируется.
 * \param rows кол-во строк для копирования.
 * \param columns кол-во столбцов для копирования.
 * \param row_offset смещение по строке.
 * \param column_offset смещение по столбцу.
 */
void MatrixHandler_copyMatrix(int** fromMatrixPtr, int** toMatrixPtr, const int rows, 
                              const int columns, const int row_offset, const int column_offset);