#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
int DemChuSo(int);
int DemCot(int**, int, int, int);
int DemLonNhat(int**, int, int);
void LietKe(int**, int, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	cout << "\nCac co co so luong chu so lon nhat : ";
	LietKe(a, m, n);

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

int DemChuSo(int n)
{
	int dem = 0;
	int t = abs(n);
	if (t == 0)
		return 1;
	while (t != 0)
	{
		dem++;
		t = t / 10;
	}
	return dem;
}

int DemCot(int** a, int m, int n, int c)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		dem += DemChuSo(a[i][c]);
	return dem;
}

int DemLonNhat(int** a, int m, int n)
{
	int lc = DemCot(a, m, n, 0);
	for (int j = 1; j < n; j++)
		if (DemCot(a, m, n, j) > lc)
			lc = DemCot(a, m, n, j);
	return lc;
}

void LietKe(int** a, int m, int n)
{
	for (int j = 0; j < n; j++)
		if (DemCot(a, m, n, j) == DemLonNhat(a, m, n))
			cout << setw(5) << j;
}