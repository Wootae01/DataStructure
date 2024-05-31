#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 100

typedef struct _treeNode {
	struct _treeNode* left;
	struct _treeNode* right;
	char data;
}treeNode;

treeNode* insertNode(treeNode* root, char item) {

	treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	node->data = item;
	node->left = NULL;
	node->right = NULL;

	if (root == NULL) {
		return node;
	}
	else if (root->data > item) {
		root->left = insertNode(root->left, item);
	}
	else if(root->data < item){
		root->right = insertNode(root->right, item);
	}
	else {
		printf("이미 같은 키가 있습니다.\n");
	}
	return root;
}
typedef struct _Queue {
	treeNode* queue[MAX_QUEUE];
	int front;
	int rear;
}Queue;

Queue* createQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = 0;
	q->rear = 0;
	return q;
}

int isFull(Queue* q) {
	if ((q->rear + 1) % MAX_QUEUE == q->front) {
		printf("Queue is Full\n");
		return 1;
	}
	return 0;
}

int isEmpty(Queue* q) {
	if (q->rear == q->front) {
		//printf("Queue is empty\n");
		return 1;
	}
	return 0;
}

void enQueue(Queue* q, treeNode* item) {
	if (isFull(q)) {
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE;
	q->queue[q->rear] = item;
}

treeNode* deQueue(Queue* q) {
	if (isEmpty(q)) {
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE;
	return q->queue[q->front];
}

void displayInorder(treeNode* node) {
	if (node) {
		displayInorder(node->left);
		printf("%3c", node->data);
		displayInorder(node->right);
	}
}

void displayLevelorder(treeNode* root) {
	if (!root) {
		return;
	}
	Queue* q = createQueue();

	if (root == NULL) {
		printf("트리가 비어있습니다.\n");
		return;
	}
	
	enQueue(q, root);
	while (isEmpty(&q)) {
		treeNode* current = deQueue(q);
		if (current) {
			printf("%3c", current->data);
			enQueue(q, current->left);
			enQueue(q, current->right);
		}
	}
}

int main() {
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;

	// [그림 7-38]과 같은 초기 이진 탐색 트리를 구성하고 
	// 노드 G를 루트 노드 포인터 root로 지정
	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');

	displayInorder(root);
	printf("\n");

	displayLevelorder(root);
}
