#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
int TichLe(int**, int, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	cout << "\nTich gia tri le tren dong chan bang " << TichLe(a, m, n);

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

int TichLe(int** a, int m, int n)
{
	int t = 1;
	for (int i = 0; i < m; i += 2)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 != 0)
				t *= a[i][j];
	return t;
}