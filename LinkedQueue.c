#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef char element;
typedef struct _QNode {
	element data;
	struct _QNode* link;
}QNode;

typedef struct _LQueue {
	QNode* front;
	QNode* rear;
}LQUEUE;

LQUEUE* createQueue() {
	LQUEUE* lq = (LQUEUE*)malloc(sizeof(LQUEUE));
	lq->front = NULL;
	lq->rear = NULL;
	return lq;
}

int isEmpty(LQUEUE* lq) {
	if (lq->front == NULL) {
		printf("LQ is empty");
		return TRUE;
	}
	return FALSE;
}

void enQueue(LQUEUE* lq, element item) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = item;
	node->link = NULL;

	if (lq->front == NULL) {
		lq->front = node;
		lq->rear = node;
	}
	else {
		lq->rear->link = node;
		lq->rear = node;
	}
	
}

element deQueue(LQUEUE* lq) {
	if (isEmpty(lq)) {
		return 0;
	}

	QNode* old = lq->front;
	element item = old->data;

	lq->front = old->link;
	if (lq->front == NULL) {
		lq->rear = NULL;
	}

	free(old);

	return item;
}

element peek(LQUEUE* lq) {
	if (isEmpty(lq)) {
		return 0;
	}
	return lq->front->data;
}

void printQ(LQUEUE* lq) {
	QNode* tmp = lq->front;

	printf("[");
	while (tmp) {
		printf("%3c", tmp->data);
		tmp = tmp->link;
	}
	printf("  ]");
}

void main(void) {
	QNode* cQ = createQueue();  // 큐 생성
	element data;

	printf("\n **** 연결 큐 연산 ***** \n");

	printf("\n 삽입 A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n 삽입 B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n 삽입 C>>"); enQueue(cQ, 'C'); printQ(cQ);
	data = peek(cQ); printf(" peek item : %c \n", data);

	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터 : %c", data);

	printf("\n 삽입 D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n 삽입 E>>"); enQueue(cQ, 'E'); printQ(cQ);

	free(cQ);
}
