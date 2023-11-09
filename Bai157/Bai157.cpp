#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void DichTraiDong(float[][100], int, int,int);
void DichTrai(float[][100], int, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int c;
    cout << "Nhap cot can chuyen: ";
    cin >> c;
    DichTrai(a, m, n);
    cout << "Ma tran sau khi sap xep la: " << endl;
    Xuat(a, m, n);
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

void DichTraiDong(float a[][100], int m, int n, int d)
{
    float temp = a[d][0];
    for (int j = 0; j <=n-2; j++)
        a[d][j] = a[d][j + 1];
    a[d][n - 1] = temp;
}

void DichTrai(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
        DichTraiDong(a, m, n, i);
}
