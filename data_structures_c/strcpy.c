Perhaps the most common occurrence of string constants is as arguments to functions, as in

printf("hello, world\n");
When a character string like this appears in a program, access to it is through a character pointer; what printf receives is a pointer to the character array.

Character arrays of course need not be function arguments. If message is declared as

char *message;
then the statement

message = "now is the time";
assigns to message a pointer to the actual characters. This is not a string copy; only pointers are involved. C does not provide any operators for processing an entire string of characters as a unit.

We will illustrate more aspects of pointers and arrays by studying two useful functions from the standard I/O library to be discussed in Chapter 7.

The first function is strcpy(s, t), which copies the string t to the string s. The arguments are written in this order by analogy to assignment, where one would say

s = t
to assign t to s. The array version is first:

EditCopyc_100_01strcpy(s, t) /* copy t to s */
char s[], t[];
{
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}
For contrast, here is a version of strcpy with pointers.

EditCopyc_100_02strcpy(s, t) /* copy t to s; pointer version 1 */
char *s, *t;
{
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}
Because arguments are passed by value, strcpy can use s and t in any way it pleases. Here they are conveniently initialized pointers, which are marched along the arrays a character at a time, until the \0 which terminates t has been copied to s.

In practice, strcpy would not be written as we showed it above. A second possibility might be

EditCopyc_100_03strcpy(s, t) /* copy t to s; pointer version 2 */
char *s, *t;
{
  while ((*s++ = *t++) != '\0')
  ;
}
This moves the increment of s and t into the test part. The value of *t++ is the character that t pointed to before t was incremented; the postfix ++ doesn't change t until after this character has been fetched. In the same way, the character is stored into the old s position before s is incremented. This character is also the value that is compared against \0 to control the loop. The net effect is that characters are copied from t to s up to and including the terminating \0.

As the final abbreviation, we again observe that a comparison against \0 is redundant, so the function is often written as

EditCopyc_101_01strcpy(s, t) /* copy t to s; pointer version 3 */
char *s, *t;
{
  while (*s++ = *t++)
  ;
}
Although this may seem cryptic at first sight, the notational convenience is considerable, and the idiom should be mastered, if for no other reason than that you will see it frequently in C programs.

The second routine is strcmp(s, t) , which compares the character strings s and t, and returns negative, zero or positive according as s is lexicographically less than, equal to, or greater than t. The value returned is obtained by subtracting the characters at the first position where s and t disagree.

EditCopyc_101_02strcmp(s, t) /* return <0 if s<t, 0 if s==t, >0 if s>t */
char s[], t[];
{
  int i;

  i = 0;

  while (s[i] == t[i])
    if (s[i++] == '\0')
      return (0);
  return(s[i] - t[i]);
}
The pointer version of strcmp:

EditCopyc_102_01strcmp(s, t) /* return <0 if s<t, 0 if s==t, >0 if s>t */
char *s, *t;
{
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return (0);
  return(*s - *t);
}
Since ++ and -- are either prefix or postfix operators, other combinations of * and ++ and -- occur, although less frequently. For example,

*++p
increments p before fetching the character that p points to;

*--p
decrements p first.