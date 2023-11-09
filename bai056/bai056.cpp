#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool ktHoanThien(int k)
{
	int s = 0;
	for (int i = 1;i < k;i++)
		if (k % i == 0)
			s = s + i;
	if (s == k)
		return true;
	return false;
}

