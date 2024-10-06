/* But if you ask Dr. Chuck's opinion, neither of these is ideal because in the real world we build data oriented loops that usually do a lot more than get one character from standard input. My formulation of a data loop will upset structured programming purists - but I write code in the real world so here is my version:*/

int c;
while (1) {
    c = getchar();
    if ( c == EOF ) break;
    /* process your data */
}
/* And if I wanted to skip blanks and new lines I could use both break and continue further angering the structured programming purists.*/

int c;
while (1) {
    c = getchar();
    if ( c == EOF ) break;
    if ( c == ' ' || c == '\n' ) continue;
    /* process your data */
}
/* I use this middle tested approach because usually the data I am processing is coming from a more complex source than the keyboard and I don't want a function with 2-3 parameters stuck in a side effect assignment statement in a while test. Also sometimes you want to exit a loop, not just based on the return value from the function, but instead based on the data structure that came back from the function itself.

As these "data processing loops" get more complex, the middle tested loop is a tried and true pattern. Even Kernighan and Ritchie point out its benefits above.

And with that, I have now triggered endless coffee shop conversations about the best way to write a data handling loop.*/