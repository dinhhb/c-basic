#include <stdio.h>
#include <time.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 100
};

void CopyByChar(FILE *fin, FILE *fout);
void CopyByLine(FILE *fin, FILE *fout);
void CopyByBlock(FILE *fin, FILE *fout);

int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "paragraph.txt";
    char filename2[] = "paragraph-copy.txt";
    int reval = SUCCESS;
    int option;

    while (1)
    {
        printf("---------------------------------------\n");
        printf("COPY FILE PROGRAM\n");
        printf("---------------------------------------\n");
        printf("1. Copy by character\n2. Copy by line\n3. Copy by block\n4. Quit\n---------------------------------------\nChoose 1 option: ");
        scanf("%d", &option);

        if (option == 4) break;
        else if (option < 1 || option > 4){
            printf("Wrong option! Please try again\n"); // Hiển thị thông báo nếu người dùng chọn tùy chọn không hợp lệ
            continue; // Tiếp tục vòng lặp để hiển thị lại menu
        }

        clock_t t;
        t = clock();
        double time_taken;

        if ((fptr1 = fopen(filename1, "r")) == NULL)
        {
            printf("Cannot open %s.\n", filename1);
            reval = FAIL;
        }
        else if ((fptr2 = fopen(filename2, "w")) == NULL)
        {
            printf("Cannot open %s.\n", filename2);
            reval = FAIL;
        }
        else
        {
            switch (option)
            {
            case 1:
                CopyByChar(fptr1, fptr2);
                t = clock() - t;
                time_taken = ((double)t) / CLOCKS_PER_SEC;
                printf("CopyByChar() took %lf miliseconds to execute \n", time_taken * 1000);
                break;

            case 2:
                CopyByLine(fptr1, fptr2);
                t = clock() - t;
                time_taken = ((double)t) / CLOCKS_PER_SEC;
                printf("CopyByLine() took %lf miliseconds to execute \n", time_taken * 1000);
                break;

            case 3:
                CopyByBlock(fptr1, fptr2);
                t = clock() - t;
                time_taken = ((double)t) / CLOCKS_PER_SEC;
                printf("CopyByBlock() took %lf miliseconds to execute \n", time_taken * 1000);
                break;
            }
            fclose(fptr1);
            fclose(fptr2);
        }
    }

    return reval;
}

void CopyByChar(FILE *fin, FILE *fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout); /* write to a file */
    }
}

void CopyByLine(FILE *fin, FILE *fout)
{
    char buff[MAX_LEN];
    int count = 0;
    while (fgets(buff, MAX_LEN, fin) != NULL)
    {
        fputs(buff, fout);
    }
}
void CopyByBlock(FILE *fin, FILE *fout)
{
    int num;
    char buff[MAX_LEN + 1];
    while (!feof(fin))
    {
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';
        fwrite(buff, sizeof(char), num, fout);
    }
}