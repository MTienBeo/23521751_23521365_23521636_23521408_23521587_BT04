#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void HoanViCot(float[][500], int, int, int,
	           int);
void HoanViCot(float a[][500], int m, int n,
	           int c1, int c2)
{
	for (int i = 0;i < m;i++)
		HoanVi(a[i][c1], a[i][c2]);
}