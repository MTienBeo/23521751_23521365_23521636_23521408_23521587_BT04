#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
void LietKeCot(int**, int, int, int);
bool ktDang5m(int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

	int c;
	cout << "Nhap cot can tinh: ";
	cin >> c;
	cout << "\nCac so dang 5 mu m tren cot " << c << " : ";
	LietKeCot(a, m, n, c);

	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
	return 0;
}

void Nhap(int**& a, int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}

void Xuat(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
}

void LietKeCot(int** a, int m, int n, int c)
{
	for (int i = 0; i < m; i++)
		if (ktDang5m(a[i][c]))
			cout << setw(5) << a[i][c];
}

bool ktDang5m(int n)
{
	int t = n;
	bool flag = true;
	if (t < 1)
		return 0;
	while (t > 1)
	{
		if (t % 5 != 0)
			flag = false;
		t = t / 5;
	}
	return flag;
}