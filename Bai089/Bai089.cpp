#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float TongCot(float[][500], int, int, int);
float TongNhoNhat(float[][500], int, int);

int main()
{
	float b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Tong cua cot nho nhat la: ";
	cout << TongNhoNhat(b, k, l);
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

float TongCot(float a[][500], int m, int n, int c)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		s = s + a[i][c];
	return s;
}

float TongNhoNhat(float a[][500], int m, int n)
{
	float lc = TongCot(a, m, n, 0);
		for (int j = 0; j < n; j++)
			if (TongCot(a, m, n, j) < lc)
				lc = TongCot(a, m, n, j);
	return lc;
}