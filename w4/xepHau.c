#include <stdio.h>

int x[20];

void printSolution(int n){
    for (int k = 0; k < n; k++){
        printf("%X", x[k]);
    }
    printf("\n");
}

int check(int v, int k)
{
    // kiểm tra xem v có thể gán được
    // cho x[k] không
    for (int i = 1; i <= k - 1; i++)
    {
        if (x[i] == v)
            return 0;
        if (x[i] + i == v + k)
            return 0;
        if (x[i] - i == v - k)
            return 0;
    }
    return 1;
}

void TRY(int k, int n)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k == n)
                printSolution(n);
            else
                TRY(k + 1, n);
        }
    }
}
void main()
{
    int n = 4;
    TRY(1, n);
}
