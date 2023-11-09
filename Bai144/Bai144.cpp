#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int ktCot(float[][500], int, int, int);
void XoaCot(float[][500], int, int&, int);
void XoaCot(float[][500], int, int&);

int main()
{
	float b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran B mxn: " << endl;
	Xuat(b, k, l);
	cout << "Ma tran moi la: " << endl;
	XoaCot(b, k, l);
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

int ktCot(float a[][500], int m, int n, int c)
{
	int flagAm = 0;
	int flagDuong = 0;
	for (int i = 0; i < m; i++) 
	{
			if (a[i][c] < 0)
				flagAm = true;
			if (a[i][c] > 0)
				flagDuong = 1;;
	}
	if (flagAm == 1 && flagDuong == 1)
		return 1;
	return 0;
}

void XoaCot(float a[][500], int m, int& n, int c)
{
	for (int i = 0; i < m; i++) {
		for (int j = c; j < n - 1; j++) {
			a[i][j] = a[i][j + 1];
		}
	}
	n--;
}

void XoaCot(float a[][500], int m, int& n)
{
	for (int i = n - 1; i >= 0; i--) {
		if (ktCot(a, m, n, i) == 1) {
			XoaCot(a, m, n, i);
		}
	}
}