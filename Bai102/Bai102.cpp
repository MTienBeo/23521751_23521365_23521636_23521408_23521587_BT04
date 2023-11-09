#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int KiemTra(int [][100],int ,int );

int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    KiemTra(a, m, n);
    int kq = KiemTra(a, m, n);

    if (kq==1)
        cout << "co ton tai";
    else
        cout << "khong ton tai";
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
int KiemTra(int a[][100], int m, int n)
  {
      for (int i = 0; i < m; i++)
      {
          for (int j = 0; j < n; j++)
              if (a[i][j] % 2 != 0)
                  return 1;
      }
      return 0;
  }
