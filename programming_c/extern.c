extern int var;
var = 0;

int bump()
{
  return var++;

  // Do something :)
}

/**
 * 

This is something about how an extern works in C:

    The extern keyword is used to declare a global variable that is defined in another file or later in the same file.

    An extern declaration tells the compiler that the variable exists but is defined elsewhere (this is critical), so no memory should be allocated to it during this declaration.

Therefore, for your code here:
extern int var = 0; // Declared var as extern and tried to initialize it at the same time // This is not allowed in C // Good practice extern int var; var = 0; // If you want to use a global variable across multiple files, which is the common usage for extern // Declare it in a header file // file1.h extern int var; // declare once // file1.c #include "file1.h" int i = 0; // define and initialize it elsewhere

Again, extern is meant for declarations, not for definitions.

 */