
#include "textbuffer.h"
#include <assert.h>
#include <stdio.h>

void testInit();
void testDump();
void testCopy();

int main() {

   testInit();
   testDump();
   testCopy();

   printf("All tests passed!\n");
   return 0;
}

void testCopy() {
   TB new = newTB("Some text!\nJeff\napple");
   assert(new);
   printf("%s\n", dumpTB(new));
   TB copy = copyTB(new, 1, 2);
   printf("copy = %s\n", dumpTB(copy));
   releaseTB(new);
   releaseTB(copy);
}

void testDump() {
   TB new = newTB("Some text!");
   assert(new);
   printf("%s\n", dumpTB(new));
   releaseTB(new);
   new = newTB("Some text!\nSome text\n");
   assert(new);
   printf("%s\n", dumpTB(new));
   releaseTB(new);
}

void testInit() {
   TB new = newTB("Some text!\n");
   assert(new);
   releaseTB(new);
}
