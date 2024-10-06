#include <stdio.h>
#include <string.h>
int main() {
    char line[1000];
    char above[1000];
    char keep[1000];
    int i = 0;

    while(gets(line) != NULL ) {
        strcpy(above, line);
          if(strcmp(above,keep) == 0){
            continue;
          }
          else{
            strcpy(keep, line);
          }
        
        printf("%s\n",keep);
        i++;
    }
}