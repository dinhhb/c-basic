#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
#define m 10000

typedef struct Node
{
    char key[MAX];
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *T[m];

Node *makeNode(char *k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->key, k);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

int h(char *k)
{
    int c = 0;
    for (int i = 0; i < strlen(k); i++)
        c = (c * 256 + k[i]) % m;
    return c;
}

Node *findBST(Node *r, char *k)
{
    if (r == NULL)
        return NULL;
    int c = strcmp(r->key, k);
    if (c == 0)
        return r;
    if (c < 0)
        return findBST(r->rightChild, k);
    else
        return findBST(r->leftChild, k);
}

Node *insertBST(Node *r, char *k)
{
    if (r == NULL)
        return makeNode(k);
    if (strcmp(r->key, k) < 0)
        r->rightChild = insertBST(r->rightChild, k);
    else
        r->leftChild = insertBST(r->leftChild, k);
    return r;
}

int find(char *k)
{
    int i = h(k);
    Node *p = findBST(T[i], k);
    if (p == NULL)
        return 0;
    return 1;
}

int insert(char *k)
{ // put(k)
    int i = h(k);
    Node *p = findBST(T[i], k);
    if (p != NULL)
        return 0;
    T[i] = insertBST(T[i], k);
    return 1;
}

int main()
{
    char k[MAX], cmd[20];
    while (1)
    {
        scanf("%s", k);
        if (strcmp(k, "*") == 0)
            break;
        insert(k); // put k into the hash table (+BST)
    }
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "find") == 0)
        {
            scanf("%s", k);
            int ans = find(k);
            printf("%d\n", ans);
        }
        else if (strcmp(cmd, "insert") == 0)
        {
            scanf("%s", k);
            int ans = insert(k);
            printf("%d\n", ans);
        }
        else if (strcmp(cmd, "***") == 0)
        {
            break;
        }
    }
    return 0;
}
