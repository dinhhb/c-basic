#include <stdio.h>
#include <time.h>

unsigned long long int C(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    return C(k, n - 1) + C(k - 1, n - 1);
}
int main()
{
    clock_t start, end;
    start = clock();
    printf("%llu\n", C(30, 41));
    end = clock();
    double time_taken = ((double)(end-start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf\n", time_taken);
    return 0;
}