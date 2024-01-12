#include <stdio.h>
int move(int n, char A, char B, char C, int *cnt)
{
    if (n == 1)
    {
        (*cnt)++;
        // printf("Step %d: Move a disk from %c to %c\n", cnt, A, B);
    }
    else
    {
        move(n - 1, A, C, B, cnt);
        move(1, A, B, C, cnt);
        move(n - 1, C, B, A, cnt);
    }
    return *cnt;
}
int main()
{
    int cnt = 0;
    cnt = move(10, 'A', 'B', 'C', &cnt);
    printf("%d", cnt);
}