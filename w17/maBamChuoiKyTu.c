#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 200
int n, m;

int hashCode(char *k)
{
    int c = 0;
    for (int i = 0; i < strlen(k); i++)
    {
        c = (c * 256 + k[i]) % m;
    }
    return c;
}

void solve()
{
    scanf("%d%d", &n, &m);
    char k[200];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", k);
        int h = hashCode(k);
        printf("%d\n", h);
    }
}

int main()
{
    solve();
    return 0;
}