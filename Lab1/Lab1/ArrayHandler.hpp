#pragma once

/**
 * \brief Интерфейс для работы с массивами: выделение места и очищение.
 * \date 2021-02-17
 * \author kolpakov dmitrii
 * i don't have any license, bitch. :\
 */

/**
 * \brief Выделить место для двумерного массива. Для освобождения
 *        использовать delete[].
 * \param rows кол-во строк.
 * \param columns кол-во столбцов.
 * \return выделенную память под двумерный массив.
 */
int** ArrayHandler_allocateMemory(int rows, int columns);

/**
 * \brief Освободить память по указателю matrixPtr.
 * \param matrixPtr указатель на матрицу.
 * \param кол-во строк в таблице.
 * \return true, если освобождение произошло без ошибок,
 *         иначе false.
 */
void ArrayHandler_deleteMatrix(int** matrixPtr, int rows);