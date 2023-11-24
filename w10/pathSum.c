#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int id;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;
Node *root;

Node *makeNode(int id)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *find(Node *r, int id)
{
    if (r == NULL)
        return NULL;
    if (r->id == id)
        return r;
    Node *p = find(r->leftChild, id);
    if (p != NULL)
        return p;
    return find(r->rightChild, id);
}

void addLeftChild(int u, int left)
{
    Node *pu = find(root, u);
    if (pu == NULL)
    {
        printf("Not found %d\n", u);
        return;
    }
    if (pu->leftChild != NULL)
    {
        printf("Node %d has already leftChild\n", u);
        return;
    }
    pu->leftChild = makeNode(left);
}

void addRightChild(int u, int right)
{
    Node *pu = find(root, u);
    if (pu == NULL)
    {
        printf("Not found %d\n", u);
        return;
    }
    if (pu->rightChild != NULL)
    {
        printf("Node %d has already rightChild\n", u);
        return;
    }
    pu->rightChild = makeNode(right);
}

int load()
{
    root = NULL;

    int numberOfNodes;
    scanf("%d", &numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++)
    {
        int u, l, r;
        scanf("%d%d%d", &u, &l, &r);

        if (root == NULL){
            root = makeNode(u); // create the root
        }

        if (l != -1){
            addLeftChild(u, l);
        }
        if (r != -1){
            addRightChild(u, r);
        }
    }

    int sum;
    fscanf(stdin, "%d", &sum);
    // printf("sum = %d\n", sum);
    return sum;
}

int hasPathSum(Node *r, int sum){
    if (r == NULL) {
        return 0;
    }

    int subSum = sum - r->id;

    if (subSum == 0 && r->leftChild == NULL && r->rightChild == NULL)
        return 1;
 
    if (r->leftChild && hasPathSum(r->leftChild, subSum)){
        return 1;
    }

    if (r->rightChild && hasPathSum(r->rightChild, subSum)){
        return 1;
    }
        
    return 0; 
}



void main(){
    int sum = load();
    printf("%d\n", hasPathSum(root, sum));
}