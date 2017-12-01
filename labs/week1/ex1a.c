
#include "list.h"
#include <assert.h>

int length(link ls) {
   assert(ls != NULL);
   int count = 0;
   while (ls != NULL) {
      count++;
      ls = ls->next;
   }
   return count;
}

int length(link ls) {
   if (ls != NULL) {
      return 1 + length(ls->next);
   } else {
      return 0;
   }
}

int length(link ls) {
   assert(ls != NULL);
   int count = 0;
   for (ls; ls != NULL; ls = ls->next) count++;

   return count;
}

link duplicate(link ls) {
   link new = NULL;
   link curr;

   if (ls != NULL) {
      new = newNode (ls->item);
      curr = new;
      ls = ls->next;

      for (ls; ls != NULL; ls = ls->next) {
         insertNext (curr, newNode (ls->item));
         curr = curr->next;
      }
   }


   return new;
}

// Create a new node, initialised with the item provided. Return
// pointer to node (link)
link newNode (Item item);

// Insert a new node into a given non-empty list
// The node is inserted directly after the head of the list ls
void insertNext (link ls, link node);

//Implementations
link newNode(Item item){
    link n = malloc(sizeof(*n));
    if (n == NULL) {
        printf ("Insufficient memory \n");
        abort();
    }
    n->item = item;
    n->next = NULL;
    return n;
}

void insertNext (link ls, link node) {
    assert (ls != NULL);
    assert (node != NULL);
    node->next = ls->next;
    ls->next = node;
}
