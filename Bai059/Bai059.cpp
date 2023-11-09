#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int TanSuat(float[][500], int, int, float);

int main()
{
	float b[500][500];
	int k, l;
	float n;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Nhap gia tri x: ";
	cin >> n;
	cout << "Tan suat xuat hien cua gia tri " << n <<" la: ";
	cout << TanSuat(b, k, l,n);
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


int TanSuat(float a[][500], int m, int n, float x)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == x)
				dem++;
	return dem;
}