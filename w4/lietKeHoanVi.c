#include <stdio.h>
#include <stdbool.h>

bool m[20] = {0};
int x[20];

void printSolution(int n){
    for (int k = 0; k < n; k++){
        printf("%d", x[k]);
    }
    printf("\n");
}

void TRY(int i, int n)
{
    for (int v = 1; v <= n; v++)
    {
        if (!m[v])
        {
            x[i - 1] = v;
            m[v] = true; // đánh dấu
            if (i == n)
                printSolution(n);
            else
                TRY(i + 1, n);
            m[v] = false; // khôi phục
        }
    }
}
void main()
{
    int n = 5;
    for (int v = 1; v <= n; v++)
        m[v] = false;
    TRY(1, n);
}