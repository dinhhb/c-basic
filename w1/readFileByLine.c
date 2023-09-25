#include <stdio.h>
enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 81
};
int LineReadWrite(FILE *fin, FILE *fout)
{
    char buff[MAX_LEN];
    int count = 0;
    while (fgets(buff, MAX_LEN, fin) != NULL)
    {
        fputs(buff, fout);
        printf("%s", buff);
        count++;
    }
    return count;
}
int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "text/lab1a.txt";
    char filename2[] = "text/lab1.txt";
    int reval = SUCCESS;
    if ((fptr1 = fopen(filename1, "w")) == NULL)
    {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    }
    else if ((fptr2 = fopen(filename2, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    }
    else
    {
        printf("\nThis file has %d lines\n", LineReadWrite(fptr2, fptr1));
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}