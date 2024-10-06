#include <stdio.h>

int main() {

    int MAX = 1000;
    char buf[MAX];
    printf("Enter line\n");
    fgets(buf, MAX, stdin);
    printf("Line: %s\n", buf);

    return 0;
}