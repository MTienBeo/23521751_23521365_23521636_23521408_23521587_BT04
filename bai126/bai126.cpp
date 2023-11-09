#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void SapDongTang(float[][500], int, int, int);
void SapDongGiam(float[][500], int, int, int);
void SapXep(float[][500], int, int);

void SapDongTang(float a[][500], int m, int n,
	int d)
{
	for (int i = 0;i <= n - 2;i++)
		for (int j = i + 1;j <= n - 1;j++)
			if (a[d][i] > a[d][j])
				HoanVi(a[d][i], a[d][j]);
}
void SapDongGiam(float a[][500], int m, int n,
	             int d)
{
	for (int i = 0;i <= n - 2;i++)
		for (int j = i + 1;j <= n - 1;j++)
			if (a[d][i] < a[d][j])
				HoanVi(a[d][i], a[d][j]);
}
void SapXep(int a[][500], int m, int n)
{
	void SapXep(int a[][500], int m, int n)
		if (i % 2 == 0)
			SapDongTang(a, m, n, i);
		else
			SapDongGiam(a, m, n, i);
}