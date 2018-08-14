#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

//struct node* root = NULL;
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int new_data) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->next = NULL;

	if(front == NULL) {
		front = temp;
		rear = temp;
		//root = temp;
	} else {
		rear->next = temp;
		rear = temp;
	}
}

void dequeue() {
	if(front == NULL) {
		printf("Queue is Empty!\n");
	}
	struct node* p;
	p = front;
	front = front->next;
	p->next = NULL;
	free(p);
	//root = front;
}

void printqueue() {
	struct node* p;
	p = front;
	if(front == NULL) {
		printf("Queue is Empty!\n");
	} else { 
		while(p != rear) {
		printf("%d", p->data);
		p = p->next;
		if(p == rear) {
			printf("%d\n", p->data);
			}
		}
	}
}

int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	dequeue();
	printqueue();
	return 0;
}