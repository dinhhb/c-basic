#include <stdio.h>

int x[4];

void printSolution(int n){
    for (int k = 0; k < n; k++){
        printf("%X", x[k]);
    }
    printf("\n");
}

int TRY(int k, int n, int *count){
    for (int c = 0; c <= 15; c++){
        x[k] = c;
        if (k == n - 1) printSolution(n);
        else TRY(k + 1, n, count);
    }
    (*count)++;
}

int main(){
    int n = 2, count = 0;
    TRY(0, n, &count);
    printf("So lan goi: %d\n", count);
}