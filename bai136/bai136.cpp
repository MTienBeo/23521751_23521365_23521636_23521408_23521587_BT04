#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void XuatNguyenToTang(int[][500], int, int);
void XuatNguyenToTang(int a[][500],
    int m, int n)
{
    int b[500];
    int k;
    int i, j;
    k = 0;
    for (i = 0;i < m;i++)
        for (j = 0;j < n;j++)
            if (ktnt(a[i][j]) == 1)
                b[k++] = a[i][j];

    for (i = 0;i <= k - 2;i++)
        for (j = i + 1;j <= k - 1;j++)
            if (b[i] > b[j])
                HoanVi(b[i], b[j]);

    for (i = 0;i < k;i++)
        cout << setw(8) << b[i];
}
