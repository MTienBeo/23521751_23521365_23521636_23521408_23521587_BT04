#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int ChanDau(int[][100], int, int);
int ChanLonNhat(int[][100], int, int);

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    cout << "so chan lon nhat la: " <<ChanLonNhat(a, m, n);
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

int ChanDau(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2 == 0)
                return a[i][j];
    }
    return -1;
}
int ChanLonNhat(int a[][100], int m, int n)
{
    int lc = ChanDau(a, m, n);
    if (lc == -1)
        return -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2 == 0 && a[i][j] > lc)
                lc = a[i][j];
    }
    return lc;

}