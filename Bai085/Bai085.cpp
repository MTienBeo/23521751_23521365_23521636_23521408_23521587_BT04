#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
bool ktChinhPhuong(int);
int ChinhPhuongDau(int**, int, int);
int ChinhPhuongLonNhat(int**, int, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	cout << "\nSo chinh phuong lon nhat : " << ChinhPhuongLonNhat(a, m, n);
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

bool ktChinhPhuong(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	for (int i = 1; i * i <= n; i++)
		if (i * i == n)
			return 1;
	return 0;
}

int ChinhPhuongDau(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktChinhPhuong(a[i][j]))
				return a[i][j];
	return -1;
}

int ChinhPhuongLonNhat(int** a, int m, int n)
{
	int lc = ChinhPhuongDau(a, m, n);
	if (lc == -1)
		return -1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > lc && ktChinhPhuong(a[i][j]))
				lc = a[i][j];
	return lc;
}