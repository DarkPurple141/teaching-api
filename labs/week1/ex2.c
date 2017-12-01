
#include "list.h"


typedef struct _listImpl *list;

typedef struct _listImpl {
   int size;
   link first;
   link last;
} listImpl;

list newList() {
   return calloc(1, sizeof(listImpl));
}

list newList() {
   list new = malloc(sizeof(listImpl));

   new->size = 0;
   new->first = NULL;
   new->last = NULL;

   return new;
}




// TODO change this code in tutorial
link reverse (link ls) {
   link tmp;
   link curr = ls;
   link rev  = NULL;
   while (curr != NULL) {
      tmp = curr->next;
      curr->next = rev;
      rev  = curr;
      curr = tmp;
   }
   return rev;
}

void insertNext(link ls, link node);
void deleteNext(link ls);
