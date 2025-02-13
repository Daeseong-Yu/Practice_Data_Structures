#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"



int main(void) {
	printf("Hello practice implement Stack\n");
	int retVal = 0;
	Stack* stack = NULL;

	retVal = initializedStack(&stack);

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	push(stack, 6);
	push(stack, 7);
	push(stack, 8);
	push(stack, 9);
	push(stack, 10);
	push(stack, 11);

	printf("Popped Stack: %d\n", pop(stack));
	printf("Peeked Stack: %d\n", peek(stack));
	printf("Popped Stack: %d\n", pop(stack));
	printf("Popped Stack: %d\n", pop(stack));
	printf("Peeked Stack: %d\n", peek(stack));
	printf("Popped Stack: %d\n", pop(stack));
	printf("Popped Stack: %d\n", pop(stack));
	printf("Peeked Stack: %d\n", peek(stack));
	printf("Popped Stack: %d\n", pop(stack));
	
	if (retVal != SUCCEED) {
		return FAILED;
	}

	return SUCCEED;
}

int initializedStack(Stack** stack) {
	(*stack) = (Stack*)malloc(sizeof(Stack));

	if (*stack == NULL) {
		printf("Cannot allocate memory for stack\n");
		return FAILED;
	}

	(*stack)->front = (StackNode*)malloc(sizeof(StackNode));
	(*stack)->topIndex = -1;

	return SUCCEED;
}

int push(Stack* stack, int value) {
	if (isStackFull(stack)) {
		printf("[Push] Stack is Full\n");
		return FAILED;
	}

	StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));

	if (stackNode == NULL) {
		printf("Cannot allocate memory for stackNode\n");
		return FAILED;
	}

	stackNode->value = value;

	// Assigned data to new stackNode
	if (stack->topIndex != -1) {
		stackNode->next = stack->front;
	}
	stack->front = stackNode;
	stack->topIndex++;

	printf("[Push] The Value %d is pushed\n", value);

	return SUCCEED;
}

int pop(Stack* stack) {
	if (isStackEmpty(stack)) {
		printf("[Pop] Stack is empty\n");
		return FAILED;
	}

	int poppedData = stack->front->value;
	stack->topIndex--;

	StackNode* toBeDelete = stack->front;
	stack->front = stack->front->next;
	free(toBeDelete);

	return poppedData;
}

int peek(Stack* stack) {
	if (isStackEmpty(stack)) {
		printf("[Peek] Stack is empty\n");
		return FAILED;
	}

	return stack->front->value;
}

bool isStackEmpty(Stack* stack) {
	return stack->topIndex == -1;
}

bool isStackFull(Stack* stack) {
	return stack->topIndex == MAX_STACK_SIZE - 1;
}