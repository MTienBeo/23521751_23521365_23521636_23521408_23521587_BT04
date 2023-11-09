#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void HoanVi(float&, float&);
void SapTangZicZac(float**, int, int);

int main()
{
	float** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	cout << "\Ma tran sau khi sap tang ziczac: "<<endl;
	SapTangZicZac(a, m, n);
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

void SapTangZicZac(float** a, int m, int n)
{
	float b[500];
	int k;
	int i, j;

	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			b[k++] = a[i][j];

	for (i = 0; i <= k - 2; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (b[i] > b[j])
				HoanVi(b[i], b[j]);

	k = 0;
	for (int cheo = 0; cheo <= m + n - 2; cheo++)
	{
		if (cheo % 2 != 0)
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (i + j == cheo)
						a[i][j] = b[k++];
		if (cheo % 2 == 0)
			for (int i = m - 1; i >= 0; i--)
				for (int j = n - 1; j >= 0; j--)
					if (i + j == cheo)
						a[i][j] = b[k++];
	}
}