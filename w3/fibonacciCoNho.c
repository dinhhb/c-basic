#include <stdio.h>
#include <time.h>
#define MAX 100

int M[MAX];

unsigned long f(int n)
{
    if (n <= 1)
        M[n] = 1;
    else if (M[n] == 0)
        M[n] = f(n - 1) + f(n - 2);
    return M[n];
}
int main()
{
    clock_t start, end;
    start = clock();
    for (int i = 0; i <= 45; i++){
        printf("f(%d) = %lu\n", i, f(i));
    }
    end = clock();
    double time_taken = ((double)(end -start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf\n", time_taken);

    return 0;
}