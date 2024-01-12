/*
Tìm số lớn thứ k trong dãy
Cho một dãy gồm n (n < 1000) số nguyên, tìm giá trị lớn thứ k trong dãy. 
Đầu vào có dòng đầu là n. Dòng tiếp theo chứa n phần tử của dãy. Dòng cuối là số nguyên dương k <= n. 
Chương trình in ra -1 nếu không tồn tại giá trị thỏa mãn.

Ví dụ
INPUT:
6
6 3 4 4 2 1
4
OUTPUT:
2
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    qsort(arr, n, sizeof(int), compare);

    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n-1];

    if(k > j) {
        printf("-1\n");
    } else {
        printf("%d\n", arr[k-1]);
    }
    return 0;
}