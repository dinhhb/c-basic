#include <stdio.h>
#define N 100

int n, M, T;
int x[N];

void solution()
{
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

int check(int v, int k)
{
    if (k == n)
        return T + v == M;
    return 1;
}

void Try(int k)
{
    for (int v = 1; v <= M - T - (n - k); v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            T += v;
            if (k == n)
                solution();
            else
                Try(k + 1);
            T -= v;
        }
    }
}
int main()
{
    n = 3;
    M = 5;
    T = 0;
    Try(1);
}