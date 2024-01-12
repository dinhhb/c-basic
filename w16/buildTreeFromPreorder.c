#include <stdio.h>
#include <stdlib.h>

#define N 100001
int n;
int a[N];
int ok = 1;

typedef struct Node
{
    int id;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *makeNode(int id)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *build(int start, int end)
{
    if (start > end)
        return NULL;
    if (start == end)
    {
        return makeNode(a[start]);
    }
    Node *r = makeNode(a[start]);
    int i = start + 1;
    while (i <= end && a[i] < a[start])
        i++;
    for (int j = i; j <= end; j++)
        if (a[j] < a[start])
        {
            ok = 0;
            break;
        }

    r->leftChild = build(start + 1, i - 1);
    r->rightChild = build(i, end);
    return r;
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%d ", r->id);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ok = 1;
    Node *root = build(1, n);
    if (ok == 0)
    {
        printf("NULL");
        return 0;
    }
    postOrder(root);
    printf("\n");
    return 0;
}

