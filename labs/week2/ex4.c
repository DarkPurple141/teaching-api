
#include <assert.h>
#include <stdio.h>

// a + b
int adder(int a, int b) {
   return a + b;
}

int main() {

   assert(adder(21, 21) == 42);
   assert(adder(-21, 21) == 0);

   printf("ALL TESTS PASSED!\n");

   return 0;
}
