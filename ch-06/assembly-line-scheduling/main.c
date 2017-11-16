#include <stdio.h>

#define N 6

void DPFastestWay(int **a, int **t, int *e, int *x, int n,
                  int **f, int **l, int *fOut, int *lOut)
{
    int j;

    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];
    for (j = 1; j < n; ++j)
    {
        if (f[0][j - 1] + a[0][j] <= f[1][j - 1] + t[1][j - 1] + a[1][j])
        {
            f[0][j] = f[0][j - 1] + a[0][j];
            l[0][j] = 0;
        }
        else
        {
            f[0][j] = f[1][j - 1] + t[1][j - 1] + a[1][j];
            l[0][j] = 1;
        }
    }
    for (j = 1; j < n; ++j)
    {
        if (f[1][j - 1] + a[1][j] <= f[0][j - 1] + t[0][j - 1] + a[0][j])
        {
            f[1][j] = f[1][j - 1] + a[1][j];
            l[0][j] = 1;
        }
        else
        {
            f[1][j] = f[0][j - 1] + t[0][j - 1] + a[0][j];
            l[0][j] = 0;
        }
    }
    if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1])
    {
        *fOut = f[0][n - 1] + x[0];
        *lOut = 0;
    }
    else
    {
        *fOut = f[1][n - 1] + x[1];
        *lOut = 1;
    }

    return;
}

int main()
{
    int a[][N] = {7, 9, 3, 4, 8, 4,
                  8, 5, 6, 4, 5, 7};
    return 0;
}