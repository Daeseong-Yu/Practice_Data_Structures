#pragma once

#define FAILED	-1
#define SUCCEED	0
#define MAX_STACK_SIZE 10

typedef struct StackNode {
	int value;
	struct StackNode* next;
} StackNode;

typedef struct Stack {
	struct StackNode* front;
	int topIndex;
} Stack;

int initializedStack(Stack** stack);
int push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);

bool isStackEmpty(Stack* stack);
bool isStackFull(Stack* stack);