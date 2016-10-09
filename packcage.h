//-----------------------------------------------------------------------------
// File: packcage.h
//-----------------------------------------------------------------------------
#ifndef PACKCAGE_H
#define PACKCAGE_H
//-----------------------------------------------------------------------------
#include <iostream>
#include <ctime>
//-----------------------------------------------------------------------------
void randomize();             // ��������� ��������� ����� ����������
int iRandom(int a, int b);    // ������� ��������� ����� ����� �� [a, b]
double dRandom(int a, int b); // ������� ��������� ������� ����� �� [a, b]
//----------------------------------------------------------------------------
void printEndl();                            // ������� ������
void setup(bool &p, bool &d);                // ���� ��������
void inputData(int &size, int &dif);         // ���� ��������� ������
void generateArr(int *m, int s, int dif);    // ��������� ������� ������ (int)
void generateArr(double *m, int s, int dif); // ��������� ������� ������
//-----------------------------------------------------------------------------
template< typename T >
void printArr(T *a, int size) // ������ ������� ������
{
	std::cout << "\t { ";
	for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
	std::cout << "}\n";
}
//-----------------------------------------------------------------------------
struct TestData // ��������� ������ ��� ������������ �������
{
	int m[3];       // ���-�� ������������
	int n[3];       // ���-�� ���������
	bool type[3];   // ��� ����������
	int count;      // ����� �����
	TestData();     // �����������
	void print(const char *comment);  // ����� ������
};
//-----------------------------------------------------------------------------
#endif /* PACKCAGE_H */
//-----------------------------------------------------------------------------