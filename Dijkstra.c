#include <stdio.h>
#define TRUE 1;
#define FALSE 0;
#define INF 10000
#define MAX_VERTEX 5

int cost[MAX_VERTEX][MAX_VERTEX] = {		//간선 비용 저장하는 변수
	{0, 10, 3, INF, INF},
	{INF, 0, 1, 2, INF},
	{INF, 4, 0, 8, 2},
	{INF, INF, INF, 0, 7},
	{INF, INF, INF, 9, 0}
};

int distance[MAX_VERTEX]; //각 정점 까지의 최단 경로 저장하는 변수
int S[MAX_VERTEX]; //최단 경로가 저장된 집합

//distance 초기화. 
void initDistance() {
	for (int i = 0; i < MAX_VERTEX; i++) {
		distance[i] = INF;
	}
}

//S 초기화
void initFind() {
	for (int i = 0; i < MAX_VERTEX; i++) {
		S[i] = FALSE;
	}
}

int nextVertex() {  //최단 경로를 갖는 다음 정점 찾는 함수
	int min = INF + 1;
	int res = -1;
	for (int i = 0; i < MAX_VERTEX; i++) {
		if (!S[i]) {
			if (min > distance[i]) {
				min = distance[i];
				res = i;
			}
		}
	}
	return res;
}

int min(int x, int y) {
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
}

int printStep(int step) {
	printf("%3d단계 : S = {", step);
	for (int i = 0; i < MAX_VERTEX; i++) {
		if (S[i]) {
			printf("%3c", i + 'A');
		}
	}
	printf("  }\n");
	printf("\t\t\t distance = {", step);
	for (int i = 0; i < MAX_VERTEX; i++) {
		if (distance[i] == INF) {
			printf("%3c", '*');
		}
		else {
			printf("%3d", distance[i]);
		}
	}
	printf("  }\n\n");
	return step + 1;
}

void dijkstra(char c) {
	initDistance();
	initFind();

	int start = c - 'A';
	distance[start] = 0;
	
	int u;
	int step = 0;
	for (int i = 0; i < MAX_VERTEX; i++) {
		u = nextVertex();
		S[u] = TRUE;
		step = printStep(step);

		for (int j = 0; j < MAX_VERTEX; j++) {
			if (!S[j]) {
				distance[j] = min(distance[j], distance[u] + cost[u][j]);
			}
		}
		
	}
}

int main(void) {
	printf("*****가중치 인접 행렬*****\n\n");
	for (int i = 0; i < MAX_VERTEX; i++) {
		for (int j = 0; j < MAX_VERTEX; j++) {
			if (cost[i][j] == INF) {
				printf("%4c", '*');
			}
			else {
				printf("%4d", cost[i][j]);
			}
		}
		printf("\n\n");
	}

	printf("*****다익스트라 최단 경로 구하기*****\n\n");
	dijkstra('A');

}
