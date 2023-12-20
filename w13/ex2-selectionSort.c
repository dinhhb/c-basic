#include <stdio.h>

void selectionSort(int A[], int N)
{
    // index tu 0 -> N
    for (int k = 0; k < N - 1; k++)
    {
        int min = k;
        for (int j = k + 1; j < N; j++)
        {
            if (A[min] > A[j])
                min = j;
        }
        int tmp = A[min];
        A[min] = A[k];
        A[k] = tmp;
    }
}

int main()
{
    int n;
    fscanf(stdin, "%d", &n);
    // printf("n = %d\n", n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(stdin, "%d", &a[i]);
    }

    selectionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}