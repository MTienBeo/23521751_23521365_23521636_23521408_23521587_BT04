#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
float LonNhat(float**, int, int);
float LonNhatDong(float**, int, int, int);
void LietKe(float**, int, int);

int main()
{
	float** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	cout << "\nCac dong chua gia tri lon nhat: ";
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

float LonNhat(float** a, int m, int n)
{
	float lc = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > lc)
				lc = a[i][j];
	return lc;
}

float LonNhatDong(float** a, int m, int n, int d)
{
	float lc = a[d][0];
	for (int j = 1; j < n; j++)
		if (a[d][j] > lc)
			lc = a[d][j];
	return lc;
}

void LietKe(float** a, int m, int n)
{
	for (int i = 0; i < m; i++)
		if (LonNhat(a, m, n) == LonNhatDong(a, m, n, i))
			cout << fixed << setw(5) << i;
}