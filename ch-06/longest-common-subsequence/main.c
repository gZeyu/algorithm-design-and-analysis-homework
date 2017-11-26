#include <stdio.h>

#define ElemType char
#define LEFTTOP 1
#define TOP 2
#define BOTTOM 3

#define M 7
#define N 6

void LCSLength(ElemType *x, ElemType *y, int m, int n,
               int *c, int *b)
{
    int i, j;

    for (i = 1; i <= m; ++i)
    {
        *(c + i * (n + 1) + 0) = 0;
    }
    for (j = 0; j <= n; ++j)
    {
        *(c + 0 * (n + 1) + j) = 0;
    }

    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (x[i] == y[j])
            {
                *(c + i * (n + 1) + j) = *(c + (i - 1) * (n + 1) + (j - 1)) + 1;
                *(b + i * (n + 1) + j) = LEFTTOP;
            }
            else if (*(c + (i - 1) * (n + 1) + j) >= *(c + i * (n + 1) + (j - 1)))
            {
                *(c + i * (n + 1) + j) = *(c + (i - 1) * (n + 1) + j);
                *(b + i * (n + 1) + j) = TOP;
            }
            else
            {
                *(c + i * (n + 1) + j) = *(c + i * (n + 1) + (j - 1));
                *(b + i * (n + 1) + j) = BOTTOM;
            }
        }
    }

    return;
}

void PrintLCS(int *b, int m, int n, ElemType *x, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (*(b + i * (n + 1) + j) == LEFTTOP)
    {
        PrintLCS(b, m, n, x, i - 1, j - 1);
        printf("%c", x[i]);
    }
    else if (*(b + i * (n + 1) + j) == TOP)
    {
        PrintLCS(b, m, n, x, i - 1, j);
    }
    else
    {
        PrintLCS(b, m, n, x, i, j - 1);
    }
}

int main()
{
    ElemType *x = (ElemType *)" ABCBDAB";
    ElemType *y = (ElemType *)" BDCABA";
    int c[(M + 1) * (N + 1)], b[(N + 1) * (M + 1)];

    LCSLength(x, y, M, N, c, b);
    PrintLCS(b, M, N, x, M, N);

    return 0;
}