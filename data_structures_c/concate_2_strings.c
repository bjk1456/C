#include <stdio.h>
#include <string.h>
int main() {
    char str1[1000], str2[1000], conc[2000], temp[1000];

    printf("Enter two strings\n");
    scanf("%s", str1);
    scanf("%s", str2);
  
    strcpy(conc, str1);
    strcat(conc, " & ");
    strcat(conc, str2);
    
    printf("%s", conc); 
}