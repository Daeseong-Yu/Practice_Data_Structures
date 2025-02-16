#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FAILED	-1
#define SUCCEED	0

typedef struct dataNode {
	int value;
	struct dataNode* next;
} dataNode;

void insertNewNode(dataNode** head, int value);
dataNode* createNewNode(int value);
void viewList(dataNode* head);
bool isListExist(dataNode* head);
bool isEmptyList(dataNode* head);


//void freeList(dataNode* linkedlist);