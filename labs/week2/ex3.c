
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Item safePop (Stack s) {
   if (stackSize(s) == 0) {
       printf ("syntax error in postfix expression\n");
       abort ();
   } else {
       return (pop(s));
   }
}

char validPop (char c) {
   if (c == ')') {
      return '(';
   } else if (c == ']') {
      return '[';
   } else {
      return '{';
   }
}

int main (int argc, char *argv[]) {
   Stack s;
   char *arg;
   int i;

   if (argc < 2) {
       printf ("No argument string provided\n");
       return 0;
   }

   arg = argv[1];

   s = createStack();

   // iterate through arg and check if matching
   for (i = 0; arg[i] != '\0'; i++) {
      if (arg[i] == '(' || arg[i] == '[' || arg[i] == '{') {
         push(s, arg[i]);
      } else if (arg[i] == ')' || arg[i] == ']' || arg[i] == '}') {
         if (safePop(s) != validPop(arg[i])) {
            abort();
         }
      }
   }

   stackSize(s) == 0 ? printf ("success\n") : printf ("fail\n");

   return 0;

}
