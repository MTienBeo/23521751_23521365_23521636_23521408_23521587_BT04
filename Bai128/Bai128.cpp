#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float TongDong(float[][100], int, int);
void Hoanvi(float&, float&);
void HoanviDong(float[][100], int, int, int);
void SapTang(float [][100], int, int);

int main()
{
	float a[100][100];

	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	SapTang(a, n, m);
	Xuat(a, n, m);
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
			a[i][j] = (-100.0 + (rand() / (RAND_MAX / 200.0)));
	}

}
void Xuat(float a[][100], int n, int m)
{
	cout << "Ma tran " << n << " x " << m << ": " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}
float TongDong(float a[][100], int n, int c)
{
	float s = 0;
	for (int j = 0; j < n; j++)
	{
		s = s + a[c][j];
	}
	return s;
}
void Hoanvi(float& n, float& m)
{
	float temp = n;
	n = m;
	m = temp;
}
void HoanviDong(float a[][100], int n, int m , int d1, int d2)
{
	for (int j = 0; j < n; j++)
	{
		Hoanvi(a[d1][j], a[d2][j]);
	}
}
void SapTang(float a[][100], int n, int m)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (TongDong(a, n, i) > TongDong(a, n, j))
				HoanviDong(a, n, m, i, j);
		}
	}
}