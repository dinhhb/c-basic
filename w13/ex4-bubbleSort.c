#include <stdio.h>

void bubbleSort(int A[], int N)
{
    // index tu 0 den N
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                int tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
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

    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
