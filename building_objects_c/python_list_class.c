/* print(lst) */
void pylist_print(struct pylist* self)
{
  printf("[");
       int i;
     struct lnode *node;
    for(i = 0; i < self-> count; i++){
      if(i == 0){
        node = self->head;
      }
      else{
        node = node->next;
      }
      char *text = node->text;
      if(i > 0){printf(", ");}
      printf("'");
      printf("%s", text);
      printf("'");
      
    }
    printf("]\n");
}

/* len(lst) */
int pylist_len(const struct pylist* self)
{
    /* One line of code */
    return self->count;
}

/* lst.append("Hello world") */
void pylist_append(struct pylist* self, char *str) {
    //printf("pylist_append %s\n", self->head->text);
    struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
    new->text = str;
    if(self->head == NULL){
      int count = 1;
      self->count = count;
      new->next = NULL;
      self->head = new;
      self->tail = new;
    }
    else{
      self->count = self->count + 1;
    }
    struct lnode *last;
    last = self->tail;
    last->next = new;
    self->tail = new;
    
    new->next = NULL;

}
/* lst.index("Hello world") - if not found -1 */
int pylist_index(struct pylist* self, char *str)
{
     int i;
     struct lnode *node;
    for(i = 0; i < self-> count; i++){
      if(i == 0){
        node = self->head;
      }
      else{
        node = node->next;
      }
      char *text = node->text;
      int result = strcmp(str, text);
     if (result == 0) {
        return i;
     }
    }
  return -1;
}


/**
 * The main program which will execute your code:
 * #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *text;
    struct lnode *next;
};

struct pylist {
  struct lnode *head;
  struct lnode *tail;
  int count;
};

/* Constructor - lst = list() */
struct pylist * pylist_new() {
    struct pylist *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(lst) */
void pylist_del(struct pylist* self) {
    struct lnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->text);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    struct pylist * lst = pylist_new();
    pylist_append(lst, "Hello world");
    pylist_print(lst);
    pylist_append(lst, "Catch phrase");
    pylist_print(lst);
    pylist_append(lst, "Brian");
    pylist_print(lst);
    printf("Length = %d\n", pylist_len(lst));
    printf("Brian? %d\n", pylist_index(lst, "Brian"));
    printf("Bob? %d\n", pylist_index(lst, "Bob"));
    pylist_del(lst);
}

 */