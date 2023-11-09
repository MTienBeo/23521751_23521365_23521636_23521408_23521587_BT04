#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktHoanThien(int);
void LietKe(int[][100], int, int, int);

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int d;
    cout << "Nhap dong can tim so hoan thien: ";
    cin >> d;
    cout << "Cac so hoan thien tren dong " << d << " la: ";
    LietKe(a, m, n, d);
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

bool ktHoanThien(int k)
{
    if (k <= 0)
        return false;
    int sum = 0;
    for (int i = 1; i <= k / 2; i++)
    {
        if (k % i == 0)
            sum += i;
    }
    return sum == k;
}

void LietKe(int a[][100], int m, int n, int d)
{
    if (d < 0 || d >= m)
    {
        cout << "khong co";
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (ktHoanThien(a[d][j]))
        {
            cout << setw(8) << a[d][j];
        }
    }
}