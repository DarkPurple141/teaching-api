
#include <assert.h>
#include <stdio.h>

// a + b
int adder(int a, int b) {
   // return 42
   return a + b;
}

int main() {

   // A basic example of triangulation
   assert(adder(21, 21) == 42);
   assert(adder(-21, 21) == 0);

   printf("ALL TESTS PASSED!\n");

   return 0;
}
