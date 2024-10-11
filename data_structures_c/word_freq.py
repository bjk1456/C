A classic early assignment in any programming language is a "word frequency" program. Here is a Python program from my Python for Everybody course to count words from an input stream:

handle = open('romeo.txt', 'r')
words = handle.read().split()
counts = dict()
for word in words:
    counts[word] = counts.get(word,0) + 1
print(counts)
This section implements a less general word counting program in C. The code depends on several functions from earlier in the book, and the code below is pretty complex, where the programmer only has access to a low-level language without powerful and easy-to-use data types like list or dict.

It is likely that, Guido van Rossum, read this book, took a look at this code and designed the dict data structure in Python so that the rest of us could write a data parsing and word frequency program in the above six lines of code without worrying about dynamic memory allocation, pointer management, string length and a myriad of other details that must be solved when solving the problem in C

Since Python is open source, you can actually look at the C code that implements the dict object in a file called dictobject.c. It is almost 6000 lines of code and includes 11 other files of utility code. Thankfully we only have to write one line in Python to use it:

counts = dict()
We will leave the complex bits to the C programmers that build and maintain Python.

This section is not showing us how to use the Python dict object - rather it is showing how one would build a dict-like structure using C.

https://github.com/python/cpython/blob/main/Objects/dictobject.c

