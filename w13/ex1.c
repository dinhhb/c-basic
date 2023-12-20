#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateAndSave(int n, int m, int M) {
    FILE *file = fopen("arr-n.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d\n", n);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        int randomNumber = rand() % (M - m + 1) + m;
        fprintf(file, "%d ", randomNumber);
    }

    fclose(file);
}

int main() {
    int n, m, M;
    printf("Nhap n, m, M: ");
    scanf("%d %d %d", &n, &m, &M);

    generateAndSave(n, m, M);

    return 0;
}