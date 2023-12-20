/*
Đảo ngược một xâu (không chứa dấu cách) do người dùng nhập vào (dừng khi gặp dấu '\n') sử dụng ngăn xếp. Không dùng cấu trúc xâu. (Gợi ý: dùng getchar() đọc từng kí tự vào ngăn xếp)
Vd:
INPUT
12345
OUTPUT
54321
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char c;
    struct Node *next;
} Node;
Node *top;

Node *makeNode(char x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->c = x;
    p->next = NULL;
    return p;
}

void initStack()
{
    top = NULL;
}
int stackEmpty()
{
    return top == NULL;
}

void push(char x)
{
    Node *p = makeNode(x);
    p->next = top;
    top = p;
}
char pop()
{
    if (stackEmpty())
        return ' ';
    char x = top->c;
    Node *tmp = top;
    top = top->next;
    free(tmp);
    return x;
}

int main(){

    initStack();
    int c; 

    while ((c = getchar()) != '\n') 
    {
        push(c);
    }
    
    while (!stackEmpty())
    {
        printf("%c", pop());
    }
    
    return 0;
}   