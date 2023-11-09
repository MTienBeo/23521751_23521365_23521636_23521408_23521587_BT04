#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void DichLenCot(float[][500], int, int, int);
void DichLen(float[][500], int, int);

void DichLenCot(float a[][500],
	            int m, int n, int c)
{
	float temp = a[0][c];
	for (int i = 0;i <= m - 2;i++)
		a[i][c] = a[i + 1][c];
	a[m - 1][c] = temp;
}

void DichLen(float a[][500], int m, int n)
{
	for (int j = 0;j < n;j++)
		DichLenCot(a, m, n, j);
}