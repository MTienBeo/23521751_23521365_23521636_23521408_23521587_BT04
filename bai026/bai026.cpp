#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
void TongChinhPhuong(int[][500], int, int, int);

int main()
{
	int b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Xuat Ma tran data01.inp: ";
	cout << endl;
	cout << "Ket thuc!!!\n\n\n";
	return 0;
}

void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % (201) - 100;
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << fixed << setw(10) << setprecision(3) << a[i][j];;
		}
		cout << endl;
	}
}

int TongChinhPhuong(int a[][500], int m, int n, int d)
{
	int s = 0;
	for (int j = 0;j <= n - 2;j++)
		if (ktChinhPhuong(a[0][j]))
			s = s + a[0][j];
	for (int i = 0;i <= m - 2;i++)
		if (ktChinhPhuong(a[i][n - 1]))
			s = s + a[i][n - 1];
	for (int j = n - 1;j > 1;j--)
		if (ktChinhPhuong(a[m - 1][j]))
			s = s + a[m - 1][j];
	for (int i = m - 1;i > 1;i--)
		if (ktChinhPhuong(a[i][0]))
			s = s + a[i][0];
	return s;
}