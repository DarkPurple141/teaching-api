

typedef struct _queue queue;
typedef struct _node node;
typedef struct _queue * Queue;
typedef struct _node * Link;


// new Queue
Queue newQueue(void);

// add item to queue
void enterQueue(Queue q, int item);

// check empty
int isQueueEmpty(Queue q);

// leave queue
int leaveQueue(Queue q);

// show queue
void showQueue(Queue q);

// delete the queue
void destoryQueue(Queue q);

// getnum_items
int getNumItems(Queue q);