
#include "stack.h"
#include <stdlib.h>

// TODO MAKE YOUR OWN STACK IMPL USING A LINKED LIST

// Stack.h
typedef struct _stackNode * link;

typedef struct _stackNode {
   Item value;
   link next;
    //You need to decide what goes in here
} stackNode;

typedef struct _stackImp {
   link top;
   int size;
} stackImp;


static link createNode(Item item);

Stack createStack( void ) {

   Stack new = calloc(1, sizeof(stackImp));

   return new;
}

void destroyStack( Stack stack );

Item pop( Stack stack) {
   Item retVal;
   if (stack->top != NULL) {
      top = stack->top;
      stack->top = top->next;
      retVal = top->value;
      stack->size--;
      free(top);
   } else {
      abort()
   }

   return retVal;
}
void push( Stack stack, Item data);
int stackSize( Stack stack);
