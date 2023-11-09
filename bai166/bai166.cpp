#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int ktCon(float[][500], int, int, int, int);
void ConDau(float[][500], int, int, int&, int&);

int ktCon(float a[][500], int m, int n,
	      int vtd, int vtc)
{
	int flag = 1;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			if (a[vtd + i][vtc + j] <= 0)
				flag = 0;
	return flag;
}