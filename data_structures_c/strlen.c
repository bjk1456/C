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