#include<stdio.h>
#include <stdlib.h>

struct node {
	struct node* left;
	int data;
	struct node* right;
};

struct node* root = NULL;

void insert(int new_data) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = new_data;
	temp->left = NULL;
	temp->right = NULL;

	if(root == NULL) {
		root = temp;
	} else {
		struct node* p, *current;
		p = current = root;
		while(current) {
			p = current;
			if(current->data < new_data) {
				current = current->right;
			} else if(current->data > new_data) {
				current = current->left;
			}
		}
		if(p->data < new_data) {
			p->right = temp;
		} else if(p->data > new_data) {
			p->left = temp;
		}
	}
}

void delete(int new_data) {
	struct node* p, *current;
	p = current = root;
	while(current->data != new_data) {
		p = current;
		if(current->data < new_data) {
			current = current->right;
		} else if(current->data > new_data) {
			current = current->left;
		}
	}

	if(current->left == NULL && current->right == NULL) {
		if(p->left == current) {
			p->left = NULL;
			free(current);
		} else if(p->right == current) {
			p->right = NULL;
			free(current);
		}
	} else if(current->left == NULL) {
		if(p->left == current) {
			p->left = current->right;
			current->right = NULL;
			free(current);
		} else if(p->right == current) {
			p->right = current->right;
			current->right = NULL;
			free(current);
		}
	} else if(current->right == NULL) {
		if(p->left == current) {
			p->left = current->left;
			current->left = NULL;
			free(current);
		} else if(p->right == current) {
			p->right = current->left;
			current->left = NULL;
			free(current);
		}
	} else {
		if(p->left == current) {
			struct node* r;
			r = current->right;
			p->left = r;
			while(r) {
				p->left = r;
				r = r->left;
			}
			p->left->left = current->left;
			current->left = NULL;
			current->right = NULL;
			free(current);
		} else if(p->right == current) {
			struct node* r;
			r = current->right;
			p->right = r;
			while(r) {
				p->right = r;
				r = r->left;
			}
			p->right->left = current->left;
			current->left = NULL;
			current->right = NULL;
			free(current);
		}
	}
}

int search(int new_data) {
	struct node* p;
	p = root;
	while(p) {
		if(p->data < new_data) {
			p = p->right;
		} else if(p->data > new_data) {
			p = p->left;
		} else if(p->data == new_data) {
			return 1;
		}
	}
	return 0;
}

void inorder(struct node* t) {
	if(t->left) {
		inorder(t->left);
	}
	printf("%d ", t->data);
	if(t->right) {
		inorder(t->right);
	}
}

void preorder(struct node* t) {
	printf("%d ", t->data);
	if(t->left) {
		preorder(t->left);
	}
	if(t->right) {
		preorder(t->right);
	}
}

void postorder(struct node* t) {
	if(t->left) {
		postorder(t->left);
	}
	if(t->right) {
		postorder(t->right);
	}
	printf("%d ", t->data);
}

int main() {
	insert(30);
	insert(20);
	insert(40);
	insert(10);
	insert(25);
	insert(35);
	insert(50);
	insert(23);
	insert(27);
	//printf("%d\n", search(25));
	//delete(25);
	//printf("%d\n", search(25));
	preorder(root);
	return 0;
}