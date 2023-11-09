#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktToanLe(int);
int SoLuong(int[][100], int, int,int);

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int d;
    cout << "Nhap dong can tinh: ";
    cin >> d;
    cout << "so luong so toan le la: " << SoLuong(a, m, n,d);
    return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

void Xuat(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << "\n";
    }
}

bool ktToanLe(int k)
{
    if (k == 0)
        return false;
    int t = abs(k);
    int dv;
    while (t != 0)
    {
        dv = t % 10;
        if (dv % 2 == 0)
            return false;
        t = t / 10;
    }
    return true;
}

int SoLuong(int a[][100], int m, int n, int d)
{
    int dem = 0;
    for (int j = 0; j < n; j++)
    {
        if (ktToanLe(a[d][j]))
            dem++;
    }
    return dem;


}