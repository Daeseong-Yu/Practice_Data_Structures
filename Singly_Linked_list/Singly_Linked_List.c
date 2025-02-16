#include "Singly_Linked_List.h"

int main(void) {
	dataNode* head = NULL;

	insertNewNode(&head, 1);
	insertNewNode(&head, 2);
	insertNewNode(&head, 3);
	insertNewNode(&head, 4);
	insertNewNode(&head, 5);
	insertNewNode(&head, 6);
	insertNewNode(&head, 7);

	viewList(head);

	return SUCCEED;
}

void insertNewNode(dataNode** head, int value) {
	dataNode* newNode = createNewNode(value);

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	newNode->next = *head;
	*head = newNode;
}

dataNode* createNewNode(int value) {
	dataNode* newNode = (dataNode*)malloc(sizeof(dataNode));
	if (newNode == NULL) {
		printf("[createNewNode] Cannot allocate the memory for newNode\n");
		return newNode;
	}

	memset(newNode, 0x0, sizeof(dataNode));

	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void viewList(dataNode* head) {
	if (isEmptyList(head)) {
		printf("[viewList] list is empty\n");
		return;
	}

	dataNode* current = head;

	while (current != NULL) {
		printf("Address: %p / value: %4d / next: %p\n", current, current->value, current->next);

		current = current->next;
	}
}

bool isEmptyList(dataNode* head) {
	return head == NULL;
}

bool isListExist(dataNode* linkedlist) {
	return linkedlist != NULL;
}