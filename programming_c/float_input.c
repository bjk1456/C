#include "stdio.h"

main () {
      float total = 0;
      float avg = 0;
      int count = 0;
      float num;
    while(scanf("%f",&num) != EOF ) {
        total += num;
        count += 1;
    }
    avg = total / count;
  printf("The total is: %.1f\n", total);
  printf("The average is: %.1f\n", avg);