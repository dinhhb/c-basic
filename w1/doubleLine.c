#include <stdio.h>
#include <stdlib.h>

void double_space(FILE *, FILE *);
void print_info(char *);

int main(int argc, char **argv)
{
    FILE *ifp, *ofp;
    if (argc != 3)
    {
        print_info(argv[0]);
        exit(1);
    }
    ifp = fopen(argv[1], "r");
    ofp = fopen(argv[2], "w");
    double_space(ifp, ofp);
    fclose(ifp);
    fclose(ofp);
    return 0;
}
void double_space(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = fgetc(ifp)) != EOF)
    {
        fputc(c, ofp); /*nếugặpkýtựxuốngdòng–nhânđôinó */
        if (c == '\n')
            fputc('\n', ofp);
    }
}
void print_info(char *pgm_name)
{
    printf("\n%s%s%s\n\n%s\n\n",
           "Usage: ", pgm_name, " infile outfile",
           "The contents of infile will be double-spaced and written to outfile.");
}