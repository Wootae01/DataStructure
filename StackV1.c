#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
element stack[MAX_SIZE];

int top = -1;

int isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull() {
	if (top == MAX_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(element item) {
	if (isFull()) {
		printf("stack이 꽉 차있습니다.");
		return;
	}
	stack[++top] = item;
}

element pop() {
	if (isEmpty()) {
		printf("stack이 비어있습니다.");
		return;
	}
	return stack[top--];
}

element peak() {
	if (isEmpty()) {
		printf("스택이 비어있습니다.");
		return;
	}
	return stack[top];
}

void printStack() {
	printf("[");
	for (int i = 0; i <= top; i++) {
		printf("%d", stack[i]);
		if (i != top) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(void) {
	element item;

	printStack();
	push(1);
	push(2);
	push(3);
	printStack();
	printStack();

	item = peak(); printStack();

	item = pop(); printStack();
}
