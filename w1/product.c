#include <stdio.h>
enum
{
    SUCCESS,
    FAIL,
    MAX_ELEMENT = 10
};

typedef struct
{
    int no;
    char name[20];
    double price;
} product;

int main(void)
{
    FILE *fp;
    product arr[MAX_ELEMENT];
    int i = 0, n;
    int reval = SUCCESS;
    printf("Loading file...\n");
    if ((fp = fopen("text/product.txt", "r")) == NULL)
    {
        printf("Can not open %s.\n", "product.txt");
        reval = FAIL;
    }
    else
    {
        while (fscanf(fp, "%d%s%lf", &arr[i].no, arr[i].name, &arr[i].price) != EOF)
        {
            i++;
        }
        n = i;
        for (i = 0; i < n; i++)
            printf("%-6d%-24s%-6.2f\n", arr[i].no, arr[i].name, arr[i].price);
    }
    fclose(fp);
    return reval;
}