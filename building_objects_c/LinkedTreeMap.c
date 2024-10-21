struct TreeMapEntry {
    char *key;  /* public */
    int value;  /* public */
    struct TreeMapEntry *__next;
    struct TreeMapEntry *__left;
    struct TreeMapEntry *__right;
};

struct TreeMapIter {
   struct TreeMapEntry *__current;

   struct TreeMapEntry* (*next)(struct TreeMapIter* self);
   void (*del)(struct TreeMapIter* self);
};

void __TreeMapIter_del(struct TreeMapIter* self) {
    free((void *)self);
}

struct TreeMap {
   /* Attributes */
   struct TreeMapEntry *__head;
   struct TreeMapEntry *__root;
   int __count;
   int debug;

   /* Methods */
   void (*put)(struct TreeMap* self, char *key, int value);
   int (*get)(struct TreeMap* self, char *key, int def);
   int (*size)(struct TreeMap* self);
   void (*dump)(struct TreeMap* self);
   struct TreeMapIter* (*iter)(struct TreeMap* self);
   void (*del)(struct TreeMap* self);
};

void __TreeMap_del(struct TreeMap* self) {
    struct TreeMapEntry *cur, *next;
    cur = self->__head;
    while(cur) {
        free(cur->key);
        /* value is just part of the struct */
        next = cur->__next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

void __TreeMap_put(struct TreeMap* self, char *key, int value) {
    struct TreeMapEntry *cur, *left, *right;
    int cmp;
    struct TreeMapEntry *old, *new;
    char *new_key;
    new_key = malloc(sizeof(*key));
    strcpy(new_key, key);

    cur = self->__root;
    left = NULL;
    right = NULL;

    /* Loop through the tree from the root.  If the matches
     * the node, update the value and return.  Ad the tree is scanned,
     * keep track of the node containing largest key less than "key"
     * in the variable left and the node containing the smallest key
     * greater than "key" in the variable "right".  So if the key is
     * not found, left will be the closest lower neighbor or null
     * and right will be the closest greater neighbor or null.
     */
  while(cur != NULL ) {
    cmp = strcmp(key, cur->key);
    
    //We have a match
    if(cmp == 0 ) {
      cur->value = value;
      return;
    }
    
    if( cmp < 0 ) { /* Turn left */
        right = cur;
        cur = cur->__left;
    }  else { /* Turn right */
         left = cur;
         cur = cur->__right;
     }
   }

    /* Not found - time to insert into the linked list after old */
    new = malloc(sizeof(*new));
    new->key = new_key;
    new->value = value;


    /* Set up the new node with its new data. */

    /* Empty list - add first entry */
    if ( self->__head == NULL ) {
        self->__head = new;
        self->__root = new;
        self->__count = self->__count + 1;
        return;
    }

   if ( left != NULL ) {
        new->__next = right;
        left->__next = new;
   } else {
        new->__next = self->__head;
        self->__head = new;
   }
   // Insert into the tree
   if ( right != NULL && right->__left == NULL ) {
        right->__left = new;
        self->__count = self->__count + 1;
   } else if (left != NULL && left->__right == NULL ) {
       left->__right = new;
       self->__count = self->__count + 1;
   } else {
     printf("FAIL!\n");
   }
}

int __TreeMap_get(struct TreeMap* self, char *key, int def)
{
    int cmp;
    struct TreeMapEntry *cur;

    if ( self == NULL || key == NULL || self->__root == NULL ) return def;

    cur = self->__root;

    /* TODO: scan down the tree and if the key is found, return the value.
     * If the key is not found, return the default value (def).
     */
  while(cur != NULL ) {
    cmp = strcmp(key, cur->key);
    if(cmp == 0) return cur->value;
    else if(cmp < 0) cur = cur->__left;
    else cur = cur->__right;
    }

    return def;
}

struct TreeMapEntry* __TreeMapIter_next(struct TreeMapIter* self)
{
    /* Advance the iterator.  Recall that when we first 
     * create the iterator __current points to the first item
     * so we must return an item and then advance the iterator.
     */
      struct TreeMapEntry *current, *next;
      current = self->__current;
      next = current->__next;
      self->__current = next;
      return current;
}

int __TreeMap_size(struct TreeMap* self)
{
    return self->__count;
}

struct TreeMapIter* __TreeMap_iter(struct TreeMap* self)
{
    struct TreeMapIter *iter = malloc(sizeof(*iter));
    iter->__current = self->__head;
    iter->next = &__TreeMapIter_next;
    iter->del = &__TreeMapIter_del;
    return iter;
}

void __TreeMap_dump_tree(struct TreeMapEntry *cur, int depth)
{
    int i;
    if ( cur == NULL ) return;
    for(i=0;i<depth;i++) printf("| ");
    printf("%s=%d\n", cur->key, cur->value);
    if ( cur->__left != NULL ) {
        __TreeMap_dump_tree(cur->__left, depth+1);
    }
    if ( cur->__right != NULL ) {
        __TreeMap_dump_tree(cur->__right, depth+1);
    }
}

void __TreeMap_dump(struct TreeMap* self)
{
    struct TreeMapEntry *cur;
    printf("Object TreeMap count=%d\n", self->__count);
    for(cur = self->__head; cur != NULL ; cur = cur->__next ) {
         printf("  %s=%d\n", cur->key, cur->value);
    }
    printf("\n");
    __TreeMap_dump_tree(self->__root, 0);
    printf("\n");
}

struct TreeMap * TreeMap_new() {
    struct TreeMap *p = malloc(sizeof(*p));

    p->__head = NULL;
    p->__root = NULL;
    p->__count = 0;
    p->debug = 0;

    p->put = &__TreeMap_put;
    p->get = &__TreeMap_get;
    p->size = &__TreeMap_size;
    p->dump = &__TreeMap_dump;
    p->iter = &__TreeMap_iter;
    p->del = &__TreeMap_del;
    return p;
}

/**
 * 
 * The main program which will execute your code:
 * 
 * #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "student.c"

/**
 * The main program to read, parse, and count words
 */
int main(void)
{
    struct TreeMap * map = TreeMap_new();
    struct TreeMapEntry *cur;
    struct TreeMapIter *iter;
    char word[100];  /* Yes, this is dangerous */
    int i,j;
    int count, maxvalue;
    char *maxkey;

    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    /* Turn off debug */
    map->debug = 0;

    /* Loop over each word in the file */
    while (scanf("%s", word) != EOF) {
        for (i=0, j=0; word[i] != '\0'; i++) {
            if ( ! isalpha(word[i]) ) continue;
            word[j++] = tolower(word[i]);
        }
        word[j] = '\0';
        count = map->get(map, word, 0);
        map->put(map, word, count+1);
    }

    maxkey = NULL;
    maxvalue = -1;
    iter = map->iter(map);
    while(1) {
        cur = iter->next(iter);
        if ( cur == NULL ) break;
        if ( maxkey == NULL || cur->value > maxvalue ) {
            maxkey = cur->key;
            maxvalue = cur->value;
        }
    }
    iter->del(iter);
    printf("\n%s %d\n", maxkey, maxvalue);

    map->del(map);
}

 */

/**
 * 
 * People in this forum expressed having  difficulty with the last two assignments. Having just finished all assignments for week 6 let me offer some advice: Be very careful with your pointers. Any time you're creating pointer you need to allocate space for it in memory. This includes keys for key value pairs! Dr Chuck even gave us a hint by giving us a new key pointer in the map put code. If you don't do this the map entry key will point to the same place in memory multiple times which can cause counts to be off like in the last assignment for this week. 

For the Build a linkedTreeMap assignment you don't strictly need to allocate memory for the key, you'll still pass that assignment. This is because every key is allocated on main's stack frame and is unique, but this will cause a problem when you try to port your code over to the last assignment. With the counting words assignment we  have duplicate words being read in from a file and they aren't saved anywhere in memory. If you didn't allocate memory for the key, you'll always be pointing to whatever  word is currently being read in by the file. Which is causing you to count each word in the file, instead of how many words are in each file.


The solution is to change your __TreeMap_put code to do the following things:

using  malloc, allocate enough space in memory to hold the key string.

copy the key string into the newly allocated space.

have your TreeMapEntry key member point to this newly allocated space.
 * 
 */