#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float LonNhatCot(float[][500], int, int, int);
void ThemDong(float[][500], int&, int);

int main()
{
	float b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran B mxn: " << endl;
	Xuat(b, k, l);
	cout << "Ma tran moi la: " << endl;
	ThemDong(b, k, l);
	Xuat(b, k, l);
	cout << endl;
	cout << "Ket thuc!!!\n\n\n";
	return 0;
}

void Nhap(float a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
		}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

float LonNhatCot(float a[][500], int m, int n, int c)
{
	float lc = a[0][c];
	for (int i = 0; i < m; i++)
		if (a[i][c] > lc)
			lc = a[i][c];
	return lc;
}

void ThemDong(float a[][500], int& m, int n)
{
	int d = m;
	for (int j = 0; j < n; j++)
		a[d][j] = LonNhatCot(a, m, n, j);
	m++;
}
