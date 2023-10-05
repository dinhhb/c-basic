#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAIL,
    MAX_ELEMENT = 20
};

// the phone book structure
typedef struct phoneaddress
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int countNumRec(FILE *fp){
    fseek(fp, 0, SEEK_END);    // Di chuyển con trỏ vị trí tệp đến cuối tệp
    long fileSize = ftell(fp); // Lấy vị trí hiện tại của con trỏ vị trí, là kích thước tệp

    if (fileSize == -1)
    {
        printf("Error in ftell!\n");
    }

    return fileSize / sizeof(phoneaddress);   // số bản ghi file fp
}

int main(int argc, char *argv[])
{
    FILE *fp;
    phoneaddress *phonearr;
    int i, n, irc; // return code
    int reval = SUCCESS;

    if (argc != 2)
    {
        printf("Usage: %s <.dat file>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv[1], "r+b")) == NULL)
    {
        printf("Can not open %s.\n", argv[1]);
        reval = FAIL;
    }

    int numRecords = countNumRec(fp);
    printf("%d\n", numRecords);
    phonearr = (phoneaddress *)malloc(numRecords * sizeof(phoneaddress));

    if (phonearr == NULL)
    {
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    irc = fread(phonearr, sizeof(phoneaddress), numRecords, fp);

    // Hiển thị thông tin của 2 bản ghi được đọc từ tệp "phonebook.dat".
    for (i = 0; i < numRecords; i++)
    {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s\n", phonearr[i].email);
    }

    fclose(fp);
    free(phonearr);
    return reval;
}