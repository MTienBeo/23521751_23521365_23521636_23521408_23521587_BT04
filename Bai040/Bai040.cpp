#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
int TongCot(int**, int, int, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	int c;
	cout << "Nhap cot can tinh: ";
	cin >> c;
	cout << "\nTong cac gia tri le tren cot " << c << " bang " << TongCot(a, m, n, c);

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
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

int TongCot(int** a, int m, int n, int c)
{
	int S = 0;
	for (int i = 0; i < m; i++)
		if (a[i][c] % 2 != 0)
			S += a[i][c];
	return S;
}