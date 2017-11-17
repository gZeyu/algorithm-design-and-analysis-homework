#include <stdio.h>

#define N 6

void DPFastestWay(int a[][N], int t[][N], int *e, int *x, int n,
                  int f[][N], int l[][N], int *fOutPtr, int *lOutPtr)
{
    int j;

    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];
    for (j = 1; j < n; ++j)
    {
        if (f[0][j - 1] + a[0][j] <= f[1][j - 1] + t[1][j - 1] + a[0][j])
        {
            f[0][j] = f[0][j - 1] + a[0][j];
            l[0][j] = 0;
        }
        else
        {
            f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
            l[0][j] = 1;
        }
        if (f[1][j - 1] + a[1][j] <= f[0][j - 1] + t[0][j - 1] + a[1][j])
        {
            f[1][j] = f[1][j - 1] + a[1][j];
            l[1][j] = 1;
        }
        else
        {
            f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
            l[1][j] = 0;
        }
    }
    if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1])
    {
        *fOutPtr = f[0][n - 1] + x[0];
        *lOutPtr = 0;
    }
    else
    {
        *fOutPtr = f[1][n - 1] + x[1];
        *lOutPtr = 1;
    }

    return;
}

void printStation(int l[][N], int lOut, int n)
{
    int i, j;

    i = lOut;
    printf("line %d, station %d\n", i, n);
    for (j = n - 1; j > 0; --j)
    {
        i = l[i][j];
        printf("line %d, station %d\n", l[i][j], j);
    }

    return;
}

int main()
{
    

    int a[2][N] = {7, 9, 3, 4, 8, 4,
                  8, 5, 6, 4, 5, 7};
    int t[2][N] = {2, 3, 1, 3, 4, 3,
                  2, 1, 2, 2, 1, 2};
    int e[2] = {2, 4};
    int x[2] = {3, 2};
    int n = N;
    int f[2][N], l[2][N], fOut, lOut;

    DPFastestWay(a, t, e, x, n, 
                 f, l, &fOut, &lOut);
    printStation(l, lOut, n);

    return 0;
}