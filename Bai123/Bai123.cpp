#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void Hoanvi(float&, float&);
void SapDongGiam(float[][100], int, int);
int main()
{
	float a[100][100];

	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	SapDongGiam(a, n, m);
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
			cout << setw(8);
			cout << setprecision(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void Hoanvi(float& n, float& m)
{
	float temp = n;
	n = m;
	m = temp;
}
void SapDongGiam(float a[][100], int n, int m)
{
	int d;
	cout << "Nhap dong can sap dong theo thu tu giam dan: ";
	cin >> d;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[d][i] < a[d][j])
				Hoanvi(a[d][i], a[d][j]);
		}
	}
}