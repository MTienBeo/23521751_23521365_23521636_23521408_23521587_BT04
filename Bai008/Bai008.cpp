#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void Nhap(string, float[][100], int&, int&);
void Xuat(float[][100], int&, int&);

int main()
{
	float a[100][100];
	int m;
	int n;
	Nhap("floatdata06.inp", a, n, m);
	Xuat(a, n, m);
}

void Nhap(string filename, float a[][100], int& n, int& m)
{
	ifstream fi(filename);
	fi >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fi >> a[i][j];
		}
	}
}
void Xuat(float a[][100], int& n, int& m)
{
	cout << "Ma tran " << m << " x " << n << ": " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) <<setprecision(2)<<fixed<< a[i][j];
		cout << endl;
	}
}