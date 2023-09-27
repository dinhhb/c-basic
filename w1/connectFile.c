#include <stdio.h>
#include <stdlib.h>

enum{
    SUCCESS,
    FAIL,
    MAX_LEN = 1000
};

void LineReadWrite(FILE *fin, FILE *fout){
    char buff[MAX_LEN];
    while (fgets(buff, MAX_LEN, fin) != NULL){
        fputs(buff, fout);
    }
}

int main(int argc, char **argv){
    FILE *fp1, *fp2;
    int i = 0, n;
    int reval = SUCCESS;

    if (argc != 3){
        printf("Usage: %s file1.txt file2.txt\n", argv[0]);
        exit(1);
    }

    printf("Loading file...\n");

    if ((fp2 = fopen(argv[2], "r")) == NULL){
        printf("Can not open %s.\n", argv[2]);
        reval = FAIL;
    }
    else if ((fp1 = fopen(argv[1], "a")) == NULL){
        printf("Can not open %s.\n", argv[1]);
        reval = FAIL;
    }

    LineReadWrite(fp2, fp1);
    fclose(fp1);
    fclose(fp2);
    return reval;
}