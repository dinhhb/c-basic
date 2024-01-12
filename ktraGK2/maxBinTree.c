/*
Cho một dãy số nguyên phân biệt a1, a2,… an. Hãy xây dựng cây nhị phân lớn nhất (MaxBT) theo quy tắc sau:
Bước 1: Lấy phần tử lớn nhất ai làm gốc
Bước 2: Lấy các phần tử bên trái ai làm cây con trái
Bước 3: Lấy các phần tử bên phải ai làm cây con phải
Lặp lại (đệ quy) các bước trên với cây con trái và cây con phải.
Chương trình nhận đầu vào có dòng đầu là số nguyên dương n (n < 50). Dòng tiếp theo chứa n số nguyên phân biệt 
cách nhau bởi dấu cách. Chương trình in ra MaxBT theo thứ tự sau (postorder), mỗi nút cách nhau bởi dấu cách.

Ví dụ
INPUT:
6
3 2 1 6 0 5
OUTPUT:
1 2 3 0 5 6
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node *constructTreeUtil(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int maxind = start;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] > arr[maxind])
        {
            maxind = i;
        }
    }

    Node *root = newNode(arr[maxind]);

    root->left = constructTreeUtil(arr, start, maxind - 1); 
    root->right = constructTreeUtil(arr, maxind + 1, end);

    return root;
}

Node *constructTree(int arr[], int size)
{
    return constructTreeUtil(arr, 0, size - 1);
}

void printPostorder(Node *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node *root = constructTree(arr, n);
    printPostorder(root);
    return 0;
}