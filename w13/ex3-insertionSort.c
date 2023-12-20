#include <stdio.h>

void insertionSort(int A[], int N)
{
    // index tu 0 -> N
    for (int k = 1; k < N; k++)
    {
        int key = A[k];
        int j = k - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}