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

//distance 초기화. 
void initDistance() {
	for (int i = 0; i < MAX_VERTEX; i++) {
		distance[i] = INF;
	}
}

int min(int x, int y) {
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
}

int bellmanFord(char c) {
	int start = c - 'A';
	initDistance();
	distance[start] = 0;
	for (int k = 0; k < MAX_VERTEX - 1; k++) {
		for (int i = 0; i < MAX_VERTEX; i++) {
			for (int j = 0; j < MAX_VERTEX; j++) {
				distance[j] = min(distance[j], distance[i] + cost[i][j]);
			}
		}
	}
	//음의 사이클 검출
	for (int i = 0; i < MAX_VERTEX; i++) {
		for (int j = 0; j < MAX_VERTEX; j++) {
			if (distance[j] > distance[i] + cost[i][j]) {
				printf("음의 사이클 검출\n");
				return FALSE;
			}
		}
	}
	return TRUE;
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

	printf("*****벨만-포드 최단 경로 구하기*****\n\n");
	if (bellmanFord('A')) {
		printf("distance = {");
		for (int i = 0; i < MAX_VERTEX; i++) {
			printf("%3d", distance[i]);
		}
		printf("}\n");
	}
}
