#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void TichCot(float[][500], int, int, int);

int main()
{
	float b[500][500];
	int k, l, n;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Nhap cot c: ";
	cin >> n;
	cout << "Tich cac so thuoc doan [0;-1] tren cot " << n << " la: ";
	TichCot(b, k, l, n);
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

void TichCot(float a[][500], int m, int n, int c)
{
	float T = 1;
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] >= -1 && a[i][c] <= 0)
			T = T * a[i][c];
	}
	if (T == 1)
		cout << "Khong co so nao";
	else
		cout << T;
	
}