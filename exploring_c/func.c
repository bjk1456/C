#include <stdio.h>
int main() {
    int mymult(int,int);
    int retval;

    retval = mymult(6,7);
    printf("Answer: %d\n", retval);

    return 0;
}

int mymult(int a, int b)
{
    int c = a * b;
    return c;
}