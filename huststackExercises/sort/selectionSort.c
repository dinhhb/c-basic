/*
Viết chương trình nhập vào 1 dãy số nguyên dương a1 , a2 , …, an , 
sắp xếp dãy đã cho theo thứ tự không giảm bằng thuật toán sắp xếp lựa chọn
Dữ liệu (stdin) 
Dòng 1: ghi số nguyên dương n (1 ≤ n ≤ 10^6 ) 
Dòng 2: ghi a1 , a2 , …, an , (1 ≤ ai ≤ 10^6 ) 
Kết quả (stdout) 
Ghi dãy đã được sắp xếp theo thứ tự không giảm, các phần tử cách nhau bởi 1 dấu cách
*/

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