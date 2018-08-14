#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* root = NULL;

void append(int new_data) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = new_data;
	temp->next = NULL;

	if(root == NULL) {
		root = temp;
	} else {
		struct node* new_temp;
		new_temp = root;
		while(new_temp->next != NULL) {
			new_temp = new_temp->next;
		}
		new_temp->next = temp;
	}
}

void printlist() {
	struct node* temp;
	temp = root;
	while(temp->next != NULL) {
		printf("%d", temp->data);
		temp = temp->next;
		if(temp->next == NULL) {
			printf("%d\n", temp->data);
		}
	}
}

void appendmiddle(int loc, int new_data) {
	struct node* temp, *p;
	p = root;
	int i = 1;
	while(i < loc) {
		p = p->next;
		i++;
	}
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->next = p->next;
	p->next = temp;
}

int length() {
	struct node* temp;
	temp = root;
	int count = 1;
	while(temp->next != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

void delete(int loc) {
	struct node* p,*q;
	int i = 1;
	while(i <  loc-1) {
		p = p->next;
		i++;
	}
	q = p->next;
	p->next = q->next;
	q->next = NULL;
	free(q);
}

void reverse() {
	struct node* p,*q;
	int i = 1;
	int j = length();
	int k,temp;
	p = root;
	q = root;
	while(i < j) {
		k = 1;
		while(k < j) {
			q = q->next;
			k++;
		}
		temp = p->data;
		p->data = q->data;
		q->data = temp;
		i++;
		j--;
		p = p->next;
		q = root;
	}
}

int main() {
	append(10);
	append(20);
	append(30);
	append(40);
	printlist();
	appendmiddle(2,50);
	delete(2);
	printlist();
	reverse();
	printlist();
	return 0;
}