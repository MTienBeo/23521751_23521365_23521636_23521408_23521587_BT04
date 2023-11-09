#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void BienDoi(float[][500], int, int);
void BienDoi(float a[][500], int m, int n)
{
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] < 0)
				a[i][j] = -a[i][j];
}