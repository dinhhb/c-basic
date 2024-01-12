#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000001

typedef struct Node
{
    char word[20];
    int occ;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;
char T[N];
int n;

void input()
{
    n = 0;
    while (!feof(stdin))
    {
        char c = fgetc(stdin);
        T[n] = c;
        n += 1;
    }
    T[n - 1] = '\0';
}

Node *makeNode(char *w)
{
    Node *nod = (Node *)malloc(sizeof(Node));
    strcpy(nod->word, w);
    nod->occ = 1;
    nod->leftChild = NULL;
    nod->rightChild = NULL;
    return nod;
}

Node *insert(Node *r, char *w)
{
    if (r == NULL)
        return makeNode(w);
    int c = strcmp(r->word, w);
    if (c == 0)
    {
        r->occ += 1;
        return r;
    }
    if (c < 0)
        r->rightChild = insert(r->rightChild, w);
    else
        r->leftChild = insert(r->leftChild, w);
    return r;
}

int legal(char c)
{
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
}

void solve()
{
    root = NULL;
    char word[30];
    int end = -1;
    for (int i = 0; i < n; i++)
    {
        if (legal(T[i]))
        {
            end++;
            word[end] = T[i];
        }
        else
        {
            if (end != -1)
            {
                word[end + 1] = '\0';
                root = insert(root, word);
            }
            end = -1;
        }
    }
}

void inOrder(Node *r)
{
    if (r == NULL)
        return;
    inOrder(r->leftChild);
    printf("%s %d\n", r->word, r->occ);
    inOrder(r->rightChild);
}

int main()
{
    input();
    solve();
    inOrder(root);
    return 0;
}