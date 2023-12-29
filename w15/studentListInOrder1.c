/*
Cho danh sách sinh viên gồm hai thông tin name và email là xâu không chứa dấu cách có độ dài tối đa 255.
Viết chương trình nhập lần lượt từng sinh viên, đưa vào mảng và duy trì tình trạng sắp xếp theo thứ tự từ điển của mảng.
Mỗi lần đưa một sinh viên vào mảng in ra vị trí chèn vào (vị trí bắt đầu từ 0). Việc nhập dừng khi name và email
có giá trị NULL.

INPUT:
Hoang hoang@hust
Long long@hust
NULL NULL

OUTPUT:
0 1
*/

#include <stdio.h>
#include <string.h>
#define MAX_L 256
#define MAX 100000

typedef struct Profile
{
    char name[MAX_L];
    char email[MAX_L];
} Profile;

Profile students[MAX];
int n = 0;
int positions[MAX];

void insert(char *name, char *email)
{
    // maintain increasing order of name
    int i = n - 1;
    while (i >= 0)
    {
        int c = strcmp(students[i].name, name);
        if (c == 0)
        {
            printf("Name %s exists, do not insert\n", name);
            return;
        }
        else if (c > 0)
        {
            students[i + 1] = students[i];
            i--;
        }
        else
            break;
    }
    i++; // increment i after shifting elements
    positions[n] = i; // store position
    strcpy(students[i].name, name);
    strcpy(students[i].email, email);
    n++;
}

int main()
{
    char name[256], email[256];
    while (scanf("%s%s", name, email) != EOF) 
    {
        if(strcmp(name, "NULL") == 0 && strcmp(email, "NULL") == 0)
            break;
        insert(name, email);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", positions[i]);
    }

    return 0;
}