#pragma once

/**
 * \brief ��������� ��� ������ � ���������.
 * \date 2021-02-20
 * \author kolpakov dmitrii
 * i don't have any license, bitch. :\
 */

/**
 * \brief ��������� ������� ���������� ����������.
 * \param matrixPtr ��������� �� �������.
 * \param rows ���-�� �����.
 * \param columns ���-�� ��������.
 */
void MatrixHandler_fillMatrixWithRandom(int** matrixPtr, const int rows, const int columns);

/**
 * \brief ��������� ������� ������� ����������.
 * \param matrixPtr ��������� �� �������.
 * \param rows ���-�� �����.
 * \param columns ���-�� ��������.
 */
void MatrixHandler_fillMatrixManually(int** matrixPtr, const int rows, const int columns);

/**
 * \brief ��������� ������� �������� ����������.
 * \param matrixPtr ��������� �� �������.
 * \param rows ���-�� �����.
 * \param columns ���-�� ��������.
 */
void MatrixHandler_fillMatrixWithZeros(int** matrixPtr, const int rows, const int columns);

/**
 * \brief ����������� ����� ������� fromMatrixPtr � toMatrixPtr.
 * \param fromMatrixPtr ��������� �� �������, ������ ������������ �����������.
 * \param toMatrixPtr ��������� �� �������, ���� ����������.
 * \param rows ���-�� ����� ��� �����������.
 * \param columns ���-�� �������� ��� �����������.
 * \param row_offset �������� �� ������.
 * \param column_offset �������� �� �������.
 */
void MatrixHandler_copyMatrix(int** fromMatrixPtr, int** toMatrixPtr, const int rows, 
                              const int columns, const int row_offset, const int column_offset);