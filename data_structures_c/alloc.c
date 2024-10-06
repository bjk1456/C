#include <stdio.h>
#define NULL 0 /* pointer value for error report */
#define ALLOCSIZE 1000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(n) /* return pointer to n characters */
int n;
{
  if (allocp + n <= allocbuf + ALLOCSIZE) { /* fits */
    allocp += n;
    return(allocp - n); /* old p */
  } else /* not enough room */
    return (NULL);
}

free(p) /* free storage pointed to by p */
char *p;
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

C is consistent and regular in its approach to address arithmetic; its integration of pointers, arrays and address arithmetic is one of the major strengths of the language. Let us illustrate some of its properties by writing a rudimentary storage allocator (but useful in spite of its simplicity). There are two routines: alloc(n) returns a pointer p to n consecutive character positions, which can be used by the caller of alloc for storing characters; free(p) releases the storage thus acquired so it can be later re-used. The routines are "rudimentary" because the calls to free must be made in the opposite order to the calls made on alloc. That is, the storage managed by alloc and free is a stack, or last-in, first-out list. The standard C library provides analogous functions which have no such restrictions, and in Chapter 8 we will show improved versions as well. In the meantime, however, many applications really only need a trivial alloc to dispense little pieces of storage of unpredictable sizes at unpredictable times.

The simplest implementation is to have alloc hand out pieces of a large character array which we will call allocbuf. This array is private to alloc and free. Since they deal in pointers, not array indices, no other routine need know the name of the array, which can be declared external static, that is, local to the source file containing alloc and free, and invisible outside it. In practical implementations, the array may well not even have a name; it might instead be obtained by asking the operating system for a pointer to some unnamed block of storage.

The other information needed is how much of allocbuf has been used. We use a pointer to the next free element, called allocp. When alloc is asked for n characters, it checks to see if there is enough room left in allocbuf. If so, alloc returns the current value of allocp (i.e., the beginning of the free block), then increments it by n to point to the next free area. free(p) merely sets allocp to p if p is inside allocbuf.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Some explanations. In general a pointer can be initialized just as any other variable can, though normally the only meaningful values are NULL (discussed below) or an expression involving addresses of previously defined data of appropriate type. The declaration

static char *allocp = allocbuf;
defines allocp to be a character pointer and initializes it to point to allocbuf, which is the next free position when the program starts. This could have also been written

static char *allocp = &allocbuf[0];
since the array name is the address of the zeroth element; use whichever is more natural.

The test

if (allocp + n <= allocbuf + ALLOCSIZE)
checks if there's enough room to satisfy a request for n characters. If there is, the new value of allocp would be at most one beyond the end of allocbuf. If the request can be satisfied, alloc returns a normal pointer (notice the declaration of the function itself). If not, alloc must return some signal that no space is left. C guarantees that no pointer that validly points at data will contain zero, so a return value of zero can be used to signal an abnormal event, in this case, no space. We write NULL, instead of zero, however, to indicate more clearly that this is a special value for a pointer. In general, integers cannot meaningfully be assigned to pointers; zero is a special case.

Tests like

if (allocp + n <= allocbuf + ALLOCSIZE)
and

if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
show several important facets of pointer arithmetic. First, pointers may be compared under certain circumstances. If p and q point to members of the same array, then relations like <, >=, etc., work properly.

p > q
is true, for example, if p points to an earlier member of the array than does q. The relations == and != also work. Any pointer can be meaningfully compared for equality or inequality with NULL. But all bets are off if you do arithmetic or comparisons with pointers pointing to different arrays. If you're lucky, you'll get obvious nonsense on all machines. If you're unlucky, your code will work on one machine but collapse mysteriously on another.

Second, we have already observed that a pointer and an integer may be added or subtracted. The construction

p + n
means the n-th object beyond the one p currently points to. This is true regardless of the kind of object p is declared to point at; the compiler scales n according to the size of the objects p points to, which is determined by the declaration of p. For example, on the PDP-11, the scale factors are 1 for char, 2 for int and short, 4 for long and float, and 8 for double.

Pointer subtraction is also valid: if p and q point to members of the same array, p-q is the number of elements between p and q. This fact can be used to write yet another version of strlen:

strlen(s) /* return length of string s */
char *s;
{
  char *p = s;

  while(*p != '\0')
    p++;
  return(p-s);
}
In its declaration, p is initialized to s, that is, to point to the first character.

In the while loop, each character in turn is examined until the \0 at the end is seen. Since \0 is zero, and since while tests only whether the expression is zero, it is possible to omit the explicit test, and such loops are often written as

while (*p)
  p++;
Because p points to characters, p++ advances p to the next character each time, and p-s gives the number of characters advanced over, that is, the string length. Pointer arithmetic is consistent: if we had been dealing with float's, which occupy more storage than char's, and if p were a pointer to float, p++ would advance to the next float. Thus we could write another version of alloc which maintains, let us say, float's instead of char's, merely by changing char to float throughout alloc and free. All the pointer manipulations automatically take into account the size of the object pointed to, so nothing else has to be altered.

Other than the operations mentioned here (adding or subtracting a pointer and an integer; subtracting or comparing two pointers), all other pointer arithmetic is illegal. It is not permitted to add two pointers, or to multiply or divide or shift or mask them, or to add float or double to them.

