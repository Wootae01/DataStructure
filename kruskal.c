#define MAX_VERTEX 10
#include <stdio.h>
#include <stdlib.h>

int parent[MAX_VERTEX]; //각 정점의 부모 노드를 저장

//초기화 함수
void init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
}

//정점의 부모노드를 찾는 함수
int find(int vertex) {
	if (parent[vertex] < 0) {
		return vertex;
	}
	return parent[vertex] = find(parent[vertex]);
}


void set_union(int s1, int s2) {
	int r1 = find(s1);
	int r2 = find(s2);
	parent[r1] = r2;
}

typedef struct _Edge {
	int vertex1;
	int vertex2;
	int weight;
} Edge;

typedef struct _Heap {
	Edge heap[MAX_VERTEX];
	int size;
}Heap;

void initHeap(Heap** h) {
	*h = (Heap*)malloc(sizeof(Heap));
	(*h)->size = 0;
}

int isEmpty(Heap* h) {
	if (h->size == 0) {
		return 1;
	}
	return 0;
}

void insertHeap(Heap* h, Edge item) {
	int i = ++(h->size);
	while (i != 1 && (h->heap[i / 2].weight > item.weight)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

Edge deleteHeap(Heap* h) {
	
	Edge res = h->heap[1];
	Edge item = h->heap[(h->size)--];

	int parent = 1;
	int child = 2;

	while (child <= h->size) {
		if (child < h->size && h->heap[child].weight > h->heap[child + 1].weight) {
			child = child + 1;
		}
		
		if (h->heap[child].weight > item.weight) {
			break;
		}
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = item;
	return res;
}

void insertHeapEdge(Heap* h, int v1, int v2, int weight) {
	Edge edge;
	edge.vertex1 = v1;
	edge.vertex2 = v2;
	edge.weight = weight;
	insertHeap(h, edge);
}

int kruskal(Heap* h, int n) {
	int count = 0;
	int res = 0;
	while (count < n - 1) {
		Edge e = deleteHeap(h);
		int s1 = find(e.vertex1);
		int s2 = find(e.vertex2);
		if (s1 != s2) {
			set_union(e.vertex1, e.vertex2);
			printf("%d %d %d\n", e.vertex1, e.vertex2, e.weight);
			count++;
			res += e.weight;
		}
	}
	return res;
}

int main(void) {
	Heap* h = NULL;
	initHeap(&h);
	insertHeapEdge(h, 0, 1, 29);
	insertHeapEdge(h, 1, 2, 16);
	insertHeapEdge(h, 2, 3, 12);
	insertHeapEdge(h, 3, 4, 22);
	insertHeapEdge(h, 4, 5, 27);
	insertHeapEdge(h, 5, 0, 10);
	insertHeapEdge(h, 6, 1, 15);
	insertHeapEdge(h, 6, 3, 18);
	insertHeapEdge(h, 6, 4, 25);

	init(7);
	int res = kruskal(h, 7);
	printf("%d", res);

	free(h);
}
