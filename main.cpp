﻿//-----------------------------------------------------------------------------
// File: main.cpp
//-----------------------------------------------------------------------------
#include "main.h"
//-----------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------
bool PRINT = 0;   // Единоразовый вывод массива (Да/Нет)
bool DEBUG = 0;   // Постоянный вывод массива (Да/Нет)
//-----------------------------------------------------------------------------
typedef void (*SORT)(TYPE *a, int size, bool type, TestData &td);
//-----------------------------------------------------------------------------
TestData testSort(SORT method, const TYPE *a, const int size)
{
	TYPE *b = new TYPE[size];        // Копия данных
	memcpy(b, a, sizeof(TYPE)*size); // Копируем 
	TestData td;                     // Инициализируем тестовые данные
	if (DEBUG) printEndl();
	method(b, size, 0, td);          // Тест 1: сортируем произвольный массив
	if (DEBUG) printArr(b, size);
	method(b, size, 1, td);          // Тест 2: сортируем инвертированный массив
	if (DEBUG) printArr(b, size);
	method(b, size, 1, td);          // Тест 3: сортируем отсортированный массив
	if (DEBUG) printArr(b, size);
	delete [] b;                     // Очистка памяти (!)
	return td;
}
//-----------------------------------------------------------------------------
int main()
{
	int size;             // Размер массива
	int dif;              // Тип генерации массива данных
	setup(PRINT, DEBUG);  // Предустановка глобальных констант
	inputData(size, dif); // Ввод параметров
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	TYPE *a = new TYPE[size];    // Массив размером SIZE
	generateArr(a, size, dif);   // Генерируем данные
	if (PRINT) { printEndl(); printArr(a, size); }
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	SORT methods[6] = { bubleSort, 
		                quietSort, 
					    dwarfSort, 
					    inserSort, 
					    shellSort, 
					    superShellSort };
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	const char *title[6] = { "Сортировка пузырьком\0",
		                     "Сортировка перестановками\0",
							 "Гномья сортировка\0",
							 "Сортировка вставками\0",
							 "Сортировка Шелла\0",
							 "Cортировка Шелла (A102549)\0" };
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Провести тестирование 6-ти методов и вывести результаты
	for (int i = 0; i < 6; i++)
		(testSort(methods[i], a, size)).print(title[i]);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	delete [] a; // Очищаем память (!)
	return 0;
}
//-----------------------------------------------------------------------------
//                                                   By SnipGhost on 08.10.2016
//-----------------------------------------------------------------------------