#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Xoay90(float[][500], int&, int&);
void Xoay90(float a[][500], int& m, int& n)
{
	float b[500][500];
	int k, l;

	k = n;
	l = m;
	for (int i = 0;i < k;i++)
		for (int j = 0;j < l;j++)
			b[i][j] = a[j][n - 1 - i];

	m = k;
	n = l;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			a[i][j] = b[i][j];
}