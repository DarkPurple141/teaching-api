
#include <stdlib.h>

// Stack.h
typedef struct stackImp *Stack;
//Function Prototypes
Stack createStack( void );
void destroyStack( Stack stack );
Item pop( Stack stack);
void push( Stack stack, Item data);
int stackSize( Stack stack);

// TODO stack stacks on eachother
Stack stackStacks(Stack a, Stack b) {
   Stack super = createStack();


   return super;
}
