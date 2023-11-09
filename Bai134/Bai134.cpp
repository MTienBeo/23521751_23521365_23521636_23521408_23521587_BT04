#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
void HoanVi(int&, int&);
void XuatChanGiam(int[][500], int, int);

int main()
{
	int b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Cac gia tri chan trong ma tran la: ";
	XuatChanGiam(b, k, l);
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
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % (200 + 1) - 100;
		}
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(8) << a[i][j];
		cout << endl;
	}
}

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void XuatChanGiam(int a[][500], int m, int n)
{
	int b[500];
	int k;
	int i, j;
	
	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				b[k++] = a[i][j];
	
	for (i = 0; i <= k - 2; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (b[i] < b[j])
				HoanVi(b[i], b[j]);
	
	for (i = 0; i < k; i++)
		cout << setw(8) << b[i];
}
