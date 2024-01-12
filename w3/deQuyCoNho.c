#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX 100

int C(int k, int n, int M[MAX][MAX]){
    if(k == 0 || k == n) M[k][n] = 1; 
    else if(M[k][n] == 0)
        M[k][n] =  C(k,n-1, M) + C(k-1,n-1, M);
    return M[k][n];
}

int main(){
    int M[MAX][MAX];
    clock_t start, end;
    start = clock();
    memset(M, 0, sizeof(M));
    printf("%d\n", C(20, 25, M));
    end = clock();
    double time_taken = ((double)(end -start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf\n", time_taken);
}