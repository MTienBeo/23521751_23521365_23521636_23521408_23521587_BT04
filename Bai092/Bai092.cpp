#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int DemDong(int[][100], int, int, int);
int DemLonNhat(int[][100], int, int);
void LietKe(int [][100], int, int);

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    LietKe(a, m, n);
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
int DemDong(int a[][100], int m, int n, int d)
{
    int dem = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[d][j] % 2 == 0)
            dem++;
    }
    return dem;
}

int DemLonNhat(int a[][100], int m,int n)
{
    int lc = DemDong(a, m, n, 0);
    for (int i = 0; i < m; i++)
    {
        if (DemDong(a, m, n, i) > lc)
            lc = DemDong(a, m, n, i);
    }
    return lc;

}

void LietKe(int a[][100], int m, int n)
{

    int demMax = DemLonNhat(a, m, n);
    for (int i = 0; i < m; i++)
    {
        if (DemDong(a, m, n, i) == demMax)
            cout << "Dong " << i << "co nhieu so chan nhat " << endl;
    }
}