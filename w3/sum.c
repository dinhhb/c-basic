#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int recursiveSum(int n) {
    if (n == 0) {
        return 0; // Base case: sum of 0 elements is 0
    } else {
        return n + recursiveSum(n - 1); // Recursive case: sum of n and sum of (n-1) elements
    }
}

long long int iterativeSum(int n) {
    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    // Calculate sum using recursion
    start = clock();
    long long int recursiveResult = recursiveSum(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Recursive Sum (1 to %d): %lld\n", n, recursiveResult);
    printf("Recursive Execution Time: %.6f seconds\n", cpu_time_used);

    // Calculate sum using iteration
    start = clock();
    long long int iterativeResult = iterativeSum(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Iterative Sum (1 to %d): %lld\n", n, iterativeResult);
    printf("Iterative Execution Time: %.6lf seconds\n", cpu_time_used);

    return 0;
}
