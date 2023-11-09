#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

void TaoMaTran(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void Xuat(string, float[][500], int, int);

int main()
{
    float a[100][500];
    int m, n;
    TaoMaTran(a, m, n);
    Xuat(a, m, n);
    return 0;
}

void TaoMaTran(float a[][500], int& m, int& n)
{
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
        }
    }
}

void Xuat(float a[][500], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(10) << a[i][j];
        cout << "\n";
    }
}
void Xuat(string filename, float a[][500],
    int m, int n)
{
    ofstream fo(filename);
    fo << setw(10) << setprecision(5) << m;
    fo << setw(10) << setprecision(5) << n;
    fo << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fo << setw(10);
            fo << setprecision(5);
            fo << a[i][j];
        }
        fo << "\n";
    }
}
