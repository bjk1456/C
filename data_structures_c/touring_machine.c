#include <stdio.h>

int main()
{
    char memory[256], token[256];
    int position = 0, value;

    while(scanf("%s",token) == 1 ) {
        if(*token == '>'){
          position += 1;
        }
        else if(*token == '<'){
          position -= 1;
        }
        else{
          char temp[256];
          int k;
          for(k = 0; k < 256; k++){
            temp[k] = '\0';
           }
          int j;
          for(j = 0; j < 15;j++){
           char ch = token[j];
           char tmp[2] = {ch, '\0'};
            strcat(temp, tmp);
          }
          int the_num = atoi(temp);
          memory[position] = the_num;
        }
    }
    printf("Memory:\n%s\n", memory);
}

/*
This will be provided as input to your program: Copy

42 > 114 > 105 > 97 > 
110 < < < < 66
Expected output from your program:
Memory:
Brian
*/