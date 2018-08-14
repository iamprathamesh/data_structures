/*

NOTE:

	LINKED LIST implemented is APPENDED which has O(n) complexity
	
	use PREPENDED to achieve O(1) complexity or maintain a tail pointer.

*/

#include <stdio.h>
#include <stdlib.h>

int length;

struct node
{
	int data;
	struct node* next;
};

struct node* array[10];

void insertinlist(int index, int new_data) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->next = NULL;

	if(array[index] == NULL) {
		array[index] = temp;
	} else {
		struct node* p;
		p = array[index];
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}


int hash(int key) {
	int index = key % 7;
	return index;
}

void delete(int key) {
	int index = hash(key);
	struct node* p;
	p = array[index];
	while(p->data != key) {
		p = p->next;
	}
	p->data = p->next->data;
	struct node* q;
	q = p->next;
	p->next = q->next;
	q->next = NULL;
	free(q);
}

void insert(int key) {
	int index = hash(key);
	insertinlist(index,key);
}

void printlist(struct node* p) {
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void display() {
	for(int i=0; i<length; i++) {
		printlist(array[i]);
	}
}

int main() {
	length = 10;
	for(int i=0; i<length; i++) {
		array[i] = NULL;
		
	}
	insert(1);
	insert(2);
	insert(7);
	insert(14);
	insert(21);
	insert(49);
	insert(50);
	delete(14);
	display();


	return 0;
}
