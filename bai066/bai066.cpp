#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 100
#define M 100

void ImportData(float[][M], int, int, char*);
void PrintMatrix(float[][M], int, int);
int CntEAtBoundInMatrix(float[][M], int, int);


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

    printf("\nThe number of positive elements at boundary of matrix: %d",
        CntEAtBoundInMatrix(A, nRow, nCol));

    getch();
}

int CntEAtBoundInMatrix(float A[][M], int nRow, int nCol)
{
    int iRow, iCol;
    int cnt = 0;

    for (iRow = 0; iRow < nRow; iRow++)
    {
        for (iCol = 0; iCol < nCol; iCol++)
        {
            if (A[iRow][iCol] > 0 &&
                (iRow == 0 || iCol == 0 || iRow == nRow - 1 || iCol == nCol - 1))
            {
                cnt++;
            }
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