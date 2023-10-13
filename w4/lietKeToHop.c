#include <stdio.h>

int x[5];

void printSolution(int k) {
    for (int j = 0; j < k; j++) {
        printf("%d", x[j]);
    }
    printf("\n");
}

void TRY(int i, int n, int k, int *count) {
    for (int v = (i == 1 ? 1 : x[i - 1] + 1); v <= n - k + i; v++) {
        x[i - 1] = v;
        if (i == k) {
            printSolution(k);
            (*count)++;
        } else {
            TRY(i + 1, n, k, count);
        }
    }
}

int main() {
    int n = 4, k = 3, count = 0;
    TRY(1, n, k, &count);
    printf("So lan goi: %d\n", count);
}
