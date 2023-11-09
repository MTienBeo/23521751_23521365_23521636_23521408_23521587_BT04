#include<iostream>
#include<iomanip>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void DuongBienTang(float[][100], int, int);
void Hoanvi(float&, float&);

int main()
{
	float a[100][100];
	int n;
	int m;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	DuongBienTang(a, n, m);
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
		{
			a[i][j] = -100.0 + (rand() / (RAND_MAX / 200.0));
		}
	}
}

void Xuat(float a[][100], int n, int m)
{
	cout << "Ma tran " << m << " x " << n << " la: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8) << setprecision(5) << a[i][j];
		}
		cout << endl;
	}
}

void Hoanvi(float& m, float& n)
{
	float temp = n;
	n = m;
	m = temp;
}

void DuongBienTang(float a[][100], int n, int m)
{
	float b[200];
	int k = 0;
	for (int j = 0; j < n - 1; j++)
	{
		b[k++] = a[0][j]; 
	}
	for (int i = 0; i < m - 1; i++)
	{
		b[k++] = a[i][n - 1];
	}
	for (int j = n - 1; j > 0; j--)
	{
		b[k++] = a[m - 1][j];
	}
	for (int i = m - 1; i > 0; i--)
	{
		b[k++] = a[i][0];
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i+1; j < k; j++)
		{
			if (b[i] > b[j])
				Hoanvi(b[i], b[j]);
		}
	}
	k = 0;
	for (int j = 0; j < n - 1; j++)
	{
		a[0][j] = b[k++];
	}
	for (int i = 0; i < m - 1; i++)
	{
		a[i][n - 1] = b[k++];
	}
	for (int j = n - 1; j > 0; j--)
	{
		a[m - 1][j] = b[k ++];
	}
	for (int i = m - 1; i > 0; i--)
	{
		a[i][0] = b[k++];
	}
}