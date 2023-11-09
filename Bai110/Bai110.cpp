#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
bool ktNguyenTo(int);
bool ktDong(int** a, int, int, int);
void LietKe(int**, int, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	cout << "\nCac dong co chua so nguyen to : ";
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

bool ktNguyenTo(int n)
{
	if (n <= 1)
		return 0;
	int dem = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			dem++;
	if (dem == 2)
		return 1;
	return 0;
}

bool ktDong(int** a, int m, int n, int d)
{
	for (int j=0;j<n;j++)
		if (ktNguyenTo(a[d][j]))
			return 1;
	return 0;
}

void LietKe(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i))
			cout << setw(5) << i;
}