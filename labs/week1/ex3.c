
#include "list.h"

typedef char Item;

typedef struct dnode *dlink;

struct dnode {
    Item  item;
    dlink next;
    dlink prev;
};

dlink append (dlink list1, dlink list2) {
   if (list1 == NULL) {
      return list2;
   } else if (list2 == NULL) {
      return list1;
   } else {
      link curr = list1;
      while (curr->next != NULL) {
         curr = curr->next;
      }
      curr->next = list2;
      list2->prev = curr;
   }

   return list1;
}
