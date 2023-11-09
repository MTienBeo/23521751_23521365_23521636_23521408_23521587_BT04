#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float TongDong(float[][100], int, int);
void TongLonNhat(float[][100], int, int);

int main()
{
	float a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	TongLonNhat(a, n, m);
}

void TaoMaTran(float a[][100], int& n, int& m)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / 200.0));
	}
}
void Xuat(float a[][100], int n, int m)
{
	cout << "Ma tran " << n << " x " << m << ": " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(9);
			cout << setprecision(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}
float TongDong(float a[][100], int n, int k)
{
	float s = 0;
	for (int j = 0; j < n; j++)
	{
		s = s + a[k][j];
	}
	return s;
}
void TongLonNhat(float a[][100], int m, int n)
{
	float lc = TongDong(a, n, 0);
	for (int i = 0; i < m; i++)
	{
		if (lc <TongDong(a,n,i))
			lc = TongDong(a,n,i);
	}
	cout << "Tong dong lon nhat trong ma tran la: " << lc;
}
