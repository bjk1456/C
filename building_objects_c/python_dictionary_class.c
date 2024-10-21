/* print(dct) */
/* {'z': 'W', 'y': 'B', 'c': 'C', 'a': 'D'} */
void pydict_print(struct pydict* self)
{
    printf("{");
       int i;
     struct dnode *node;
    for(i = 0; i < self-> count; i++){
      if(i == 0){
        node = self->head;
      }
      else{
        node = node->next;
      }
      char *key = node->key;
      char *value = node->value;
      if(i > 0){printf(", ");}
      printf("'");
      printf("%s': ", key);
      printf("'");
      printf("%s", value);
      printf("'");
    }
    printf("}\n");
}

int pydict_len(const struct pydict* self)
{
    return self->count;
}

/* find a node - used in get and put */
struct dnode* pydict_find(struct pydict* self, char *key)
{
    int i;
    struct dnode *node;
    for(i = 0; i < self->count; i++){
      if(i == 0){
        node = self->head;
      }
      else{
        node = node->next;
      }
      char *n_key = node->key;
      int result = strcmp(key, n_key);
     if (result == 0) {
        return node;
     }
    }
    
    return NULL;
}

/* x.get(key) - Returns NULL if not found */
char* pydict_get(struct pydict* self, char *key)
{
  struct dnode *node = pydict_find(self, key);
    if(node){return node->value;}
    return NULL;
}

/* x[key] = value; Insert or replace the value associated with a key */
void pydict_put(struct pydict* self, char *key, char *value)
{
  struct dnode *node = pydict_find(self, key);
  if(node){
    free(node->value);
    node->value = value;
  }
  else{
    struct dnode *new = (struct dnode *) malloc(sizeof(struct dnode));
    new->key = key;
    new->value = value;
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
     struct dnode *last;
    last = self->tail;
    last->next = new;
    self->tail = new;
    
    new->next = NULL;
  }
      
}
/*
The main program which will execute your code:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnode {
    char *key;
    char *value;
    struct dnode *next;
};

struct pydict {
  struct dnode *head;
  struct dnode *tail;
  int count;
};

/* Constructor - dct = dict() */
struct pydict * pydict_new() {
    struct pydict *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(dct) */
void pydict_del(struct pydict* self) {
    struct dnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

int main(void)
{
    struct dnode * cur;
    struct pydict * dct = pydict_new();

    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    pydict_put(dct, "z", "Catch phrase");
    pydict_print(dct);
    pydict_put(dct, "z", "W");
    pydict_print(dct);
    pydict_put(dct, "y", "B");
    pydict_put(dct, "c", "C");
    pydict_put(dct, "a", "D");
    pydict_print(dct);
    printf("Length =%d\n",pydict_len(dct));

    printf("z=%s\n", pydict_get(dct, "z"));
    printf("x=%s\n", pydict_get(dct, "x"));

    printf("\nDump\n");
    for(cur = dct->head; cur != NULL ; cur = cur->next ) {
        printf("%s=%s\n", cur->key, cur->value);
    }

    pydict_del(dct);
}

*/