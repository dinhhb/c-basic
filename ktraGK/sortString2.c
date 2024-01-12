/*
Cho một mảng chứa n (n <= 500) xâu có độ dài tối đa 80 kí tự, hãy dùng một thuật toán sắp xếp đã học 
(chèn, lựa chọn, nổi bọt) để sắp xếp mảng theo thứ tự tăng dần theo thứ tự từ điển. 
Đầu vào có dòng đầu là n, dòng thứ hai chứa n xâu. Đầu ra là mảng đã sắp xếp in ra trên n dòng, mỗi xâu trên một dòng
Ví dụ:
INPUT
3
Hello my friend
OUTPUT
friend
Hello
my
*/

#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 500
#define MAX_LENGTH 81

void bubbleSort(char arr[][MAX_LENGTH], int n) {
    int i, j;
    char temp[MAX_LENGTH];
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

int main() {
    int n, i = 0;
    char strings[MAX_STRINGS][MAX_LENGTH];
    char input_line[MAX_STRINGS * MAX_LENGTH];
    char *token;

    // Reading the number of strings
    scanf("%d", &n);

    // Clearing the input buffer
    while (getchar() != '\n');

    // Reading the entire line
    fgets(input_line, sizeof(input_line), stdin);

    // Splitting the line into tokens
    token = strtok(input_line, " ");
    while (token != NULL && i < n) {
        strncpy(strings[i], token, MAX_LENGTH);
        strings[i][strcspn(strings[i], "\n")] = 0; // Remove newline character
        i++;
        token = strtok(NULL, " ");
    }

    // Adjust the actual number of strings read
    n = i;

    // Sorting the strings
    bubbleSort(strings, n);

    // Printing the sorted strings
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
