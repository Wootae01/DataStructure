#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _stackNode {
	element data;
	struct _Node* link;
}stackNode;

stackNode* top;

int isEmpty() {
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(element item) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = item;
	newNode->link = top;
	top = newNode;
}

element pop() {
	element item;
	stackNode* tmp = top;
	if (top == NULL) {
		printf("stack이 비어있습니다.\n");
		return 0;
	}
	else {
		item = tmp->data;
		top = tmp->link;
		free(tmp);
		return item;
	}
}

element peak() {
	
	if (top == NULL) {
		printf("stack이 비어있습니다.\n");
		return 0;
	}
	else {
		return top->data;
	}
}

void printStack() {
	stackNode* tmp = top;
	printf("[");
	while (tmp) {
		printf("%d", tmp->data);
		tmp = tmp->link;
		if (tmp != NULL) {
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

	item = peak(); printStack();

	item = pop(); printStack();
	item = pop(); item = pop(); item = pop();
	printStack();
}
