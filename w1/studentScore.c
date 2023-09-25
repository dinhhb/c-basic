#include <stdio.h>
enum
{
    SUCCESS,
    FAIL,
    MAX_ELEMENT = 100
};

typedef struct
{
    int no;
    char id[9];
    char name[20];
    char phoneNumber[11];
    double score;
} student;

int main(void)
{
    FILE *fptr1, *fptr2;
    student arr[MAX_ELEMENT];
    int i = 0, n;
    int reval = SUCCESS;
    printf("Loading file...\n");
    if ((fptr1 = fopen("text/studentInfo.txt", "r")) == NULL)
    {
        printf("Can not open %s.\n", "studentInfo.txt");
        reval = FAIL;
    }

    if ((fptr2 = fopen("text/transcript.txt", "w")) == NULL)
    {
        printf("Can not open %s.\n", "transcript.txt");
        reval = FAIL;
    }
  
    while (fscanf(fptr1, "%d%s%s%s", &arr[i].no, arr[i].id, arr[i].name, arr[i].phoneNumber) != EOF)
    {
        i++;
    }
    n = i;
    for (i = 0; i < n; i++){
        printf("%-6d%-24s%-24s%-24s\nInput this student's score: ", arr[i].no, arr[i].id, arr[i].name, arr[i].phoneNumber);
        scanf("%lf", &arr[i].score);
        fprintf(fptr2,"%-6d%-24s%-24s%-24s%-6.2lf\n", arr[i].no, arr[i].id, arr[i].name, arr[i].phoneNumber, arr[i].score);
    }
    
    fclose(fptr1);
    fclose(fptr2);
    return reval;
}