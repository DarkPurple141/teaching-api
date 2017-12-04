
#include "stack.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char * argv[]){
    printf("Testing new stack\n");
    Stack s = createStack();
    assert(s->size == 0); // <--- only valid as whitebox test
    printf("Test passed\n");
    return 0;
}
