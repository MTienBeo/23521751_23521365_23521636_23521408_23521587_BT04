#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float NhoNhat(float[][500], int, int);
int DemNhoNhat(float[][500], int, int);

int main()
{
	float b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "So luong gia tri nho nhat trong ma tran la: ";
	cout << DemNhoNhat(b, k, l);
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
			cout << fixed << setw(10) << setprecision(2) << a[i][j];
		cout << endl;
	}
}

float NhoNhat(float a[][500], int m, int n)
{
	float lc = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j=0; j<n;j++)
			if (a[i][j] < lc)
				lc = a[i][j];
	return lc;
}

int DemNhoNhat(float a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == NhoNhat(a, m, n))
				dem++;
	return dem;

}