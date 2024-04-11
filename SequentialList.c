#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

int List[MAX_TERMS];

void insertList(int index, int value) {
	int tmp = List[index];
	for (int i = index; i < MAX_TERMS - 1; i++) {
		List[i + 1] = List[i];
	}
	List[index] = value;
}
int searchValue(int value) {
	for (int i = 0; i < value; i++) {
		if (List[i] == value) {
			return i;
		}
	}
	return -1;
}
void deleteElement(int value) {
	int index = searchValue(value);
	if (index == -1) {
		return;
	}
	for (int i = index; i < MAX_TERMS - 1; i++) {
		List[i] = List[i + 1];
	}
}
