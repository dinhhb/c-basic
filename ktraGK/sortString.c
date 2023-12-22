#include <stdio.h>
#include <string.h>

void selectionSort(char arr[][81], int n)
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
        // printf("temp = %s\n", temp);
        // printf("arr[%d] = %s\n", min_idx, arr[min_idx]);
        // printf("arr[%d] = %s\n", i, arr[i]);
        // printf("temp = %s\n", temp);
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
        // strncpy(temp, arr[min_idx], 80);
        // strncpy(arr[min_idx], arr[i], 80);
        // strncpy(arr[i], temp, 80);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char arr[n][81];
    char buffer[81 * n];
    fgets(buffer, sizeof(buffer), stdin);
    // printf("%d", buffer[strlen(buffer)-1] = "");
    // // buffer[strlen(buffer)-1] = "";
    buffer[strcspn(buffer, "\n")] = '\0';

    char *token = strtok(buffer, " ");

    int i = 0;
    while (token != NULL && i < n)
    {
        if (token)
        {
            strcpy(arr[i], token);
            i++;
        }
        token = strtok(NULL, " ");
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
    return 0;
}