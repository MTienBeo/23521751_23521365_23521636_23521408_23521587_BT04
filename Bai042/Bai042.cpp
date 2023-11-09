#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool KiemTra(int);
int TinhTong(int[][100], int, int, int);

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int c;
    cout << "Nhap cot can tinh: ";
    cin >> c;
    cout << "Tong cac so co dang la: " << TinhTong(a, m, n, c);
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

bool KiemTra(int k)
{
    if (k < 1)
        return false;
    for (int t = k; t > 1; t = t / 2)
    {
        int du = t % 2;
        if (du != 0)
            return false;
    }
    return true;
}

int TinhTong(int a[][100], int m, int n, int c)
{
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        if (KiemTra(a[i][c]))
            s = s + a[i][c];

    }
    return s;
 }
