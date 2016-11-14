//-----------------------------------------------------------------------------
// File: sort.h
//-----------------------------------------------------------------------------
#ifndef SORT_H
#define SORT_H
//-----------------------------------------------------------------------------
#include "packcage.h"
//-----------------------------------------------------------------------------
typedef double TYPE; // Необходимый тип данных (int/double)
//-----------------------------------------------------------------------------
#define SWAP(A, B) { (A) = (A)+(B); (B) = (A)-(B); (A) = (A)-(B);  }
//-----------------------------------------------------------------------------
// Marcin Ciura's optimal sequence of increments for shell sort algorithm
const int A102549[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1}; 
//-----------------------------------------------------------------------------
template< typename T >                                 // Сортировка пузырьком
void bubleSort(T *a, int size, bool type, TestData &td)
{
	td.type[td.count] = type;
	int i, j;
	for (i = size-1; i >= 0; --i) {
		for (j = 0; j < i; j++) {
			if ( (type) ? (a[j] > a[j+1]) : (a[j] < a[j+1]) ) {
				SWAP(a[j], a[j+1]);
				td.m[td.count]++; // #
			}
			td.n[td.count]++; // #
		}
	}
	td.count++;
}
//-----------------------------------------------------------------------------
template< typename T >                             // Сортировка перестановками
void quietSort(T *a, int size, bool type, TestData &td)
{
	td.type[td.count] = type;
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = i+1; j < size; ++j) {
			if ((type) ? (a[j] < a[i]) : (a[j] > a[i])) {
				SWAP(a[i], a[j]);
				td.m[td.count]++; // #
			}
			td.n[td.count]++; // #
		}
	}
	td.count++;
}
//-----------------------------------------------------------------------------
template< typename T >                                     // Гномья сортировка
void dwarfSort(T *a, int size, bool type, TestData &td)
{
	td.type[td.count] = type;
	int i = 0;
	while (i < size) {
		if (i == 0 || ((type)?(a[i - 1] <= a[i]):(a[i - 1] >= a[i]))) ++i;
		else {
			SWAP(a[i], a[i-1]);
			td.m[td.count]++; // #
			--i;
		}
		td.n[td.count]++; // #
	}
	td.count++;
}
//-----------------------------------------------------------------------------
template< typename T >                                  // Сортировка вставками
void inserSort(T *a, int size, bool type, TestData &td) 
{
	td.type[td.count] = type;
	int i, j;
	for (j = 1; j < size; ++j) {
		T key = a[j];
		i = j - 1;
		while (i >= 0 && ((type)?(a[i] > key):(a[i] < key))) {
			a[i+1] = a[i];
			--i;
			td.m[td.count]++; // #
		}
		a[i+1] = key;
		td.n[td.count]++; // #
	}
	td.count++;
}
//-----------------------------------------------------------------------------
template< typename T >                          // Сортировка Шелла [Shell's d]
void shellSort(T *a, int size, bool type, TestData &td)
{
	td.type[td.count] = type;
	int i, j;
	for (int d = size/2; d > 0; d /= 2) {
		for (i = d; i < size; ++i) {
			T key = a[i];
			j = i;
			while (j >= d && ((type)?(a[j-d] > key):(a[j-d] < key))) {
				a[j] = a[j-d];
				j -= d;
				td.m[td.count]++; // #
			}
			a[j] = key;
			td.n[td.count]++; // #
		}
	}
	td.count++;
}
//-----------------------------------------------------------------------------
template< typename T >                          // Сортировка Шелла [Ciura's d]
void superShellSort(T *a, int size, bool type, TestData &td)
{
	td.type[td.count] = type;
	int i, j; 
	for (int d : A102549) {
		for (i = d; i < size; ++i) {
			T key = a[i];
			j = i;
			while (j >= d && ((type)?(a[j-d] > key):(a[j-d] < key))) {
				a[j] = a[j-d];
				j -= d;
				td.m[td.count]++; // #
			}
			a[j] = key;
			td.n[td.count]++; // #
		}
	}
	td.count++;
}
//-----------------------------------------------------------------------------
#endif /* SORT_H */
//-----------------------------------------------------------------------------