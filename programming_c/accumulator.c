#include <stdio.h>

int main()
{
    char line[256];
    char opcode;
    float value, display = 0.0;
    float total = 0;

    while(fgets(line, 256, stdin) != NULL) {
        // Use sscanf to parse data from a string
        sscanf(line, "%c %f", &opcode, &value);
        if ( opcode == 'S' ) break;
        if ( opcode == '=' ) total = value;
        if ( opcode == '+' ) total = total + value;
        if ( opcode == '*' ) total = total * value;
        if ( opcode == '/' ) total = total / value;
         if ( opcode == '-' ) total = total - value;
        /* Replace this with your code */
        display = total;
        printf("Display: %.2f\n", display);
    }
}