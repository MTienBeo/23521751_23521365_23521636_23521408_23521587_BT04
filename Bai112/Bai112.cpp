#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktDong(float[][100], int, int, int);
void LietKe(float[][100], int, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    LietKe(a, m, n);
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

int ktDong(float a[][100], int m, int n, int d)
{
    for (int j = 0; j < n; j++)
    {
        if (a[d][j] >= 0)
            return 0;
    }
    return 1;
}

void LietKe(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (ktDong(a, m, n, i) == 1)
            cout << "Dong " << i << " co toan so am " << endl;
    }
}