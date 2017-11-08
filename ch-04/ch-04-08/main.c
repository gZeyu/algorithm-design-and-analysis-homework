#include <stdio.h>

#define MAX 1024
void printfArray(const int *A, int n)
{
    int i;

    for (i = 1; i <= n; ++i)
    {
        printf("%d", A[i]);
    }
    printf("\n");

    return;
}

void Perm2(int *P, int n, int m) //非字典序
{
    int j, tmp;

    if(m == 0)
    {
        printfArray(P, n);
    }
    else
    {
        for(j = 1; j <= n; ++j)
        {
            if (P[j] == 0)
            {
                P[j] = m;
                Perm2(P, n, m - 1);
                P[j] = 0;
            }
        }
    }

    return;
}

void GeneratingPerm2(int *P, int n)
{
    int j;
    for (j = 1; j <= n; ++j)
    {
        P[j] = 0;
    }
    Perm2(P, n, n);
    return;
}
void Perm22(int *P, int n, int m) //非字典序
{
    int j, tmp;
    if(m == 0)
    {
        printfArray(P, n);
    }
    else
    {
        for(j = n; j >= 1; --j)
        {
            if (P[j] == 0)
            {
                P[j] = m;
                Perm22(P, n, m - 1);
                P[j] = 0;
            }
        }
    }

    return;
}

void GeneratingPerm22(int *P, int n)
{
    int j;
    for (j = 1; j <= n; ++j)
    {
        P[j] = 0;
    }
    Perm22(P, n, n);
    return;
}
int main()
{
    int P[MAX];
    
    printf("GeneratingPerm2\n");
    GeneratingPerm2(P, 4);
    printf("GeneratingPerm22\n");
    GeneratingPerm22(P, 4);
    return 0;
}