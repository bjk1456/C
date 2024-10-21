/*
"Adding Support for User-defined Classes" :
https://python-history.blogspot.com/2009/02/adding-support-for-user-defined-classes.html
*/

/* x = x + 'h'; */

void pystr_append(struct pystr* self, char ch) {
    /* Need about 10 lines of code here */
     if(self->length + 2 == self->alloc){
       self->alloc = self->alloc + 10;
       self->data = (char *)
           realloc(self->data, self->alloc);
     }
     self->data[self->length] = ch;
     int null_pos = self->length + 1;
     int new_length = self->length + 1;
     self->data[null_pos] = NULL;
     self->length = new_length;
}

/* x = x + "hello"; */

void pystr_appends(struct pystr* self, char *str) {
    /* Need a line or two of code here */
    int i = 0;
    while(1){
      if(*(str + i) == '\0'){break;}
      pystr_append(self, *(str + i));
      i++;
    }
}

/* x = "hello"; */

void pystr_assign(struct pystr* self, char *str) {
    /* Need about three lines of code here */
      int i = 0;
      int num_blocks = 0;
      int alloc = 0;

    while(1){
      if(*(str + i) == '\0'){break;}
      i++;
    }
    
    num_blocks = (i / 10) + 1;
    self->length = 0;
    self->alloc = num_blocks * 10;
    self->data = malloc(num_blocks * 10);
    pystr_appends(self, str);
    
}
/**
 * The main program which will execute your code:
 * 
 * #include <stdio.h>
#include <stdlib.h>

struct pystr
{
    int length;
    int alloc; /* the length of *data */
    char *data;
};

/* Constructor - x = str() */
struct pystr * pystr_new() {
    struct pystr *p = malloc(sizeof(*p));
    p->length = 0;
    p->alloc = 10;
    p->data = malloc(10);
    p->data[0] = '\0';
    return p;
}

/* Destructor - del(x) */
void pystr_del(const struct pystr* self) {
    free((void *)self->data); /* free string first */
    free((void *)self);
}

void pystr_dump(const struct pystr* self)
{
    printf("Pystr length=%d alloc=%d data=%s\n",
            self->length, self->alloc, self->data);
}

int pystr_len(const struct pystr* self)
{
    return self->length;
}

char *pystr_str(const struct pystr* self)
{
    return self->data;
}


int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    struct pystr * x = pystr_new();
    pystr_dump(x);

    pystr_append(x, 'H');
    pystr_dump(x);

    pystr_appends(x, "ello world");
    pystr_dump(x);

    pystr_assign(x, "A completely new string");
    printf("String = %s\n", pystr_str(x));
    printf("Length = %d\n", pystr_len(x));
    pystr_del(x);
}
 */