//-----------------------------------------------------------------------------
// File: packcage.cpp
//-----------------------------------------------------------------------------
#include "packcage.h"
//-----------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------
void Randomize()
{ srand((unsigned)time(NULL)); }
//-----------------------------------------------------------------------------
int iRandom( int a, int b )
{ return a + (b - a + 1) * rand() / RAND_MAX ; }   
//-----------------------------------------------------------------------------
double dRandom( int a, int b )
{ return a + (b - a) * rand() / (double)RAND_MAX; }   
//-----------------------------------------------------------------------------
// ���� ������
//-----------------------------------------------------------------------------
void InputData(int &size, int &dif)
{
	Randomize();
	cout << "Input array size: ";
	cin >> size;
	while (size <= 0) {
		cout << "Incorrect size, repeat: ";
		cin >> size;
	}
	cout << "Input difficulty: ";
	cin >> dif;
}
//-----------------------------------------------------------------------------
void GenerateArr(int *m, int s, int dif) // ��������� ������� ������ (int)
{	
	switch (dif) {
		case 0:
			for (int i = 0; i < s; ++i)
				m[i] = i;      // ������ ������ (������������)
			break;
		case 1:
			for (int i = 0; i < s; ++i) // ��������� ����� ������
				m[i] = iRandom(-999, 999);
			break;
		case 2:
			for (int i = 0; i < s; ++i)
				m[i] = s - i;  // ������ ������ (������������)
			break;
		case 3:
			for (int i = 0; i < s; ++i)
				cin >> m[i];   // ���� �� �����
			break;
		default:
			for (int i = 0; i < s; ++i)
				m[i] = 0;      //���������� 0-��
	}
}
//-----------------------------------------------------------------------------
void GenerateArr(double *m, int s, int dif) // ��������� ������� ������
{	
	switch (dif) {
		case 0:
			for (int i = 0; i < s; ++i)
				m[i] = i;      // ������ ������ (������������)
			break;
		case 1:
			for (int i = 0; i < s; ++i) // ��������� ����� ������
				m[i] = dRandom(-999, 999);
			break;
		case 2:
			for (int i = 0; i < s; ++i)
				m[i] = s - i;  // ������ ������ (������������)
			break;
		case 3:
			for (int i = 0; i < s; ++i)
				cin >> m[i];   // ���� �� �����
			break;
		default:
			for (int i = 0; i < s; ++i)
				m[i] = 0;      //���������� 0-��
	}
}
//-----------------------------------------------------------------------------
void PrintArr(int *a, int size) // ������ ������� ������ (int)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";
	cout << endl;
}
//-----------------------------------------------------------------------------
void PrintArr(double *a, int size) // ������ ������� ������
{
	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";
	cout << endl;
}
//-----------------------------------------------------------------------------