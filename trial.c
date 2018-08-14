#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

void printnodes(struct node* head){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp = head;

  //printf("%d ", temp->data);

  while(temp->next!=NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    if(temp->next == NULL) {
      printf("%d ", temp->data);
    }
  }
}


int main() {
  struct node* head = NULL;
  struct node* first = NULL;
  struct node* second = NULL;
  

  head = (struct node*)malloc(sizeof(struct node));
  first = (struct node*)malloc(sizeof(struct node));
  second = (struct node*)malloc(sizeof(struct node));

  head->data = 10;
  first->data = 20;
  second->data = 30;

  head->next = first;
  first->next = second;
  second->next = NULL;
  
  printnodes(head);
  return 0;
}