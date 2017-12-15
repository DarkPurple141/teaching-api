#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main(void) {
	// your code goes here
	int i;
	int j = 0;
	Queue q =  newQueue();

	while (fscanf(stdin, "%d", &i) != EOF) {
		enterQueue(q,i);
		j++;
	}
	assert(getNumItems(q) == j);
	showQueue(q);
	while (!isQueueEmpty(q)) {
		i = leaveQueue(q);
		showQueue(q);
	}
	return 0;
}
