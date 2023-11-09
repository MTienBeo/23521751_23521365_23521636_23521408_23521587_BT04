#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
float TongDong(float**, int, int, int);
float TongLonNhat(float**, int, int);
void LietKe(float**, int, int);

int main()
{
	float** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	cout << "\nCac dong co tong lon nhat: ";
	LietKe(a, m, n);

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

float TongDong(float** a, int m, int n, int d)
{
	float S = 0;
	for (int j = 0; j < n; j++)
		S += a[d][j];
	return S;
}

float TongLonNhat(float** a, int m, int n)
{
	float lc = TongDong(a, m, n, 0);
	for (int i = 1; i < m; i++)
		if (TongDong(a, m, n, i) > lc)
			lc = TongDong(a, m, n, i);
	return lc;
}

void LietKe(float** a, int m, int n)
{
	for (int i = 0; i < m; i++)
		if (TongDong(a, m, n, i) == TongLonNhat(a, m, n))
			cout << fixed << setw(5) << i;
}