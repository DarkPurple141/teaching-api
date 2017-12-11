
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {

   // some basic black box tests
   Tree new = newTree();
   for (int i = 0; i < 10; i++) {
      Item toAdd = rand()%10;
      addToTree(new, toAdd);
      assert(contains(new, toAdd));
   }
   printTree(new);

   destroyTree(new);

   return 0;
}
