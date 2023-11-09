#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void HoanVi(float&, float&);
void SapCotGiam(float**, int, int, int);

int main()
{
	float** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	int c;
	cout << "\nNhap cot can sap xep: ";
	cin >> c;
	SapCotGiam(a, m, n, c);
	cout << "\nMa tran sau khi sap giam cot " << c << " : " << endl;;
	Xuat(a, m, n);

	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
	return 0;
}

void Nhap(float**& a, int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	a = new float* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new float[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}

void Xuat(float** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setprecision(2) << setw(10) << a[i][j];
		cout << endl;
	}
}

void HoanVi(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

void SapCotGiam(float** a, int m, int n, int c)
{
	for (int i = 0; i <= m - 2; i++)
		for (int j = i + 1; j <= m - 1; j++)
			if (a[i][c] < a[j][c])
				HoanVi(a[i][c], a[j][c]);
}