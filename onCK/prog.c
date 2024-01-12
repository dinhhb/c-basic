#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock
{
    char stockSymbol[256]; // ma co phieu
    double openPrice;
    double closePrice;
} Stock;


typedef struct Node
{
    Stock key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;

Node *makeNode(char *stockSymbol, double openPrice, double closePrice)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->key.stockSymbol, stockSymbol);
    p->key.openPrice = openPrice;
    p->key.closePrice = closePrice;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *insert(Node *r, char *stockSymbol, double openPrice, double closePrice)
{
    if (r == NULL)
        return makeNode(stockSymbol, openPrice, closePrice);
    int c = strcmp(r->key.stockSymbol, stockSymbol);
    if (c < 0)
    {
        r->rightChild = insert(r->rightChild, stockSymbol, openPrice, closePrice);
        return r;
    }
    else
    {
        r->leftChild = insert(r->leftChild, stockSymbol, openPrice, closePrice);
        return r;
    }
}

void readFile()
{
    FILE *fp = fopen("data.txt", "r");
    int n;
    scanf("%d", &n);
    
    fclose(fp);
}

void searchByStockSymbol()
{
}

void searchRisingStockSymbol()
{
}

void findStockSymbolHasHighestRisingDay()
{
}

int main()
{
    while (1)
    {
        int cmd;
        printf("Menu\n1. Đọc file\n2. Tìm kiếm theo mã chứng khoán\n3. Tìm kiếm những mã chứng khoán có xu hướng tăng\n4. Tìm mã có số ngày tăng lớn nhất\n5. Thoát chương trình\n");
        printf("Nhập lựa chọn: ");
        scanf("%d", &cmd);

        switch (cmd)
        {
        case 1:
            readFile();
            break;
        case 2:
            searchByStockSymbol();
            break;
        case 3:
            searchRisingStockSymbol();
            break;
        case 4:
            findStockSymbolHasHighestRisingDay();
            break;
        default:
            printf("Hà Bửu Định 20205200\n");
            return 0;
        }
    }
    return 0;
}