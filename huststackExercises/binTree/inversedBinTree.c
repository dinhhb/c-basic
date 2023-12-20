/*
Đảo ngược cây nhị phân (nút trái thành nút phải và ngược lại). 
Dữ liệu nhập vào từ bàn phím có dòng đầu là số nút. N dòng tiếp theo mỗi dòng chứa nút cha và nút con trái, 
con phải (giá trị -1 nếu nút NULL). Cây in ra theo thứ tự InOrder (trái, gốc, phải).
*/

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
}

void printTree(Node *r)
{
    if (r == NULL)
        return;
    printTree(r->leftChild);
    printf("%d ", r->id);
    printTree(r->rightChild);
}

void inverseTree(Node *r){
    if (r == NULL) {
        return;
    }

    Node* temp = r->leftChild;
    r->leftChild = r->rightChild;
    r->rightChild = temp;

    inverseTree(r->leftChild);
    inverseTree(r->rightChild);
}

void main(){
    
    load();
    // printTree(root);
    inverseTree(root);
    // printf("Inverted tree:\n");
    printTree(root);
}
