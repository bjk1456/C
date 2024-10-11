void list_add(lst, value)
    struct list *lst;
    int value;
{
    /* Append the value to the end of the linked list. */
    struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
    new->value = value;
    if(lst->head == NULL){
      new->next = NULL;
      lst->head = new;
      lst->tail = new;
      return;
    }
    struct lnode *last;
    last = lst->tail;
    last->next = new;
    lst->tail = new;
    new->next = NULL;
  
}

void list_remove(lst, value)
    struct list *lst;
    int value;
{
    /* Remove the value from the linked list. */
    struct lnode * cur;
    struct lnode * next;
    for(cur=lst->head; cur != NULL; cur=cur->next) {
       next = cur->next;      
      if(lst->head->value == value){
        cur->next = NULL;
        lst->head = next;
        next->next = lst->head->next;
        break;
      }
       if(next->value == value){
        cur->next = next->next;
      }

      if(next->value == lst->tail->value){
        lst->tail = cur;
        break;
      }
     
    }
    return NULL;
}

/*
#include <stdio.h>
#include <stdlib.h>

struct lnode {
    int value;
    struct lnode *next;
};

struct list {
  struct lnode *head;
  struct lnode *tail;
};

int main()
{
    void list_add();
    void list_dump();
    struct lnode * list_find();

    struct list mylist;
    struct lnode * mynode;

    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);
    list_dump(&mylist);

    list_remove(&mylist, 42);

    list_remove(&mylist, 10);
    list_dump(&mylist);

    list_remove(&mylist, 30);
    list_dump(&mylist);

    list_add(&mylist, 40);
    list_dump(&mylist);

}

void list_dump(lst)
    struct list *lst;
{
    struct lnode *cur;
    printf("\nDump:\n");
    for(cur=lst->head; cur != NULL; cur=cur->next) {
        printf("  %d\n", cur->value);
    }
}
*/