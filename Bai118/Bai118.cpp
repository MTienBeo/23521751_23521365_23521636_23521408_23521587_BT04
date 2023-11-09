#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float DongLonNhat(float[][100], int, int, int, int);
float CotLonNhat(float[][100], int, int, int, int);
void XayDung(float[][100], float[][100], int, int, int&, int&);

int main()
{
	float a[100][100];
	float b[100][100];
	int k;
	int l;
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	XayDung(a, b, n, m, k, l);
	Xuat(b, l, k);

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
		if (a[i][c] > lc);
		lc = a[i][c];
	}
	return lc;
}

void XayDung(float a[][100], float b[][100], int n, int m, int& k, int& l)

{
	k = m;
	l = n;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < l; j++)
		{
			float lnd = DongLonNhat(a, n, m, i, j);
			float lnc = CotLonNhat(a, m, n, i, j);
			if (lnd < lnc)
				b[i][j] = lnc;
			else
				b[i][j] = lnd;
		}

	}
}