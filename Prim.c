#define MAX_VERTEX 7
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

typedef struct _GraphNode {
	int vertex;
	int weight;
	struct graphNode* link;

}GraphNode;

typedef struct _Graph {
	GraphNode* adjList[MAX_VERTEX];
}Graph;

void createGraph(Graph* g) {
	for (int i = 0; i < MAX_VERTEX; i++) {
		g->adjList[i] = NULL;
	}
}

//무방향 그래프 삽입
void insertEdge(Graph* g, int v1, int v2, int w) {
	GraphNode* node1 = (GraphNode*)malloc(sizeof(GraphNode));
	node1->vertex = v1;
	node1->weight = w;
	node1->link = g->adjList[v2];
	g->adjList[v2] = node1;

	GraphNode* node2 = (GraphNode*)malloc(sizeof(GraphNode));
	node2->vertex = v2;
	node2->weight = w;

	node2->link = g->adjList[v1];
	g->adjList[v1] = node2;
}

void print_adjList(Graph* g) {
	for (int i = 0; i < MAX_VERTEX; i++) {
		printf("%d의 인접 리스트: ", i);
		GraphNode* tmp = g->adjList[i];
		while (tmp != NULL) {
			printf("%d, ", tmp->vertex);
			tmp = tmp->link;
		}
		printf("\n\n");
	}
}

int prim(Graph* g, int start) {
	int visited[MAX_VERTEX];
	int n = 0;
	int res = 0;

	for (int i = 0; i < MAX_VERTEX; i++) {
		visited[i] = FALSE;
	}
	
	visited[start] = TRUE;
	int v = start;

	while (n < MAX_VERTEX - 1) {
		GraphNode* tmp = g->adjList[v];
		int minVertex = -1;
		int min = 1000;

		while (tmp != NULL) {
			if (min > tmp->weight && !visited[tmp->vertex]) {
				min = tmp->weight;
				minVertex = tmp->vertex;
			}

			tmp = tmp->link;
		}
		printf("간선 %d-%d, 가중치 %d 삽입\n", v, minVertex, min);
		visited[minVertex] = TRUE;
		res += min;
		v = minVertex;
		n++;
	}

	return res;
}

int main(void) {
	Graph g;
	createGraph(&g);
	insertEdge(&g, 0, 1, 29);
	insertEdge(&g, 1, 2, 16);
	insertEdge(&g, 2, 3, 12);
	insertEdge(&g, 3, 4, 22);
	insertEdge(&g, 4, 5, 27);
	insertEdge(&g, 5, 0, 10);
	insertEdge(&g, 6, 1, 15);
	insertEdge(&g, 6, 3, 18);
	insertEdge(&g, 6, 4, 25);
	//print_adjList(&g);
	int res = prim(&g, 0);
	printf("최소 비용 : %d\n", res);

}
