#include <stdio.h>
#include <stdlib.h>

int arr[10],length,maxlength;


void maxheapify(int index) {
	int left = 2*index;
	int right = 2*index + 1;
	int largest;

	if(left <= length && arr[left]>arr[index]) {
		largest = left;
	} else {
		largest = index;
	}

	if(right <= length && arr[right]>arr[largest]) {
		largest = right;
	}

	if(largest != index) {
		int temp = 0;
		arr[temp] = arr[largest];
		arr[largest] = arr[index];
		arr[index] = arr[temp];

		maxheapify(largest);
	}
}

void heapify() {
	for(int i=length/2; i>=1; i--) {
		maxheapify(i);
	}
}

void deletemax() {
	int max;
	max = arr[1];
	arr[1] = arr[length];
	length = length - 1;
	maxheapify(1);
}

void increasekey(int index, int key) {
	if(key < arr[index]) {
		printf("value can only be increased!\n");
	} else {
		arr[index] = key;
		while(index > 1 && arr[index] > arr[index/2]) {
			int temp = 0;
			arr[temp] = arr[index/2];
			arr[index/2] = arr[index];
			arr[index] = arr[temp];
			index = index/2;
		}
	}

}

void insert(key) {
	length = length+1;
	int index = length;
	if(length > maxlength) {
		printf("Index out of scope!\n");
		length = length-1;
	} else {
		arr[index] = key;
		while(index > 1 && arr[index] > arr[index/2]) {
			int temp = 0;
			arr[temp] = arr[index/2];
			arr[index/2] = arr[index];
			arr[index] = arr[temp];
			index = index/2;
		}
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
	length = (int)(sizeof(arr)/sizeof(arr[0]));
	length = length-1;
	maxlength = length;
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	heapify();
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	deletemax();
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	increasekey(5,100);
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	increasekey(1,1);
	printf("\n");
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	insert(9);
	printf("\n");
	for(int i=1; i<=length; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}