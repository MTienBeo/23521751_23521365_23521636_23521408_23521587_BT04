#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktCon(float[][100], int, int, int, int);
void ConCuoi(float[][100], int, int, int&, int&);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int vtd, vtc;
    ConCuoi(a, m, n, vtd, vtc);

    if (vtd != -1 && vtc != -1)
    {
        cout << "Ma tran con 3x3 toan am cuoi cung:" << endl;
        for (int i = vtd; i < vtd + 3; i++)
        {
            for (int j = vtc; j < vtc + 3; j++)
                cout << setw(8) << a[i][j];
            cout << "\n";
        }

    }
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

int ktCon(float a[][100], int m, int n, int vtd, int vtc)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[vtd + i][vtc + j] >= 0)
                return 0;
        }
    }
    return 1;
}

void ConCuoi(float a[][100], int m, int n, int& vtd, int& vtc)
{
    for (vtd = m - 3; vtd >= 0; vtd--)
    {
        for (vtc = n - 3; vtc >= 0; vtc--)
        {
            if (ktCon(a, m, n, vtd, vtc) == 1)
                return;
        }
    }
    vtd = vtc = -1;
}



