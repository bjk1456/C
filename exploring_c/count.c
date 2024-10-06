#include <stdio.h>
main() /* count new lines in input */
{
    int c, nl, b;
    nl = 0;
    b = 0;
    c = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
          ++nl;
        }
        if (c == ' '){
            ++b;
        }
    } 
    printf("%d", b);
    printf(" %d", nl);
}