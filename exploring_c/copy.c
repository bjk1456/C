#include <stdio.h>
main() {
    int c;
  int p;
    while ((c = getchar()) != EOF) {
      if((c == ' ') && (p == ' ')){
        continue;
      }
      else{
        putchar(c);
      }
      p = c;
    } 
}