#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(string, float[][500], int&, int&);
void Xuat(float[][500], int, int);

int main()
{
	float b[500][500];
	float k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Xuat Ma tran data01.inp: ";
	cout << endl;
	cout << "Ket thuc!!!\n\n\n";
	return 0;
}

void Nhap(string filename, float a[][500], int m, int n)
{
	ifstream fi(filename);
	fi >> setw(8) << m;
	fi >> setw(8) << n;
	fi >> "\n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			fi >> a[i][j];
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << fixed << setw(10) << setprecision(3) << a[i][j];;
		}
		cout << endl;
	}
}
