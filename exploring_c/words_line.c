#include <stdio.h>
main() {
    int c;
    while ((c = getchar()) != EOF) {
      if((c == ' ') || (c == '\n')){
        printf("\n");
        continue;
      }
        putchar(c);
    }
}