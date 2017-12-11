
#include "stack.h"
#include <stdlib.h>

// Stack.h
typedef struct _node *Node;

typedef struct _stackImp {
   Node head;
   int size;
} stackImp;

typedef struct _node {
   Item value;
   Node next;
} node;

// static functions
static Node newNode(Item value);
static Item destroyNode(Node n);

// init the node
static Node newNode(Item value) {
   Node new = calloc(1, sizeof(node));
   new->value = value;
   return new;
}

// desttory the node
static Item destroyNode(Node n) {
   Item toReturn = n->value;
   free(n);
   return toReturn;
}

//Function Prototypes
Stack createStack( void ) {
   Stack new = calloc(1, sizeof(stackImp));
   return new;
}

static void destroyHelper(Node n) {
   if (n != NULL) {
      Node temp = n->next; // <--- important to avoid accessing free'd member
      free(n);
      destroyHelper(temp);
   }
}

void destroyStack( Stack stack ) {
   destroyHelper(stack->head);
   free(stack);
}

// pops from top of stack
Item pop( Stack stack) {
   if (!stackSize(stack)) {
      abort();
   }
   Node head = stack->head;
   stack->head = stack->head->next;
   stack->size--;

   return destroyNode(head);
}

void push( Stack stack, Item data) {
   Node oldHead = stack->head;
   Node new = newNode(data);
   stack->head = new;
   new->next = oldHead;
   stack->size++;
}

int stackSize( Stack stack) {
   return stack->size;
}

#ifdef WHITEBOX
#include <assert.h>

int main() {
   Stack s = createStack();
   assert(s->size == 0);
   assert(s->head == NULL);
   return 0;
}
#endif
