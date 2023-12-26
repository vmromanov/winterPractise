#pragma once

/*
* @brief ищет определитель матрицы
* @param n кол-во переменных
* @param matrix матрица, определитель которой ищем
*/
double determ(const int n, double** matrix);

/*
* @brief ищет минор к месту
*/
void findMinor(double** matrix, int size, int row, int col, double** minor);


void reverseMatrix(double** matrix_, double** reverse_, int size_);