
#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

   Stack s = createStack();
   assert(stackSize(s) == 0);
   printf("Stack Test\n=========\n");

   for (size_t i = 0; i < 5; i++) {
      push(s, i);
      assert(stackSize(s) == i + 1);
   }
   printf("\t--> Push tests passed!\n");

   for (size_t i = 0; i < 5; i++) {
      assert(stackSize(s) == 5 - i);
      pop(s);
   }
   printf("\t--> Pop tests passes!\n");

   destroyStack(s);
   printf("All tests passed!\n");

   return 0;
}
