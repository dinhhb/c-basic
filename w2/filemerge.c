#include <stdio.h>
#include <stdlib.h>

enum
{
    SUCCESS,
    FAIL,
};

int main(int argc, char *argv[])
{
    int reval = SUCCESS;
    if (argc != 4)
    {
        printf("Usage: %s <phonebook1.dat> <phonebook2.dat> <phonebook.dat>\n", argv[0]);
        return 1;
    }

    FILE *fp1 = fopen(argv[1], "r+b");
    FILE *fp2 = fopen(argv[2], "r+b");

    FILE *fp = fopen(argv[3], "w+b");
    char c;

    if (fp1 == NULL || fp2 == NULL || fp == NULL)
    {
        puts("Could not open files");
        reval = FAIL;
        exit(0);
    }

    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp);

    while ((c = fgetc(fp2)) != EOF)
        fputc(c, fp);

    printf("Merged successful");

    fclose(fp1);
    fclose(fp2);
    fclose(fp);
    return reval;
}
