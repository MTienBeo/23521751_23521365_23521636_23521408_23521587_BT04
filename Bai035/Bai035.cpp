#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
bool ktDoiXung(int);
int TongDong(int**, int, int, int);

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
	cout << "\nTong cac so doi xung tren dong " << d << " bang " << TongDong(a, m, n, d);

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

bool ktDoiXung(int n)
{
	int t = abs(n);
	int dn = 0;
	while (t > 0)
	{
		dn = dn * 10 + t % 10;
		t = t / 10;
	}
	if (dn == abs(n))
		return true;
	return false;
}

int TongDong(int** a, int m, int n, int d)
{
	int S = 0;
	for (int j = 0; j < n; j++)
		if (ktDoiXung(a[d][j]))
			S += a[d][j];
	return S;
}