/*
Cho một dãy số gồm n (n < 10000) số nguyên phân biệt. Hãy sắp xếp dãy số sử dụng thuật toán heapsort.
Sau đó tìm một số xuất hiện trong dãy, trả về chỉ số của số đó (chỉ số bắt đầu từ 1), trả về 0 nếu không tìm thấy.
Đầu vào gồm dòng đầu là n. Dòng tiếp theo chứa n phần tử và giá trị cần tìm.
INPUT:
4
5 7 2 1 5
OUTPUT:
3
*/
#include <stdio.h>
#define N 1000001

void swap(int *a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void heapify(int *a, int i, int n)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int max = i;
    if (L < n && a[L] > a[max])
        max = L;
    if (R < n && a[R] > a[max])
        max = R;
    if (max != i)
    {
        swap(a, i, max);
        heapify(a, max, n);
    }
}

void buildHeap(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, i, n);
}

void heapSort(int *a, int n)
{
    buildHeap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a, 0, i);
        heapify(a, 0, i);
    }
}

int main()
{
    int a[N];
    int n, Q;

    if (scanf("%d", &n) != 1)
    {
        fprintf(stderr, "Không đọc được giá trị n\n");
        return 1;
    }
    // printf("n = %d\n", n);

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            fprintf(stderr, "Không đọc được giá trị a[%d]\n", i);
            return 1;
        }
        // printf("a[%d] = %d\n", i, a[i]);
    }

    if (scanf("%d", &Q) != 1)
    {
        fprintf(stderr, "Không đọc được giá trị cần tìm\n");
        return 1;
    }

    heapSort(a, n);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == Q)
        {
            printf("%d", i+1);
            return 0;
        }
    }

    printf("0");
    return 0;
}
