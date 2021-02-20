#pragma once

/**
 * \brief ��������� ��� ������ � ���������: ��������� ����� � ��������.
 * \date 2021-02-17
 * \author kolpakov dmitrii
 * i don't have any license, bitch. :\
 */

/**
 * \brief �������� ����� ��� ���������� �������. ��� ������������
 *        ������������ delete[].
 * \param rows ���-�� �����.
 * \param columns ���-�� ��������.
 * \return ���������� ������ ��� ��������� ������.
 */
int** ArrayHandler_allocateMemory(int rows, int columns);

/**
 * \brief ���������� ������ �� ��������� matrixPtr.
 * \param matrixPtr ��������� �� �������.
 * \param ���-�� ����� � �������.
 * \return true, ���� ������������ ��������� ��� ������,
 *         ����� false.
 */
void ArrayHandler_deleteMatrix(int** matrixPtr, int rows);