int day_of_year(pd) /* set day of year from month, day */
struct simpledate *pd;
{ 
    int i, day, leap;

    day = pd->day;
    leap = pd->year % 4 == 0 && pd->year % 100 != 0 || pd->year % 400 == 0;
    for (i = 1; i < pd->month; i++)
        day += day_tab[leap][i];
    return (day);
}

void dump_date(pd) /* print date from year, month, day */
struct simpledate *pd;
{
    char date[256];
    int k;
    for(k = 0; k < 256; k++){
     date[k] = '\0';
    }
    char char_year[256];
    char char_month[256];
    char char_day[256];
    sprintf(char_year, "%d", pd->year);
    sprintf(char_month, "%d", pd->month);
    sprintf(char_day, "%d", pd->day);
    
                char slash = '/';
           char slash_s[2] = {slash, '\0'};
            char zero = '0';
           char zero_s[2] = {zero, '\0'};
            strcat(date, char_year);
            strcat(date, slash_s);
            strcat(date, zero_s);
            strcat(date, char_month);
             strcat(date, slash_s);
           strcat(date, char_day);
      printf("%s\n", date);
    /* The date should be in the following format - note that */
    /* The month and day are always two digits with leading zeros */
    //printf("2023/03/07\n");
}


/**
 * #include <stdio.h>
#include <stdlib.h>

struct simpledate {
    int day;
    int month;
    int year;
};

static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


main() {
    void dump_date();
    printf("Playing with structures\n");
    struct simpledate sd;

    sd.year = 2023;
    sd.month = 2;
    sd.day = 11;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2023;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2024;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));
}

 */