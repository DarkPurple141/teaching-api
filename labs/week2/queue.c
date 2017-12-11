
#include "stack.h"
#include <stdlib.h>

// DO THIS YOURSELF!

// Queue.h
typedef struct queueImp *Queue;
//Function Prototypes
Queue createQueue( void );
void destroyQueue( Queue queue );
Item get( Queue queue);
void put( Queue queue, Item data);
int queueSize( Queue queue);
