#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void DeleteRowColumn(int a[][20], int& m, int& n, int iRow, int iColumn)
{
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
        {
            if (i < iRow && j >= iColumn) //V�ng ph�a tr�n b�n ph?i
                a[i][j] = a[i][j + 1];
            else if (i >= iRow && j < iColumn) //V�ng ph�a d??i b�n tr�i
                a[i][j] = a[i + 1][j];
            else if (i >= iRow && j >= iColumn) //V�ng ph�a d??i b�n ph?i
                a[i][j] = a[i + 1][j + 1];
        }
    m--;
    n--;
}