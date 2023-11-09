#include <iostream>
#include <iomanip>
using namespace std;

int TonTaiDuong(float[][500], int, int);

{
	int flag = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] > 0)
				flag = 1;
	return flag;
}