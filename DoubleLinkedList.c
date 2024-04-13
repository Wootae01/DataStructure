#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* pre;
	int data;
	struct Node* next;
}Node;
typedef struct LinkedList {
	Node* head;
	int numOfdata;
}LinkedList;

void initList(LinkedList* pList) {
	pList->head = (Node*)calloc(1, sizeof(Node));
	pList->head->pre = pList->head;
	pList->head->next = NULL;
	pList->numOfdata = 0;
}

void insertFirst(LinkedList* pList, int data) {
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->data = data;

	if (pList->head->next == NULL) {
		pList->head->next = newNode;
		newNode->pre = pList->head;
		return;
	}

	newNode->next = pList->head->next;
	newNode->pre = pList->head;
	pList->head->next->pre = newNode;
	pList->head->next = newNode;
	
	pList->numOfdata += 1;
}

void insertLast(LinkedList* pList, int data) {
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	Node* tmp = pList->head->next;
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = newNode;
	newNode->pre = tmp;
}

Node* searchNode(LinkedList* pList, int data) {
	Node* tmp = pList->head->next;
	while (tmp != NULL) {
		if (tmp->data == data) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return tmp;

}

void deleteNode(LinkedList* pList, Node* target) {
	Node* tmp = pList->head->next;
	while (tmp->next != NULL) {
		if (tmp == target) {
			tmp->pre->next = tmp->next;
			tmp->next->pre = tmp->pre;
			free(target);
			return;
		}
		tmp = tmp->next;
	}
}
void freeNode(LinkedList* pList) {
	Node* tmp = pList->head->next;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		free(tmp->pre);
	}
	free(tmp);
	free(pList->head);
}

void printList(LinkedList* pList) {
	Node* tmp = NULL;
	tmp = pList->head->next;

	printf("(");
	while (tmp != NULL) {
		printf("%d", tmp->data);
		tmp = tmp->next;
		if (tmp != NULL) {
			printf(", ");
		}
	}
	printf(")\n");
}

int main(void) {
	LinkedList list;
	Node* find;
	initList(&list);

	insertFirst(&list, 1);
	insertFirst(&list, 2);
	insertFirst(&list, 3);
	insertFirst(&list, 4);
	printList(&list);

	insertLast(&list, 5);
	insertLast(&list, 6);
	insertLast(&list, 7);
	insertLast(&list, 8);
	printList(&list);

	find = searchNode(&list, 8);
	if (find == NULL) printf("찾는 데이터가 없습니다.\n");
	else printf("%d를 찾았습니다.\n", find->data);

	find = searchNode(&list, 5);
	if (find == NULL) printf("찾는 데이터가 없습니다.\n");
	else printf("%d를 찾았습니다.\n", find->data);

	deleteNode(&list, find);
	printList(&list);

	freeNode(&list);
}


