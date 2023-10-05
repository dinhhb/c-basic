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
    FILE *fp, *fp1, *fp2;
    phoneaddress *phonearr1, *phonearr2;
    int i, n, irc; // return code
    int reval = SUCCESS;
    int num = atoi(argv[2]);    // số bản ghi ghi vào file phonebook1

    if (argc != 5)
    {
        printf("Usage: %s phonebook.dat <num> <phonebook1.dat> <phonebook2.dat>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen("phonebook.dat", "r+b")) == NULL)
    {
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    }
    else if ((fp1 = fopen(argv[3], "w+b")) == NULL)
    {
        printf("Can not open %s.\n", argv[3]);
        reval = FAIL;
    }
    else if ((fp2 = fopen(argv[4], "w+b")) == NULL)
    {
        printf("Can not open %s.\n", argv[4]);
        reval = FAIL;
    }

    // Memory allocation
    phonearr1 = (phoneaddress *)malloc(num * sizeof(phoneaddress));

    if (phonearr1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    irc = fread(phonearr1, sizeof(phoneaddress), num, fp);
    for (i = 0; i < num; i++)
    {
        printf("%s-", phonearr1[i].name);
        printf("%s-", phonearr1[i].tel);
        printf("%s\n", phonearr1[i].email);
    }

    irc = fwrite(phonearr1, sizeof(phoneaddress), num, fp1);

    int numRecords2 = countNumRec(fp) - num;  // số bản ghi ghi vào file phonebook2

    if (fseek(fp, num * sizeof(phoneaddress), SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return FAIL;
    }

    phonearr2 = (phoneaddress *)malloc(numRecords2 * sizeof(phoneaddress));

    if (phonearr2 == NULL)
    {
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    irc = fread(phonearr2, sizeof(phoneaddress), numRecords2, fp);
    printf("---------------------------------\n");
    for (i = 0; i < numRecords2; i++)
    {
        printf("%s-", phonearr2[i].name);
        printf("%s-", phonearr2[i].tel);
        printf("%s\n", phonearr2[i].email);
    }

    irc = fwrite(phonearr2, sizeof(phoneaddress), num, fp2);

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    free(phonearr1);
    free(phonearr2);
    return reval;
}