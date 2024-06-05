#include <stdio.h>
#include <stdlib.h>
#define MAX 8

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
}

void bubbleSort(int* arr, int size) {
	for (int i = size - 1; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
		}
	}
}

void insertSort(int* arr, int size) {

	for (int i = 1; i < size; i++) {
		int j = i;
		int tmp = arr[i];

		while (j > 0 && arr[j-1] > tmp) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
	}
}

int partition(int* arr, int left, int right) {
	int pivot = left;
	int low = left;
	int high = right;

	do {
		do {
			low++;
		} while (low <= right && arr[low] < arr[pivot]);

		do {
			high--;
		} while (high >= left && arr[high] > arr[pivot]);
		if (low < high) {
			swap(&arr[low], &arr[high]);
		}
	} while (low < high);

	swap(&arr[pivot], &arr[high]);

	return high;
}

void quickSort(int* arr, int left, int right) {
	if (left < right) {
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

int sorted[MAX];
void merge(int* arr, int left, int right, int mid) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if(arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}
	for (i; i <= mid; i++) {
		sorted[k++] = arr[i];
	}
	for (j; j <= right; j++) {
		sorted[k++] = arr[j];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = sorted[i];
	}
}

void mergeSort(int* arr, int left, int right) {

	if (left < right) {	
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, right, mid);
	}
}


int heap[MAX+1];
int heap_size = 0;
void insertHeap(int item) {
	if (heap_size == 0) {
		heap_size++;
		heap[heap_size] = item;
	}
	else {
		int i = ++(heap_size);
		while (item < heap[i / 2]) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
}

int deleteHeap() {
	int item = heap[1];
	int tmp = heap[heap_size--];
	int parent = 1;
	int child = 2;
	while (child < heap_size) {
		if (child + 1 < heap_size && heap[child] > heap[child + 1]) {
			child++;
		}

		if (heap[child] < tmp) {
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		else {
			break;
		}
	}

	heap[parent] = tmp;
	return item;
}

void heapSort(int* arr) {
	for (int i = 0; i < MAX; i++) {
		insertHeap(arr[i]);
	}
	for (int i = 0; i < MAX; i++) {
		arr[i] = deleteHeap();
	}
}

typedef struct _TreeNode {
	struct _TreeNode* left;
	struct _TreeNode* right;
	int data;
}TreeNode;

TreeNode* insertNode(TreeNode* root, int item) {
	
	if (!root) {
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		newNode->data = item;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (item < root->data) {
		root->left = insertNode(root->left, item);
	}
	else if (item > root->data) {
		root->right = insertNode(root->right, item);
	}

	return root;
}

int n = 0;
void inorderSort(TreeNode* root, int* arr) {
	if (root) {
		inorderSort(root->left, arr);
		arr[n++] = root->data;
		inorderSort(root->right, arr);
	}
	return;
}
void treeSort(int* arr) {
	TreeNode* root = NULL;
	root = insertNode(root, arr[0]);
	for (int i = 1; i < MAX; i++) {
		insertNode(root, arr[i]);
	}
	inorderSort(root, arr);
}

int main(void) {
	int arr[8] = {69, 10, 30, 2, 16, 8, 31, 1};
	treeSort(arr);
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
}
