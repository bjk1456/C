#include <stdio.h>
main() /* Fix this to be Celsius-Fahrenheit table */
{
    int cel;
    for (cel = 0; cel <= 100; cel = cel + 20)
        printf("%4d %6.1f\n", cel, ((1.8 * cel) + 32));
}