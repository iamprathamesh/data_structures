#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* top = NULL;

void push(int new_data) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->next = top;
	top = temp;
}

void printstack() {
	struct node* p;
	p = top;
	if(top == NULL) {
		printf("Stack is Empty!\n");
		return;
	}
	while(p->next != NULL) {
		printf("%d ", p->data);
		p = p->next;
		if(p->next == NULL) {
			printf("%d\n", p->data);
		}
	}
}

void pop() {
	struct node* p;
	p = top;
	if(top == NULL){
		printf("Stack is Empty!");
	} else {
		top = top->next;
		p->next = NULL;
		free(p);
	}
}

int main() {
	push(10);
	push(20);
	push(30);
	push(40);
	pop();
	printstack();
	return 0;
}