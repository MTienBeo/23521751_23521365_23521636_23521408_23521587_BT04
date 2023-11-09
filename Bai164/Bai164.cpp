#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void DaoDong(float[][500], int, int, int);
void ChieuGuong(float[][500], int, int);


int main()
{
	float b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Ma tran duoc chieu guong theo truc doc la: \n" ;
	ChieuGuong(b, k, l);
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

void DaoDong(float a[][500], int m, int n, int d)
{
	int dd = 0;
	int cc = n - 1;
	while (dd < cc)
	{
		float temp = a[d][dd];
		a[d][dd] = a[d][cc];
		a[d][cc] = temp;
		dd++;
		cc--;
	}
}

void ChieuGuong(float a[][500], int m, int n)
{
	 for (int i = 0; i < m; i++)
		DaoDong(a, m, n, i);
}