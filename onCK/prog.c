#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock
{
    char stockSymbol[4]; // ma co phieu
    double openPrice[10];
    double closePrice[10];
} Stock;


typedef struct Node
{
    Stock key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;

Node *makeNode(Stock stock)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->key.stockSymbol, stock.stockSymbol);
    memcpy(p->key.openPrice, stock.openPrice, sizeof(stock.openPrice));
    memcpy(p->key.closePrice, stock.closePrice, sizeof(stock.closePrice));
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *insert(Node *r, Stock stock, int day)
{
    // Kiểm tra nút hiện tại
    if (r == NULL)
        return makeNode(stock);

    // So sánh nút hiện tại với nút muốn chèn
    int c = strcmp(r->key.stockSymbol, stock.stockSymbol); 
    if (c < 0)
    {
        r->rightChild = insert(r->rightChild, stock, day);
    }
    else if (c > 0)
    {
        r->leftChild = insert(r->leftChild, stock, day);
    }
    // Chèn hoặc cập nhật (giá trị đã tồn tại)
    else
    {
        r->key.openPrice[day] = stock.openPrice[day];
        r->key.closePrice[day] = stock.closePrice[day];
    }
    return r;
}

void readFile()
{
    int n;
    scanf("%d", &n);
    
    Stock stock;
    root = NULL;
    for (int day = 0; day < 10; day++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s%lf%lf", stock.stockSymbol, &stock.openPrice[day], &stock.closePrice[day]);
            root = insert(root, stock, day);
        }
    }
}

// Inorder: duyệt nút con trái trái -> xử lý nút hiện tại -> duyệt con phải 
// => in ra các khoá theo thứ tự tăng dần
void print1(Node *r)  
{
    if (r == NULL)
        return;
    print1(r->leftChild);
    
    double sum = 0;
    for (int day = 0; day < 10; day++)
    {
        sum += (r->key.closePrice[day] - r->key.openPrice[day]);
    }
    double average = sum / 10;
    
    printf("%s %.3f\n", r->key.stockSymbol, average);
    
    print1(r->rightChild);
}

void searchByStockSymbol(Node *r, char *symbol)
{
    if (r == NULL)
    {
        printf("Không tìm thấy\n");
        return;
    }

    int cmp = strcmp(symbol, r->key.stockSymbol);
    if (cmp < 0)
    {
        searchByStockSymbol(r->leftChild, symbol);
    }
    else if (cmp > 0)
    {
        searchByStockSymbol(r->rightChild, symbol);
    }
    else
    {
        double maxClose = r->key.closePrice[0];
        double minClose = r->key.closePrice[0];
        for (int day = 1; day < 10; day++)
        {
            if (r->key.closePrice[day] > maxClose)
            {
                maxClose = r->key.closePrice[day];
            }
            if (r->key.closePrice[day] < minClose)
            {
                minClose = r->key.closePrice[day];
            }
        }
        printf("Giá đóng cửa cao nhất: %.3f\n", maxClose);
        printf("Giá đóng cửa thấp nhất: %.3f\n", minClose);
    }
}

void searchRisingStockSymbol(Node *r)
{
    if (r == NULL)
        return;

    // Duyệt cây theo thứ tự giữa (in-order traversal)
    searchRisingStockSymbol(r->leftChild);

    // Kiểm tra điều kiện tăng giá cho ngày 1 và ngày 2
    if (r->key.closePrice[0] > r->key.openPrice[0] && r->key.closePrice[1] > r->key.openPrice[1])
    {
        printf("%s\n", r->key.stockSymbol);
    }

    searchRisingStockSymbol(r->rightChild);
}

void printMaxRisingSymbols(int maxRisingDays, char maxRisingSymbols[][4], int numSymbols) {
    printf("Mã chứng khoán có số ngày tăng lớn nhất (%d ngày): \n", maxRisingDays);
    for (int i = 0; i < numSymbols; i++) {
        printf("%s\n", maxRisingSymbols[i]);
    }
}

void findStockSymbolHasHighestRisingDay(Node *r, int *maxRisingDays, char maxRisingSymbols[][4], int *numSymbols)
{
    if (r == NULL)
        return;

    // Duyệt cây theo thứ tự giữa (in-order traversal)
    findStockSymbolHasHighestRisingDay(r->leftChild, maxRisingDays, maxRisingSymbols, numSymbols);

    // Đếm số ngày tăng giá cho mã chứng khoán hiện tại
    int risingDays = 0;
    for (int day = 0; day < 10; day++) {
        if (r->key.closePrice[day] > r->key.openPrice[day]) {
            risingDays++;
        }
    }

    // Cập nhật nếu tìm thấy số ngày tăng giá lớn hơn
    if (risingDays > *maxRisingDays) {
        *maxRisingDays = risingDays;
        *numSymbols = 1; // Reset số lượng mã chứng khoán và lưu mã hiện tại
        strcpy(maxRisingSymbols[0], r->key.stockSymbol);
    } else if (risingDays == *maxRisingDays) {
        // Thêm mã chứng khoán vào danh sách nếu số ngày tăng giá bằng với số ngày tăng giá lớn nhất
        strcpy(maxRisingSymbols[*numSymbols], r->key.stockSymbol);
        (*numSymbols)++;
    }

    findStockSymbolHasHighestRisingDay(r->rightChild, maxRisingDays, maxRisingSymbols, numSymbols);
}

int main()
{
    char symbol[4];
    int maxRisingDays = 0;
    char maxRisingSymbols[100][4]; // Giả sử có tối đa 100 mã có số ngày tăng lớn nhất
    int numSymbols = 0;

    while (1)
    {
        int cmd;
        printf("----------------------------------------------------------\nMENU\n----------------------------------------------------------\n");
        printf("1. Đọc file\n2. Tìm kiếm theo mã chứng khoán\n3. Tìm kiếm những mã chứng khoán có xu hướng tăng\n4. Tìm mã có số ngày tăng lớn nhất\n5. Thoát chương trình\n");
        printf("----------------------------------------------------------\nNhập lựa chọn: ");
        scanf("%d", &cmd);

        switch (cmd)
        {
        case 1:
            readFile();
            print1(root);
            break;
        case 2:
            scanf("%s", symbol);
            searchByStockSymbol(root, symbol);
            break;
        case 3:
            searchRisingStockSymbol(root);
            break;
        case 4:
            findStockSymbolHasHighestRisingDay(root, &maxRisingDays, maxRisingSymbols, &numSymbols);
            printMaxRisingSymbols(maxRisingDays, maxRisingSymbols, numSymbols);
            break;
        default:
            printf("Hà Bửu Định 20205200\n");
            return 0;
        }
    }
    return 0;
}