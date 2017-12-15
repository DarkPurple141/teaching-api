#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"

typedef struct _queue * Queue;
typedef struct _node * Link;

typedef struct _queue
{
	Link first;
	Link last;
	int items;

} queue;

typedef struct _node
{
	Link next;
	int data;
} node;

int getNumItems(Queue q) {
	assert(q!=NULL);
	return q->items;
}

void destoryQueue(Queue q) {
	assert(q!=NULL);
	Link curr = q->first;
	while (curr != NULL) {
		Link prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(q);
}

int isQueueEmpty(Queue q) {
	assert(q!=NULL);
	return q->items ? 0 : 1;
}

Queue newQueue(void) {
	Queue q = malloc(sizeof(queue));
	q->items=0;
	q->first=NULL;
	q->last=NULL;
	return q;
}

void enterQueue(Queue q, int item) {
	assert(q!=NULL);
	Link new = malloc(sizeof(node));
	new->data = item;

	if (isQueueEmpty(q)) {
		q->first = new;
		q->last = new;
	} else {
		if (q->first == q->last) {
			q->last = new;
			q->first->next = new;
		} else {
			q->last->next = new;
			q->last = new;
		}
	}
	q->items++;
	new->next = NULL;

} 

int leaveQueue(Queue q) {
	assert(q!=NULL);
	int returnval;

	if (isQueueEmpty(q)) {
		destoryQueue(q);
		returnval = 0;
	} else {
		returnval = q->first->data;
		if (q->first == q->last) {
			q->last = NULL;
		}
		q->items--;
		q->first = q->first->next;
		free(q->first);
	}
	return returnval;
}

void showQueue(Queue q) {
	assert(q!=NULL);
	Link curr = q->first;
	while (curr) {
		printf("[%d]->",curr->data);
		curr = curr->next;
	}
	printf("[X]\n");
}

