#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 4
#define TRUE 1
#define FALSE 0

typedef char element;

typedef struct _QueueType {
	element queue[QUEUE_SIZE];
	int front;
	int rear;
}QueueType;

QueueType* createQueue() {
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	q->front = -1;
	q->rear = -1;
}

int isEmpty(QueueType* q) {
	if (q->front == q->rear) {
		printf("Queue is empty");
		return TRUE;
	}
	return FALSE;
}

int isFUll(QueueType* q) {
	if (q->rear >= QUEUE_SIZE - 1) {
		printf("Queue is full");
		return TRUE;
	}
	return FALSE;
}

void enQueue(QueueType* q, element item) {
	if (isFUll(q)) {
		return;
	}

	q->queue[++(q->rear)] = item;
}

element deQueue(QueueType* q) {
	if (isEmpty(q)) {
		return;
	}
	
	return q->queue[++(q->front)];
}

element peek(QueueType* q) {
	if (isEmpty(q)) {
		return;
	}

	return q->queue[q->front + 1];
}

void printQ(QueueType* q) {
	printf("Queue [");
	for (int i = q->front + 1; i <= q->rear; i++) {
		printf("%3c", q->queue[i]);
	}
	printf("  ]");
}

int main(void) {
	QueueType* Q1 = createQueue();
	element data;

	printf("\n ***** 순차 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n 삽입 B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n 삽입 C>>"); enQueue(Q1, 'C'); printQ(Q1);
	data = peek(Q1); printf(" peek item : %c \n", data);
	printf("\n 삭제  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제  >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t삭제 데이터 : %c", data);

	printf("\n 삽입 D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n 삽입 E>>"); enQueue(Q1, 'E'); printQ(Q1);
	getchar();

}
