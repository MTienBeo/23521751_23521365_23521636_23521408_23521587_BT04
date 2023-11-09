#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
float TongCot(int[][500], int, int, int);

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

float TongCot(int a[][500], int m, int n, int c)
{
	float s = 0;
	for (int i = 0;i < m - 2;i++)
		if (ktChinhPhuong(a[i][n - 1]))
			s = s + a[i][n - 1];
	return s;
}