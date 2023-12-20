/*
Tính tổng hai số lớn nhập vào từ bàn phím (giả sử số thứ nhất lớn hơn). Chỉ sử dụng ngăn xếp, không sử dụng mảng/xâu.
VD:
INPUT:
1234
123
OUTPUT:
1357
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top1 = NULL;
Node* top2 = NULL;
Node* result = NULL;

Node* makeNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void push(Node** top, int x) {
    Node* p = makeNode(x);
    p->next = *top;
    *top = p;
}

int pop(Node** top) {
    if (*top == NULL)
        return -1; // Assuming -1 indicates an empty stack
    int x = (*top)->data;
    Node* tmp = *top;
    *top = (*top)->next;
    free(tmp);
    return x;
}

int stackEmpty(Node* top) {
    return top == NULL;
}

void addStacks() {
    int carry = 0;
    while (!stackEmpty(top1) || !stackEmpty(top2) || carry) {
        int num1 = stackEmpty(top1) ? 0 : pop(&top1);
        int num2 = stackEmpty(top2) ? 0 : pop(&top2);
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        push(&result, sum % 10);
    }
}

int main() {
    int c;

    // printf("Enter the first number: ");
    while ((c = getchar()) != '\n') {
        push(&top1, c - '0');
    }

    // printf("Enter the second number: ");
    while ((c = getchar()) != '\n') {
        push(&top2, c - '0');
    }

    addStacks();

    // printf("Sum of the numbers: ");
    while (!stackEmpty(result)) {
        printf("%d", pop(&result));
    }

    return 0;
}
