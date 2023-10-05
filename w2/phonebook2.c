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

int main(void)
{
    FILE *fp;
    phoneaddress *phonearr;
    int i, n, irc; // return code
    int reval = SUCCESS;

    printf("Read from 2sd data to 3rd data \n");
    if ((fp = fopen("phonebook.dat", "r+b")) == NULL)
    {
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    }

    // Cấp phát bộ nhớ cho mảng phonearr để chứa 2 bản ghi phoneaddress.
    phonearr = (phoneaddress *)malloc(2 * sizeof(phoneaddress));

    if (phonearr == NULL)
    {
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    // Sử dụng hàm fseek để di chuyển con trỏ vị trí trong tệp đến bản ghi thứ 2.
    if (fseek(fp, 1 * sizeof(phoneaddress), SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return FAIL;
    }

    // Sử dụng hàm fread để đọc 2 bản ghi phoneaddress từ tệp vào mảng phonearr.
    irc = fread(phonearr, sizeof(phoneaddress), 2, fp);

    // Hiển thị thông tin của 2 bản ghi được đọc từ tệp "phonebook.dat".
    for (i = 0; i < 2; i++)
    {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s\n", phonearr[i].email);
    }

    // Thay đổi dữ liệu của bản ghi thứ 2 trong mảng phonearr.
    strcpy(phonearr[1].name, "Lan Hoa");
    strcpy(phonearr[1].tel, "0923456");
    strcpy(phonearr[1].email, "lovelybuffalo@hut.edu.vn");
    
    fseek(fp, 1 * sizeof(phoneaddress), SEEK_SET);

    irc = fwrite(phonearr, sizeof(phoneaddress), 2, fp);
    printf(" fwrite return code = %d\n", irc);

    fclose(fp);
    free(phonearr);
    return reval;
}