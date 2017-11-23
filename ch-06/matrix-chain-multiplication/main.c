#include <stdio.h>
#include <limits.h>

#define N 6

void DPMatrixChain(int *p, int n, int *m, int *s)
{
    int i, j, c, k, q;

    for (i = 1; i <= n; ++i)
    {
        *(m + i * n + i) = 0;
    }
    for (c = 2; c <= n; ++c)
    {
        for (i = 1; i <= n - c + 1; ++i)
        {
            j = i + c - 1;
            *(m + i * n + j) = INT_MAX;
            for (k = i; k <= j - 1; ++k)
            {
                q = *(m + i * n + k) + *(m + (k + 1) * n + j) + p[i - 1] * p[k] * p[j];
                if (q < *(m + i * n + j))
                {
                    *(m + i * n + j) = q;
                    *(s + i * n + j) = k;
                }
            }
        }
    }

    return;
}

void PrintParents(int *s, int n, int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        PrintParents(s, n, i, *(s + i * n + j));
        PrintParents(s, n, *(s + i * n + j) + 1, j);
        printf(")");
    }

    return;
}

int main()
{
    int p[N + 1] = {30, 35, 15, 5, 10, 20, 25};
    int m[(N + 1) * (N + 1)] = {0}, s[(N + 1) * (N + 1)] = {0};

    DPMatrixChain(p, N, m, s);
    PrintParents(s, N, 1, N);

    return 0;
}