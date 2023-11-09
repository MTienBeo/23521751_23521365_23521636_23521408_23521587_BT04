#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 100
#define M 100

void ImportData(float[][M], int, int, char*);
void PrintMatrix(float[][M], int, int);
int CntMinMaxInMatrix(float[][M], int, int);


void main()
{
    int nRow, nCol;
    float average;
    float A[N][M];

    printf("\nNumber of row: ");
    scanf("%d", &nRow);
    printf("\nNumber of column: ");
    scanf("%d", &nCol);

    ImportData(A, nRow, nCol, "A");
    PrintMatrix(A, nRow, nCol);

    printf("\nThe number of minimum/maximum elements in matrix: %d",
        CntMinMaxInMatrix(A, nRow, nCol));

    getch();
}

int CntMinMaxInMatrix(float A[][M], int nRow, int nCol)
{
    int iRow, iCol;
    int cnt = 0;
    int flg = 0; // 0: init, 1: maximum, 2: minimum

    for (iRow = 0; iRow < nRow; iRow++)
    {
        for (iCol = 0; iCol < nCol; iCol++)
        {
            flg = 0; //init
            // Compare with previous element in column
            if (iRow - 1 >= 0)
            {
                if (A[iRow][iCol] > A[iRow - 1][iCol])
                    flg = 1;
                else if (A[iRow][iCol] < A[iRow - 1][iCol])
                    flg = 2;
                else
                    continue;
            }
            // Compare with next element in column
            if (iRow + 1 < nRow)
            {
                if (A[iRow][iCol] > A[iRow + 1][iCol] && (flg == 1 || flg == 0))
                    flg = 1;
                else if (A[iRow][iCol] < A[iRow + 1][iCol] && (flg == 2 || flg == 0))
                    flg = 2;
                else
                    continue;
            }
            // Compare with previous element in row
            if (iCol - 1 >= 0)
            {
                if (A[iRow][iCol] > A[iRow][iCol - 1] && (flg == 1 || flg == 0))
                    flg = 1;
                else if (A[iRow][iCol] < A[iRow][iCol - 1] && (flg == 2 || flg == 0))
                    flg = 2;
                else
                    continue;

            }
            // Compare with next element in row
            if (iCol + 1 < nCol)
            {
                if (A[iRow][iCol] > A[iRow][iCol + 1] && (flg == 1 || flg == 0))
                    flg = 1;
                else if (A[iRow][iCol] < A[iRow][iCol + 1] && (flg == 2 || flg == 0))
                    flg = 2;
                else
                    continue;
            }
            cnt++;
        }
    }

    return cnt;
}

void ImportData(float Matrix[][M], int nRow, int nCol, char* nameMatrix)
{
    int iRow, iCol;
    for (iRow = 0; iRow < nRow; iRow++)
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\n%s[%d][%d] = ", nameMatrix, iRow, iCol);
            scanf("%f", &Matrix[iRow][iCol]);
        }
}

void PrintMatrix(float Matrix[][M], int nRow, int nCol)
{
    int iRow, iCol;
    printf("\nA = ");
    for (iRow = 0; iRow < nRow; iRow++)
    {
        printf("\n");
        for (iCol = 0; iCol < nCol; iCol++)
        {
            printf("\t%.2f\t", Matrix[iRow][iCol]);
        }
    }
}
