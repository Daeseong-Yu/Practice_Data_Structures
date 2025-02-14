#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FAILED	-1
#define SUCCEED	0

typedef struct QueueNode {
	int value;
	struct QueueNode* next;
} QueueNode;

typedef struct Queue {
	struct QueueNode* front;
	struct QueueNode* tail;
} Queue;

int initializedQueue(Queue** queue);
int enqueue(Queue* queue, int value);
QueueNode dequeue(Queue* queue);
void disPlayQueue(Queue* queue);
bool isQueueEmpty(Queue* queue);
bool isQueueExist(Queue* queue);
void freeQueue(Queue* queue);