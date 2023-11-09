#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 100
#define M 100

void ImportData(int[][M], int, int, char*);
void PrintMatrix(int[][M], int, int, char);
int CntMinInMatrix(int[][M], int, int);


void main()
{
    int aRow, aCol;
    int A[N][M];
    int res;

    printf("\nNumber of row: ");
    scanf("%d", &aRow);
    printf("\nNumber of column: ");
    scanf("%d", &aCol);

    ImportData(A, aRow, aCol, "A");
    PrintMatrix(A, aRow, aCol, 'A');

    printf("\nThe number of minimum value in matrix: %d", CntMinInMatrix(A, aRow, aCol));

    getch();
}

int CntMinInMatrix(int A[][M], int aRow, int aCol)
{
    int iARow, iACol;
    int cnt = 0;
    int min;

    //1. Find minimum value in matrix
    min = A[0][0];
    for (iARow = 0; iARow < aRow; iARow++)
    {
        for (iACol = 0; iACol < aCol; iACol++)
        {
            if (min > A[iARow][iACol])
            {
                min = A[iARow][iACol];
            }
        }
    }

    //2. Count the number of minimum value
    for (iARow = 0; iARow < aRow; iARow++)
    {
        for (iACol = 0; iACol < aCol; iACol++)
        {
            if (min == A[iARow][iACol])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

void ImportData(int Matrix[][M], int nRow, int nCol, char* nameMatrix)
{
    int iRow, iCol;
    for (iRow = 0; iRow < nRow; iRow++)
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\n%s[%d][%d] = ", nameMatrix, iRow, iCol);
            scanf("%d", &Matrix[iRow][iCol]);
        }
}

void PrintMatrix(int Matrix[][M], int nRow, int nCol, char name)
{
    int iRow, iCol;
    printf("\n%c = ", name);
    for (iRow = 0; iRow < nRow; iRow++)
    {
        printf("\n");
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\t%d\t", Matrix[iRow][iCol]);
        }
    }
}