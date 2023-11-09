#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
void LietKeDong(int**, int, int, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	int d;
	cout << "Nhap dong can tinh: ";
	cin >> d;
	cout << "\nCac gia tri chan tren dong " << d << " : ";
	LietKeDong(a, m, n, d);

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

void LietKeDong(int** a, int m, int n, int d)
{
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 == 0)
			cout << setw(5) << a[d][j];
}