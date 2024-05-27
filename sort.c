#include <stdio.h>
#define MAX_SIZE 8

typedef int element;
int sorted[MAX_SIZE]; //merge sort에서 임의로 저장할 변수

void insertSort(element a[], int n) {
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j;
		for (j = i-1; j >= 0 && tmp < a[j]; j--) {
			a[j + 1] = a[j];
		}
		a[j+1] = tmp;
	}
}
void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void quickSort(element a[], int left, int right) {
	if (left >= right)
		return;

	int pivot = a[left];

	int i = left + 1;
	int j = right;

	while (i <= j) {
		while (i <= right && a[i] <= pivot) {
			i++;
		}
		while (j >= left && a[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(&a[i], &a[j]);
		}
	}

	swap(&a[left], &a[j]);

	quickSort(a, left, j - 1);
	quickSort(a, j + 1, right);
}

void merge(element arr[], int left, int mid, int right) {
	int i = left;
	int j = mid+1;
	int k = left;

	//두 배열 정렬 & 합치기
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		sorted[k++] = arr[i++];
	}
	while (j <= right) {
		sorted[k++] = arr[j++];
	}

	//다시 원래 리스트에 복사
	for (int i = left; i <= right; i++) {
		arr[i] = sorted[i];
	}

}

void mergeSort(element arr[], int left, int right) {
	int mid = (left + right) / 2;

	//divide
	if (left < right) {
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	
}

int main(void) {
	int arr[] = {26, 5, 77, 1, 67, 11, 59, 15};
	mergeSort(arr, 0, MAX_SIZE - 1);
	
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}
}
