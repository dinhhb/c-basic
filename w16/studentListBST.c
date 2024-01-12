#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[256];
    char email[256];
} Student;

typedef struct Node
{
    Student key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;

Node *makeNode(char *name, char *email)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->key.name, name);
    strcpy(p->key.email, email);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *insert(Node *r, char *name, char *email)
{
    if (r == NULL)
        return makeNode(name, email);
    int c = strcmp(r->key.name, name);
    if (c == 0)
    {
        printf("Student %s exists, do not insert\n", name);
        return r;
    }
    else if (c < 0)
    {
        r->rightChild = insert(r->rightChild, name, email);
        return r;
    }
    else
    {
        r->leftChild = insert(r->leftChild, name, email);
        return r;
    }
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;
    printf("%s %s\n", r->key.name, r->key.email);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%s %s\n", r->key.name, r->key.email);
}

int main()
{
    Student student;
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
            scanf("%s %s", student.name, student.email);
            root = insert(root, student.name, student.email);
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