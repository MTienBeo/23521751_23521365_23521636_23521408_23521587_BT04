#include<iostream>
#include<iomanip>
using namespace std;


void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void Hoanvi(int&, int&);
void ChanTang(int[][100], int, int);
void LeGiam(int[][100], int, int);
void ChanTangLeGiam(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	ChanTangLeGiam(a, n, m);
	Xuat(a, n, m);
}
void TaoMaTran(int a[][100], int& n, int& m)
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
			a[i][j] = -100 + rand() % 200;
		}
	}
}
void Xuat(int a[][100], int n, int m)
{
	cout << "Ma tran " << m << " x " << n << " :" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
}
void Hoanvi(int& n, int& m)
{
	int temp = n;
	n = m;
	m = temp;
}
void ChanTang(int a[][100], int n, int m)
{
	int b[500];
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				b[k++] = a[i][j];
			}
		}
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
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				a[i][j]=b[k++];
			}
		}
	}
}
void LeGiam(int a[][100], int n, int m)
{
	int b[100];
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				b[k++] = a[i][j];
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i+1; j < k; j++)
		{
			if (b[i] < b[j])
				Hoanvi(b[i], b[j]);
		}
	}
	k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				a[i][j] = b[k++];
			}
		}
	}
}
void ChanTangLeGiam(int a[][100], int n, int m)
{
	ChanTang(a, n, m);
	LeGiam(a, n, m);
}