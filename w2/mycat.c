#include <stdio.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 80
};

void BlockCat(FILE *fin);

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;
    int reval = SUCCESS;
    if (argc != 2)
    {
        printf("The correct syntax should be: %s text/lab1.txt \n", argv[0]);
        reval = FAIL;
    }
    if ((fptr1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s.\n", argv[1]);
        reval = FAIL;
    }
    else
    {
        BlockCat(fptr1);
        fclose(fptr1);
    }
    return reval;
}

void BlockCat(FILE *fin)
{
    int num;
    char buff[MAX_LEN + 1];
    while (!feof(fin))
    {
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';
        printf("%s", buff);
    }
}