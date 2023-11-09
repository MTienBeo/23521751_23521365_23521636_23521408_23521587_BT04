#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

void Nhap(string filename, int[][500], int&, int&);


int main()
{
	string filename;
	int a[100][500];
	int m, n;
	Nhap("intdata6.inp", a, m, n);
	cout << "Ket thuc!!!\n\n\n";
}
void Nhap(string filename, int a[][500], int& m, int& n)

{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}