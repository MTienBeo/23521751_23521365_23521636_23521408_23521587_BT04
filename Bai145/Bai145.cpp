#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
bool ktDong(int**, int, int, int);
void XoaDong(int**, int&, int, int);
void XoaDong(int**, int&, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	XoaDong(a, m, n);
	cout << "\Ma tran sau khi xoa cac dong toan so chan: " << endl;
	Xuat(a, m, n);

	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
	return 0;
}

void Nhap(int**& a, int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}

void Xuat(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setprecision(2) << setw(10) << a[i][j];
		cout << endl;
	}
}

bool ktDong(int** a, int m, int n, int d)
{
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 != 0)
			return 0;
	return 1;
}

void XoaDong(int** a, int& m, int n, int d)
{
	for (int i = d; i < m - 1; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = a[i+1][j];
	m--;
}

void XoaDong(int** a, int& m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i))
			XoaDong(a, m, n, i);
}