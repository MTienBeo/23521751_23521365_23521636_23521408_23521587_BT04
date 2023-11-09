#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktChinhPhuong(int);
int SoLuong(int[][100], int, int);

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    cout << "so luong so chinh phuong tren bien la: " << SoLuong(a, m, n);
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
bool ktChinhPhuong(int k)
{
    if (k <= 1)
        return false;
    for (int i = 1; i <=k; i++)
    {
        if (i * i == k)
            return true;
    }
    return false;
}
int SoLuong(int a[][100], int m, int n)
{
    int dem = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (ktChinhPhuong(a[i][j]) && (i == 0 || i == (m - 1) || j == 0 || j == (n - 1)))
                dem++;
    }
    return dem;
}
