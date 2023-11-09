#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void SapTang(float[][500], int, int);

int main()
{
	float b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);

	cout << "Mang sau khi sap xep la: " << endl;
	SapTang(b, k, l);
	Xuat(b, l, l);
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

void SapTang(float a[][500], int m, int n)
{
	float b[500];
	int k;
	int i, j;

	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			b[k++] = a[i][j];

	for (i=0; i<=k-2;i++)
		for (j=0; j<=k-1;j++)
			if (b[i] < b[j])
			{
				float temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}

	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a[i][j] = b[k++];
}