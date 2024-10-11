#include <stdio.h>
int main() {
   int i, v, arr[10];
   int finds;
   char f_msg[100];
   for(i=0;i<10;i++) {
       scanf("%d", &v);
       arr[i] = v;  
   }

   for(v=9; v>=0; v-- ) {
     char frst[100] = "numb[";
     char eye[5];
     
     eye[0] = v + '0';
     eye[1] = '\0';
     strcat(frst, eye);
     strcat(frst, "] =");
     printf("%s %d\n", frst, arr[v]);
   }
  	   printf("\n%s\n\n", "Searching for entries equal to 100");
       for(v=0; v<10; v++ ) {
         if(arr[v] == 100){
           printf("%s %d\n", "Found 100 at", v);
           finds++;
         }
       }
    strcat(f_msg, "Found ");
  char eye[5];
    eye[0] = finds + '0';
     eye[1] = '\0';
    strcat(f_msg, eye);
    printf("\n");
    strcat(f_msg, " entries with 100");
    
    printf("%s\n", f_msg);
}

/**
 * his will be provided as input to your program: Copy

9
5
100
16
18
20
6
100
1
77
Expected output from your program:
numb[9] = 77
numb[8] = 1
numb[7] = 100
numb[6] = 6
numb[5] = 20
numb[4] = 18
numb[3] = 16
numb[2] = 100
numb[1] = 5
numb[0] = 9

Searching for entries equal to 100

Found 100 at 2
Found 100 at 7

Found 2 entries with 100

 */