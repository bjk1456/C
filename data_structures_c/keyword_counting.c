#include <stdio.h>
#define MAXWORD 20
#define LETTER 'a'

main() /* count C keywords */

{
    int n, t;
    char word[MAXWORD];

    while ((t = getword (word, MAXWORD)) != EOF)
        if (t == LETTER)
            if ((n = binary(word, keytab, NKEYS)) >= 0)
                keytab[n].keycount++;

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].keycount > 0)
            printf("%4d %s\n",keytab[n].keycount, keytab[n].keyword);

}

binary(word, tab, n) /* find word in tab[0]...tab[n-1] */
char *word;
struct key tab[];
int n;
{
    int low, high, mid, cond;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].keyword)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return (mid);
    }
    return(-1);
}

/*
We will show the function getword in a moment; for now it suffices to say that it returns LETTER each time it finds a word, and copies the word into its first argument.

The quantity NKEYS is the number of keywords in keytab. Although we could count this by hand, it's a lot easier and safer to do it by machine, especially if the list is subject to change. One possibility would be to terminate the list of initializers with a null pointer, then loop along keytab until the end is found.

But this is more than is needed, since the size of the array is completely determined at compile time. The number of entries is just

size of keytab / size of struct key
C provides a compile-time unary operator called sizeof which can be used to compute the size of any object. The expression

sizeof(object)
yields an integer equal to the size of the specified object. (The size is given in unspecified units called "bytes," which are the same size as a char.) The object can be an actual variable or array or structure, or the name of a basic type like int or double, or the name of a derived type like a structure. In our case, the number of keywords is the array size divided by the size of one array element. This computation is used in a #define statement to set the value of NKEYS:

#define NKEYS (sizeof(keytab) / sizeof(struct key))
Now for the function getword. We have actually written a more general getword than is necessary for this program, but it is not really much more complicated. getword returns the next "word" from the input, where a word is either a string of letters and digits beginning with a letter, or a single character. The type of the object is returned as a function value; it is LETTER if the token is a word, EOF for end of file, or the character itself if it is non-alphabetic.
*/

#define LETTER 'a'
#define DIGIT  '0'

getword(w, lim) /* get next word from input */
char *w;
int lim;
{
    int c, t;
    if (type(c = *w++ = getch()) != LETTER) {
        *w = '\0';
        return(c);

    }

    while (--lim > 0) {
        t = type(c = *w++ = getch());
        if (t != LETTER && t != DIGIT) {
            ungetch(c);
            break;
        }
    }
    *(w-1) = '\0';
    return (LETTER);
}


/*

The symbolic constants LETTER and DIGIT can have any values that do not conflict with non-alphanumeric characters and EOF; the obvious choices are

#define LETTER 'a'
#define DIGIT  '0'
getword can be faster if calls to the function type are replaced by references to an appropriate array type []. The standard C library provides macros called isalpha and isdigit which operate in this manner.
*/