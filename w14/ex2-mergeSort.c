#include <stdio.h>

int TA[1000];

void merge(int A[], int L, int M, int R)
{
    // tron 2 day da sap A[L..M] va A[M+1..R]
    int i = L;
    int j = M + 1;
    for (int k = L; k <= R; k++)
    {
        
        if (i > M)
        {
            TA[k] = A[j];
            j++;
        }
        else if (j > R)
        {
            TA[k] = A[i];
            i++;
        }
        else
        {
            if (A[i] < A[j])
            {
                TA[k] = A[i];
                i++;
            }
            else
            {
                TA[k] = A[j];
                j++;
            }
        }
    }
    for (int k = L; k <= R; k++)
        A[k] = TA[k];
}

void mergeSort(int A[], int L, int R)
{
    if (L < R)
    {
        int M = (L + R) / 2;
        mergeSort(A, L, M);
        mergeSort(A, M + 1, R);
        merge(A, L, M, R);
    }
}

int main(){
    FILE *file = fopen("arr-n.txt", "r");
    if (file == NULL) {
        printf("File not found");
        return 0;
    }

    int n;
    fscanf(file, "%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    
    mergeSort(arr, 0, n - 1);
    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    fclose(file);
    return 0;
}