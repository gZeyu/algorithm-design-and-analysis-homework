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

void Perm1(int *P, int n, int m) //非字典序
{
    int j, tmp;

    if(m == n)
    {
        printfArray(P, n);
    }
    else
    {
        for(j = m; j <= n; ++j)
        {
            tmp = P[j];
            P[j] = P[m];
            P[m] = tmp;
            Perm1(P, n, m + 1);
            tmp = P[j];
            P[j] = P[m];
            P[m] = tmp;
        }
    }

    return;
}

void GeneratingPerm1(int *P, int n)
{
    int j;
    for (j = 1; j <= n; ++j)
    {
        P[j] = j;
    }
    Perm1(P, n, 1);
    return;
}

void Perm12(int *V, int *O, const int *P, int n, int m) //字典序
{
    int j;

    if (m > n)
    {
        printfArray(O, n);
    }
    else
    {
        for (j = 1; j <= n; ++j)
        {
            if (V[P[j]] == 0)
            {
                O[m] = P[j];
                V[P[j]] = 1;
                Perm12(V, O, P, n,  m + 1);
                V[P[j]] = 0;
            }
        } 

    }

    return;
}

void GeneratingPerm12(int *P, int n)
{
    int V[MAX] = {0};
    int O[MAX];
    int j;

    for (j = 1; j <= n; ++j)
    {
        P[j] = j;
    }
    Perm12(V, O, P, n, 1);
    
}
int main()
{
    int P[MAX];
    
    printf("GeneratingPerm1\n");
    GeneratingPerm1(P, 3);
    printf("GeneratingPerm12\n");
    GeneratingPerm12(P, 4);

    return 0;
}