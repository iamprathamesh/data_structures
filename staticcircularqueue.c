#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int cqueue[CAPACITY];
int front = -1;
int rear = -1;

void insert(int new_data) {
	if((front == rear+1) || (rear == CAPACITY-1 && front == 0)) {
		//printf("Circular Queue is full!");
	} else if (front == -1 && rear == -1) {
		front = 0;
		rear = 0;
		cqueue[rear] = new_data;
	} else if(rear == CAPACITY-1) {
		rear = 0;
		cqueue[rear] = new_data;
	} else {
		rear++;
		cqueue[rear] = new_data;
	}
}

void delete() {
	if(front == -1 && rear == -1) {
		//printf("Circular Queue is empty!");	
	} else if(front == rear) {
		front = rear = -1;
	} else if(front == CAPACITY-1) {
		front = 0;
	} else {
		front++;
	}
}

void printcqueue() {
	if((front == rear+1) || (rear == CAPACITY-1 && front == 0)) {
		printf("Circular Queue is full!\n");
	} else if(front == -1 && rear == -1) {
		printf("Circular Queue is empty!\n");
	} else {
		for(int i=front; i<=rear; i++) {
		printf("%d ", cqueue[i]);
		}
	}
}


int main() {
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	//insert(60);
	delete();
	delete();
	delete();
	delete();
	//delete();
	printcqueue();
	//delete();
	//printcqueue();
	return 0;
}