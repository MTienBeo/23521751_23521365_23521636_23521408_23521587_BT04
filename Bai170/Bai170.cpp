#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
int DemCon(float**, int, int, float**, int, int);

int main()
{
	float** a;
	int m, n;
	cout << "\nNhap ma tran A: ";
	Nhap(a, m, n);
	cout << "\nMa Tran A: " << endl;
	Xuat(a, m, n);

	float** b;
	int k, l;
	cout << "\nNhap ma tran B: ";
	Nhap(b, k, l);
	cout << "\nMa Tran B: " << endl;
	Xuat(b, k, l);

	cout << "\nSo lan xuat hien cua A trong B: " << DemCon(a, m, n, b, k, l);

	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
	for (int i = 0; i < k; i++)
		delete[]b[i];
	delete[]b;
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

int DemCon(float** a, int m, int n, float** b, int k, int l)
{
	if (m > k || n > l)
		return 0;
	int dem = 0;
	for (int d = 0; d <= k - m; d++)
		for (int c = 0; c <= l - n; c++)
		{
			int flag = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (b[d + i][c + j] != a[i][j])
						flag = 0;
			if (flag == 1)
				dem++;
		}
	return dem;
}