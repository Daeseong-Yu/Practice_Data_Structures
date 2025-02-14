
#include "queue.h"

int main(void) {
	printf("Hello Queue-Data Structures\n");
	Queue* queue = NULL;

	initializedQueue(&queue);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	disPlayQueue(queue);
	QueueNode dequeueData;
	dequeueData = dequeue(queue);
	printf("Dequeued data - Value: %d / Next: %p\n", dequeueData.value, dequeueData.next);
	dequeueData = dequeue(queue);
	printf("Dequeued data - Value: %d / Next: %p\n", dequeueData.value, dequeueData.next);
	dequeueData = dequeue(queue);
	printf("Dequeued data - Value: %d / Next: %p\n", dequeueData.value, dequeueData.next);
	dequeueData = dequeue(queue);
	printf("Dequeued data - Value: %d / Next: %p\n", dequeueData.value, dequeueData.next);

	initializedQueue(&queue);
	freeQueue(queue);

	return SUCCEED;
}

int initializedQueue(Queue** queue) {
	if (!isQueueExist(*queue)) {
		printf("Queue is already initialized\n");
		return FAILED;
	}

	*queue = (Queue*)malloc(sizeof(Queue));
	if (*queue == NULL) {
		printf("[initializedQueue] Cannot allocate memory for queue\n");
		return FAILED;
	}

	(*queue)->front = NULL;
	(*queue)->tail = NULL;

	return SUCCEED;
}

int enqueue(Queue* queue, int value) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));

	if (newNode == NULL) {
		printf("[enqueue] Cannot allocate the memory for newNode\n");
		return FAILED;
	}

	newNode->value = value;
	newNode->next = NULL;

	if (isQueueEmpty(queue)) {
		queue->front = newNode;
	}
	else {
		queue->tail->next = newNode;
	}
	queue->tail = newNode;

	return SUCCEED;
}

QueueNode dequeue(Queue* queue) {
	QueueNode dequeuedData;
	memset(&dequeuedData, 0x0, sizeof(dequeuedData));
	if (isQueueEmpty(queue)) {
		printf("[dequeue] The queue is empty\n");
		return dequeuedData;
	}

	QueueNode* clearNode = NULL;
	memcpy(&dequeuedData, queue->front, sizeof(dequeuedData));
	clearNode = queue->front;
	queue->front = queue->front->next;
	free(clearNode);

	return dequeuedData;
}

void disPlayQueue(Queue* queue) {
	if (isQueueEmpty(queue)) {
		printf("[displayQueue] The queue is empty\n");
		return;
	}

	QueueNode* current = queue->front;

	while (current != NULL) {
		printf("Queue data: %d\n", current->value);
		current = current->next;
	}
}

void freeQueue(Queue* queue) {
	QueueNode* toBeDeleted = NULL;
	
	while (queue->front != NULL) {
		toBeDeleted = queue->front;
		queue->front = queue->front->next;
		free(toBeDeleted);
	}

	if (queue->front == NULL) {
		queue->tail = NULL;
	}
}

bool isQueueEmpty(Queue* queue) {
	return queue->front == NULL;
}

bool isQueueExist(Queue* queue) {
	return queue == NULL;
}