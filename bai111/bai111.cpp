#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 100

void ImportData(float[][M], int, int, char*);
void PrintMatrix(float[][M], int, int);
int* FindNegativeRow(float[][M], int, int, int*);
void main()
{
    int nRow, nCol;
    float A[N][M];
    int* res;
    int cnt;
    int idx;


    printf("\nNumber of row: ");
    scanf("%d", &nRow);
    printf("\nNumber of column: ");
    scanf("%d", &nCol);
    ImportData(A, nRow, nCol, "A");
    PrintMatrix(A, nRow, nCol);

    res = FindNegativeRow(A, nRow, nCol, &cnt);

    if (!cnt)
        printf("\nMatrix does not have negative row\n");
    else
    {
        printf("\nNegative row in matrix: ");
        for (idx = 0; idx < cnt; idx++)
        {
            printf("%d, ", res[idx] + 1);
        }
    }

    getch();
}

int* FindNegativeRow(float A[][M], int nRow, int nCol, int* cnt)
{
    int iRow, iCol;
    int* pArr = NULL;
    int idx;

    *cnt = 0;

    pArr = (int*)malloc(nRow * sizeof(int));
    if (!pArr)
    {
        return NULL;
    }
    memset(pArr, NULL, nRow * sizeof(int));

    for (iRow = 0; iRow < nRow; iRow++)
    {
        idx = iRow;
        for (iCol = 0; iCol < nCol; iCol++)
        {
            if (A[iRow][iCol] >= 0)
            {
                idx = -1;
                break;
            }
        }
        if (idx != -1)
        {
            pArr[(*cnt)++] = idx;
        }
    }

    return pArr;
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