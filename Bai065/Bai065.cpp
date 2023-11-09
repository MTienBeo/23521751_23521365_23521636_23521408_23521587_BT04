#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
int DemGiaTri(int**, int, int, int);
bool ktSoDau(int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	int c;
	cout << "\nNhap cot can dem: ";
	cin >> c;
	cout << "\nSo luong chu so dau chan tren cot " << c << " : ";
	cout << DemGiaTri(a, m, n, c);

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

int DemGiaTri(int** a, int m, int n, int c)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		if (ktSoDau(a[i][c]))
			dem++;
	return dem;
}

bool ktSoDau(int n)
{
	int temp = abs(n);
	while (temp > 10)
		temp = temp / 10;
	if (temp % 2 == 0)
		return true;
	return false;
}