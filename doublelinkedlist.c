#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* root = NULL;

void append(int new_data) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->prev = NULL;
	temp->next = NULL;

	if(root == NULL) {
		root = temp;
	} else {
		struct node* p;
		p = root;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
		temp->prev = p;
	}
}

void printlistserially() {
	struct node* temp;
	temp = root;
	while(temp->next != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
		if(temp->next == NULL) {
			printf("%d\n", temp->data);
		}
	}
}

void printlistreverse() {
	struct node* temp;
	temp = root;
	while(temp->next != NULL) {
		temp = temp->next;
	}

	while(temp->prev != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
		if(temp->prev == NULL) {
			printf("%d\n", temp->data);
		}
	}
}

void appendmiddle(int loc, int new_data) {
	struct node* temp, *p, *q;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->prev = NULL;
	temp->next = NULL;
	p = root;

	int i = 1;
	while(i < loc) {
		p = p->next;
		i++;
	}
	q = p->next;
	temp->next = p->next;
	temp->prev = p;
	q->prev = temp;
	p->next = temp;
}

void delete(int loc) {
	struct node* p,*q;
	int i = 1;
	p = root;
	while(i < loc-1) {
		p = p->next;
	}
	q = p->next;
	q->next->prev = p;
	p->next = q->next;
	free(q);
}

int main() {
	append(10);
	append(20);
	append(30);
	append(40);
	printlistserially();
	appendmiddle(2,50);
	printlistserially();
	delete(2);
	printlistserially();
	printlistreverse();
	return 0;
}