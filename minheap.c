#include <stdio.h>
#include <stdlib.h>

int arr[10],length;

void minheapify(int index) {
	int left = 2*index;
	int right = 2*index + 1;
	int minimum;
	if(left <= length && arr[left] < arr[index]) {
		minimum = left;
	} else {
		minimum = index;
	}

	if(right <= length && arr[right] < arr[minimum]) {
		minimum = right;
	}

	if(minimum != index) {
		int temp = 0;
		arr[temp] = arr[index];
		arr[index] = arr[minimum];
		arr[minimum] = arr[temp];
		minheapify(minimum);
	}
}

void heapify() {
	for(int i=length/2; i>=1; i--) {
		minheapify(i);
	}
}

void deletemin() {
	int min;
	min = arr[1];
	arr[1] = arr[length];
	length = length - 1;
	minheapify(1);
}

void insert(int new_data) {
	length = length + 1;
	int index = length;
	arr[index] = new_data;
	while(index/2 > 1 && arr[index] < arr[index/2]) {
		int temp = 0;
		arr[temp] = arr[index];
		arr[index] = arr[index/2];
		arr[index/2] = arr[temp];
		index = index/2;
	}
}

int main() {
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	arr[5] = 5;
	arr[6] = 6;
	arr[7] = 7;
	arr[8] = 8;
	arr[9] = 9;
	length = (int) (sizeof(arr)/sizeof(arr[0]));
	length = length-1;
	heapify();
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	deletemin();
	insert(5);
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
