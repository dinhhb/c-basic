#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;

Node *makeNode(int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = k;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *insert(Node *r, int k)
{
    if (r == NULL)
        r = makeNode(k);
    else if (r->key > k)
        r->leftChild = insert(r->leftChild, k);
    else if (r->key < k)
        r->rightChild = insert(r->rightChild, k);
    return r;
}

Node *removeRoot(Node *r)
{
    if (r == NULL)
        return NULL;
    if (r->rightChild == NULL)
    {
        Node *tmp = r;
        r = r->leftChild;
        free(tmp);
        return r;
    }
    Node *p = r->rightChild;
    Node *pp = r;
    if (p->leftChild == NULL)
    {
        r->key = p->key;
        Node *tmp = p;
        r->rightChild = p->rightChild;
        free(tmp);
        return r;
    }
    while (p->leftChild != NULL)
    {
        pp = p;
        p = p->leftChild;
    }
    pp->leftChild = p->rightChild;
    r->key = p->key;
    free(p);
    return r;
}

Node *removeNode(Node *r, int k)
{
    if (r == NULL)
        return NULL;
    if (r->key == k)
        return removeRoot(r);
    else if (r->key < k)
        r->rightChild = removeNode(r->rightChild, k);
    else
        r->leftChild = removeNode(r->leftChild, k);
    return r;
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;
    printf("%d ", r->key);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%d ", r->key);
}

int main()
{
    root = NULL;
    while (1)
    {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        else if (strcmp(cmd, "insert") == 0)
        {
            int k;
            scanf("%d", &k);
            root = insert(root, k);
        }
        else if (strcmp(cmd, "remove") == 0)
        {
            int k;
            scanf("%d", &k);
            root = removeNode(root, k);
        }
        else if (strcmp(cmd, "preorder") == 0)
        {
            preOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "postorder") == 0)
        {
            postOrder(root);
            printf("\n");
        }
    }
    return 0;
}