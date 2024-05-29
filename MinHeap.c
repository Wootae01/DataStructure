#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 100

typedef struct _Heap {
	int heap[MAX_HEAP];
	int n;
}Heap;
void createHeap(Heap* heap) {
	heap->n = 0;
}

void insertHeap(Heap* heap, int data) {
	if (heap->n == MAX_HEAP - 1) {
		printf("힙이 가득 차있습니다.\n");
		return;
	}
	int i = ++(heap->n);

	while (i != 1 && heap->heap[i / 2] > data) {
		heap->heap[i] = heap->heap[i / 2];
		i /= 2;
	}
	heap->heap[i] = data;
}

int deleteHeap(Heap* heap) {
	if (heap->n == 0) {
		printf("힙이 비어있습니다.\n");
		exit(1);
	}

	int item = heap->heap[1];
	int tmp = heap->heap[(heap->n)--];

	int parent = 1;
	int child = 2;
	while (child <= heap->n) {
		if (child < heap->n && heap->heap[child] > heap->heap[child + 1]) {
			child = child + 1;
		}

		if (heap->heap[parent] > tmp) 
			break;

		heap->heap[parent] = heap->heap[child];
		parent = child;
		child = child * 2;
	}
	heap->heap[parent] = tmp;

	return item;
}

int main(void) {
	Heap heap;
	createHeap(&heap);
	insertHeap(&heap, 10);
	insertHeap(&heap, 19);
	insertHeap(&heap, 15);
	insertHeap(&heap, 8);
	insertHeap(&heap, 13);
	printf("%d\n", deleteHeap(&heap));
	printf("%d\n", deleteHeap(&heap));
	printf("%d\n", deleteHeap(&heap));
	printf("%d\n", deleteHeap(&heap));
	printf("%d\n", deleteHeap(&heap));
	printf("%d\n", deleteHeap(&heap));
	printf("%d\n", deleteHeap(&heap));
}
