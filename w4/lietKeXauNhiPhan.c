#include <stdio.h>

int x[100];

void printSolution(int n){
    for (int k = 0; k < n; k++){
        printf("%d", x[k]);
    }
    printf("\n");
}

int TRY(int k, int n, int *count){
    for (int v = 0; v <= 1; v++){
        if (x[k-1] + v < 2){
            x[k] = v;
            if (k == n - 1) printSolution(n);
            else TRY(k + 1, n, count);
        }
    }
    (*count)++;
}

int main(){
    int n = 4, count = 0;
    TRY(0, n, &count);
    printf("So lan goi: %d\n", count);
}