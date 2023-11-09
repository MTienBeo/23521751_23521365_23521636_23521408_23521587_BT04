#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float DuongDau(float[][100], int, int);
void DuongNhoNhat(float[][100], int, int);

int main()
{
	float a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	DuongNhoNhat(a, n, m);
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
float DuongDau(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0)
				return a[i][j];
		}
	}
	return 0;
}
void DuongNhoNhat(float a[][100], int m, int n)
{
	float lc = DuongDau(a, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0 && a[i][j] < lc)
				lc = a[i][j];
		}
	}
	cout << "Gia tri duong nho nhat trong ma tran la: " << lc;
}
