#include <stdio.h>
#include <string.h>

int main() {
    int first = 1;
    int val, maxval, minval;
    int MAX = 1000;
    char buf[MAX];

    while((fgets(buf, MAX, stdin)) != NULL){
        if(strcmp("done\n", buf) == 0){
             break;
        }
        val = atoi(buf);
        if ( first || val > maxval ) maxval = val;
        if ( first || val < minval ) minval = val;
        first = 0;
    } 
    printf("Maximum %d\n", maxval);
    printf("Minimum %d\n", minval);
    return 0;
}

