// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0)); // генерация случайных чисел
	int n;
	cout << "Введите размер матрицы: ";
	cin >> n;
	cout << endl;
	float **ptrarray = new float*[n];
	double **arrayRes = new double*[n];
	for (int count = 0; count < n; count++) {
		ptrarray[count] = new float[n]; 
		arrayRes[count] = new double[2];
	}

	// заполнение массива
	for (int count_row = 0; count_row < n; count_row++) {
		for (int count_column = 0; count_column < n; count_column++) {
			ptrarray[count_row][count_column] = (rand() % 10 + 1) / float((rand() % 10 + 1));
			arrayRes[count_row][0] = 0;
		}
	}

	// вывод массива
	for (int count_row = 0; count_row < n; count_row++)
	{
		for (int count_column = 0; count_column < n; count_column++)
			cout << setw(4) << setprecision(2) << ptrarray[count_row][count_column] << "   ";
		cout << endl;
	}


	for (int count_column = 0; count_column < n; count_column++) {
		for (int count_row = 0; count_row < n; count_row++) {
			arrayRes[count_column][0] += ptrarray[count_row][count_column];
		}
		arrayRes[count_column][1] = count_column;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arrayRes[i][0] > arrayRes[j][0]) {
				double tmp = arrayRes[i][0];
				arrayRes[i][0] = arrayRes[j][0];
				arrayRes[j][0] = tmp;

				int tmp1 = arrayRes[i][1];
				arrayRes[i][1] = arrayRes[j][1];
				arrayRes[j][1] = tmp1;
			}

		}
	}

	cout << "-----------------------------------------------" << endl;
	for (int count = 0; count < n; count++)
		cout << arrayRes[count][1] << "   " << arrayRes[count][0] << endl;
	cout << endl << "-----------------------------------------------" << endl;

	// удаление двумерного динамического массива
	for (int count = 0; count < n; count++)
		delete[]arrayRes[count];

	for (int count = 0; count < n; count++)
		delete[]ptrarray[count];
	system("pause");
	return 0;
	return 0;
}

