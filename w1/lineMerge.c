#include <stdio.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 81
};

void LineMerge(FILE *f1, FILE *f2, FILE *f3)
{
    char buff1[MAX_LEN], buff2[MAX_LEN];
    int len;
    while ((fgets(buff1, MAX_LEN, f1) != NULL) && (fgets(buff2, MAX_LEN, f2) != NULL))
    {
        fputs(buff1, f3);
        fputs(buff2, f3);
    }
    if (buff1 != NULL)
        fputs(buff1, f3);
    while (fgets(buff1, MAX_LEN, f1) != NULL)
    {
        fputs(buff1, f3);
    }
    while (fgets(buff2, MAX_LEN, f2) != NULL)
    {
        fputs(buff2, f3);
    }
}

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
    FILE *fptr1, *fptr2, *fptr3;
    char filename1[] = "text/merge1.txt";
    char filename2[] = "text/merge2.txt";
    char filename3[] = "text/merge3.txt";
    int reval = SUCCESS;
    if ((fptr1 = fopen(filename1, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    }
    else if ((fptr3 = fopen(filename3, "w")) == NULL)
    {
        printf("Cannot open %s.\n", filename3);
        reval = FAIL;
    }
    else if ((fptr2 = fopen(filename2, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    }
    else
    {
        LineMerge(fptr1, fptr2, fptr3);
        fclose(fptr1);
        fclose(fptr2);
        fclose(fptr3);
    }
    return reval;
}
