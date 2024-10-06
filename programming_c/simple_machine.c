#include <stdio.h>

int main()
{
    char line[256];
    char memory[256];
    char opcode;
    int count,address,value;

    while(fgets(line, 256, stdin) != NULL) {
        if ( line[0] == 'X' ) break;
        if ( line[0] == '*' ) {
            printf("%s",line);
            continue;
        }
        count = sscanf(line, "%d %c %d", &address, &opcode, &value);
        if ( count != 3 ) continue;
        if ( opcode  == '+' ) {
          memory[address] = memory[address] + value;
        }
        if ( opcode  == '=' ) {
          memory[address] = value;
        }
        if ( opcode  == '-' ) {
          memory[address] = memory[address] - value;
        }

    }
    printf("Memory:\n%s\n", memory);
}