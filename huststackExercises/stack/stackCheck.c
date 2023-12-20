/*
Kiểm tra một chuỗi dấu ngoặc nhập vào xem có hợp lệ hay không (1 là hợp lệ, 0 là không hợp lệ)
VD 
INPUT:
[({})]()
OUTPUT:
1
INPUT:
([} {})
OUTPUT:
0
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

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}

int check(char *s)
{
    initStack();
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        }
        else
        {
            if (stackEmpty())
                return 0;
            char x = pop();
            if (!match(x, s[i]))
                return 0;
        }
    }
    return stackEmpty();
}

int main(){
    char s[20];
    scanf("%s", s);
    // printf("%s", s);
    if (check(s) == 0) printf("0");
    else printf("1");

    return 0;
}