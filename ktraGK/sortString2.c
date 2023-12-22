#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 81

void selectionSort(char arr[][MAX_LENGTH], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        char temp[81];
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
        // strncpy(temp, arr[min_idx], 80);
        // strncpy(arr[min_idx], arr[i], 80);
        // strncpy(arr[i], temp, 80);
    }
}

int main() {
    int n;
    char arr[MAX_WORDS][MAX_LENGTH];
    char inputLine[MAX_WORDS * MAX_LENGTH];

    // Read the number of words
    if (scanf("%d\n", &n) != 1) {
        fprintf(stderr, "Error reading the number of words\n");
        return 1;
    }

    // Validate the number of words
    if (n < 1 || n > MAX_WORDS) {
        fprintf(stderr, "Invalid number of words\n");
        return 1;
    }

    // Read the entire line
    if (fgets(inputLine, sizeof(inputLine), stdin) == NULL) {
        fprintf(stderr, "Error reading input line\n");
        return 1;
    }

    // Remove newline character if present
    inputLine[strcspn(inputLine, "\n")] = '\0';

    // Split the input line into words and store them in the array
    char *token = strtok(inputLine, " ");
    int i = 0;
    while (token != NULL && i < n) {
        strncpy(arr[i], token, MAX_LENGTH - 1);
        arr[i][MAX_LENGTH - 1] = '\0'; // Ensure null-termination
        i++;
        token = strtok(NULL, " ");
    }

    // Sort the array of words
    selectionSort(arr, n);

    // Print the sorted words
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}