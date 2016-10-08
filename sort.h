//-----------------------------------------------------------------------------
// File: sort.h
//-----------------------------------------------------------------------------
#ifndef SORT_H
#define SORT_H
//-----------------------------------------------------------------------------
template< typename T >
void BubleSort(T *a, int size, bool type) // Сортировка пузырьком
{
	int i, j, m = 0, n = 0;
	for (i = size-1; i >= 0; --i) {
		for (j = 0; j < i; j++) {
			if ( (type) ? (a[j] > a[j+1]) : (a[j] < a[j+1]) ) {
				SWAP(a[j], a[j+1]);
				++m; // #
			}
			++n; // #
		}
	}
	if (DBUG) cout << m << "/" << n << endl;
}
//-----------------------------------------------------------------------------
template< typename T >
void QuietSort(T *a, int size, bool type) // Сортировка перестановками
{
	int i, j, m = 0, n = 0;
	for (i = 0; i < size; ++i) {
		for (j = i+1; j < size; ++j) {
			if ((type) ? (a[j] < a[i]) : (a[j] > a[i])) {
				SWAP(a[i], a[j]);
				++m; // #
			}
			++n; // #
		}
	}
	if (DBUG) cout << m << "/" << n << endl;
}
//-----------------------------------------------------------------------------
template< typename T >
void DwarfSort(T *a, int size, bool type) // Гномья сортировка
{
	int i = 0, m = 0, n = 0;
	while (i < size) {
		if (i == 0 || ((type)?(a[i - 1] <= a[i]):(a[i - 1] >= a[i]))) ++i;
		else {
			SWAP(a[i], a[i-1]);
			++m; // #
			--i;
		}
		++n; // #
	}
	if (DBUG) cout << m << "/" << n << endl;
}
//-----------------------------------------------------------------------------
template< typename T >
void InsertSort(T *a, int size, bool type) // Сортировка вставками
{
	int i, j, m = 0, n = 0;
	for (j = 1; j < size; ++j) {
		T key = a[j];
		i = j - 1;
		while (i >= 0 && ((type)?(a[i] > key):(a[i] < key))) {
			a[i+1] = a[i];
			--i;
			++n; // #
		}
		a[i+1] = key;
		++m; // #
	}
	if (DBUG) cout << m << "/" << n << endl;
}
//-----------------------------------------------------------------------------
template< typename T >
void ShellSort(T *a, int size, bool type) // Сортировка Шелла [Shell's d]
{
	int i, j, n = 0, m = 0;
	for (int d = size/2; d > 0; d /= 2) {
		for (i = d; i < size; ++i) {
			T key = a[i];
			j = i;
			while (j >= d && ((type)?(a[j-d] > key):(a[j-d] < key))) {
				a[j] = a[j-d];
				j -= d;
				n++; // #
			}
			a[j] = key;
			m++; // #
		}
	}
	if (DBUG) cout << m << "/" << n << endl;
}
//-----------------------------------------------------------------------------
template< typename T >
void SuperShellSort(T *a, int size, bool type) // Сортировка Шелла [Ciura's d]
{
	int i, j, m = 0, n = 0; 
	for (int d : A102549) {
		for (i = d; i < size; ++i) {
			T key = a[i];
			j = i;
			while (j >= d && ((type)?(a[j-d] > key):(a[j-d] < key))) {
				a[j] = a[j-d];
				j -= d;
				n++; // #
			}
			a[j] = key;
			m++; // #
		}
	}
	if (DBUG) cout << m << "/" << n << endl;
}
//-----------------------------------------------------------------------------
#endif /* SORT_H */
//-----------------------------------------------------------------------------