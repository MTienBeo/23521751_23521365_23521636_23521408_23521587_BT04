#include <iostream>
#include <iomanip>
using namespace std;

void TaoMaTran(int[][500], int&, int&);
void Xuat(int[][500], int, int);
void Xuat(string, int[][500], int, int);

int main()
{
	int b[500][500];
	int k, l;
	TaoMaTran(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Xuat Ma tran data01.inp: ";
	cout << endl;
	cout << "Ket thuc!!!\n\n\n";
	return 0;
}

void TaoMaTran(int a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % (201) - 100;
}

void Xuat(int a[][500], int m, int n)
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

void Xuat(string filename, int a[][500], int m, int n)
{
	ofstream fo(filename);
	fo << setw(8) << m;
	fo << setw(8) << n;
	fo << "\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			fo << setw(8) << a[i][j];
		fo << "\n";
	}
}


