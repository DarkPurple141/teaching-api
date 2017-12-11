
#include "stack.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char * argv[]){
    printf("Testing new stack\n");
    Stack s = createStack();
    assert(s->size == 0); // <--- only valid as whitebox test
    /*
      Remember, a key tenet of the ADT is that we cannot know the
      inner workings of the implementation. Thus s->size access is invalid.
    */

    printf("Test passed\n");
    return 0;
}
