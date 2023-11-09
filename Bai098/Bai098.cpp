#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float DongLonNhat(float[][100], int, int, int, int);
float CotLonNhat(float[][100], int, int, int, int);
float Cheo1LonNhat(float[][100], int, int, int, int );
float Cheo2LonNhat(float[][100], int, int, int, int );
bool ktHoangHau(float[][100], int, int, int, int);
void DemHoangHau(float[][100], int, int);

int main()
{
	float a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	DemHoangHau(a, n, m);
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

float DongLonNhat(float a[][100], int n, int m, int d, int c)
{
	float lc = a[d][0];
	for (int j = 0; j < n; j++)
	{
		if (a[d][j] > lc)
			lc = a[d][j];
		
	}
	return lc;
}
float CotLonNhat(float a[][100], int n, int m, int d, int c)
{
	float lc = a[0][c];
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] > lc)
			lc = a[i][c];
	}
	return lc;
}
float Cheo1LonNhat(float a[][100], int n, int m, int d, int c)
{
	float lc = a[d][c];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i - j == d - c) && (a[i][j] > lc))
				lc = a[i][j];
		}
	}
	return lc;
}
float Cheo2LonNhat(float a[][100], int n, int m, int d, int c)
{
	float lc = a[d][c];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j == d + c) && (a[i][j] > lc))
				lc = a[i][j];
		}
	}
	return lc;
}
bool ktHoangHau(float a[][100], int n, int m, int d, int c)
{
	float lnd = DongLonNhat(a, n, m, d, c);
	float lnc = CotLonNhat(a, n, m, d, c);
	float lnc1 = Cheo1LonNhat(a, n, m, d, c);
	float lnc2 = Cheo2LonNhat(a, n, m, d, c);
	if ((a[d][c] == lnd) && (a[d][c] == lnc) && (a[d][c] == lnc1) && (a[d][c] == lnc2))
		return true;
	return false;
}

void DemHoangHau(float a[][100], int n, int m)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktHoangHau(a, n, m, i, j))
			{
				dem++;
			}
		}
	}
	cout << "So luong gia tri Hoang Hau tren ma tran la: " << dem;
}
