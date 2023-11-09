#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float NhoNhatDong(float[][500], int, int, int);
void ThemCot(float[][500], int, int&);

int main()
{
	float a[500][500];
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	ThemCot(a, m, n);
	cout << "\Ma tran sau khi them 1 cot nho nhat: " << endl;
	Xuat(a, m, n);

	return 0;
}

void Nhap(float a[][500], int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setprecision(2) << setw(10) << a[i][j];
		cout << endl;
	}
}

float NhoNhatDong(float a[][500], int m, int n, int d)
{
	int lc = a[d][0];
	for (int j = 1; j < n; j++)
		if (a[d][j] < lc)
			lc = a[d][j];
	return lc;
}

void ThemCot(float a[][500], int m, int& n)
{
	n++;
	for (int i = 0; i < m; i++)
	a[i][n - 1] = NhoNhatDong(a, m, n - 1, i);
}