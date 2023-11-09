#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
bool KiemTra(float);
float TinhTong(float[][100], int, int,int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int d;
    cout << "Nhap dong can tinh: ";
    cin >> d;
    cout << "Tong cac so duong la: " << TinhTong(a, m, n,d);
    return 0;
}

void Nhap(float a[][100], int& m, int& n)
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

void Xuat(float a[][100], int m, int n)
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

bool KiemTra(float k)
{
    if (k >0)
        return true;
    return false;
}
float TinhTong(float a[][100], int m, int n, int d)
{
    int s= 0;
    if (d < 0 || d >= m)
    {
        cout << "khong co";
        return 0;
    }

    for (int j = 0; j < n; j++)
    {
        if (KiemTra(a[d][j]))
            s = s + a[d][j];
    }
    return s;
}
