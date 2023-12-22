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

void load()
{
    root = NULL;
    int u, l, r;

    while (scanf("%d", &u) == 1 && u != -2)
    {
        if (root == NULL){
            root = makeNode(u); // create the root
        }

        scanf("%d%d", &l, &r);

        if (l != -1){
            addLeftChild(u, l);
        }
        if (r != -1){
            addRightChild(u, r);
        }
    }
    // printf("Loaded tree successfully\n");
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

int maxPathSum(Node *node){
    if (node == NULL) {
        return 0;
    }

    int left = maxPathSum(node->leftChild);
    int right = maxPathSum(node->rightChild);

    return node->id + (left > right ? left : right);
}



int main(){
    // int sum = load();
    // printf("%d\n", hasPathSum(root, sum));
    load();
    printf("%d\n", maxPathSum(root));


    return 0;
}