#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 100
#define M 100

void ImportData(float[][M], int, int, char*);
void PrintMatrix(float[][M], int, int);
bool isDescendingMatrix(float[][M], int, int);
void main()
{
    int nRow, nCol;
    float A[N][M];
    bool res;

    printf("\nNumber of row: ");
    scanf("%d", &nRow);
    printf("\nNumber of column: ");
    scanf("%d", &nCol);
    ImportData(A, nRow, nCol, "A");
    PrintMatrix(A, nRow, nCol);

    res = isDescendingMatrix(A, nRow, nCol);

    if (res)
        printf("\nMatrix is descending\n");
    else
        printf("\nMatrix is not descending\n");

    getch();
}

bool isDescendingMatrix(float A[][M], int nRow, int nCol)
{
    int iRow, iCol;

    // Check descending row
    for (iRow = 0; iRow < nRow; iRow++)
    {
        for (iCol = 0; iCol < nCol - 1; iCol++)
        {
            if (A[iRow][iCol] > A[iRow][iCol + 1])
                continue;
            else
                return false;
        }
    }

    // Check descending column
    for (iCol = 0; iCol < nCol; iCol++)
    {
        for (iRow = 0; iRow < nRow - 1; iRow++)
        {
            if (A[iRow][iCol] > A[iRow + 1][iCol])
                continue;
            else
                return false;
        }
    }

    return true;
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