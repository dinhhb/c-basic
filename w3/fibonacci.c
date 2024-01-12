#include <stdio.h>
#include <time.h>

unsigned long f(int n)
{
    if (n <= 1)
        return 1;
    return f(n - 1) + f(n - 2);
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