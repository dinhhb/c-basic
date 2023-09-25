#include <stdio.h>
#define STRING_LEN 100
void replace(char str[], char replace_what, char replace_with)
{
    int i;
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == replace_what)
            str[i] = replace_with;
    }
}
int main(void)
{
    char str[STRING_LEN + 1];
    char replace_what, replace_with, tmp;
    printf("Please enter a string (no spaces)\n");
    scanf("%100s", str); // reads a string up to a maximum of 100 characters
    printf("Letter to replace: ");
    scanf(" %c", &replace_what); // consume any whitespace characters,
                                 // including the newline character,
                                 // left in the input buffer from previous inputs

    do                           // keeps reading characters until a newline is encountered, 
    {                            // effectively clearing the input buffer.
        tmp = getchar();
    } while (tmp != '\n');
    printf("Letter to replace with: ");
    scanf(" %c", &replace_with);
    replace(str, replace_what, replace_with);
    printf("The result: %s\n", str);
    return 0;
}