#include <stdio.h>
#include <stdlib.h>

struct node{
  int x;
  struct node *next;
  struct node *prev;
}node;

char line[8];

int main(){
  printf(" Enter how many values to input: ");
  int n;
 
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &n);

  struct node * head = malloc(sizeof(node));  //dummy head and tail nodes
  struct node * tail = malloc(sizeof(node));
  head -> next = tail;
  tail -> prev = head;

  int i;
  for (i = 1; i <= n; i++){
    struct node * newNode = malloc(sizeof(node));

    printf("Enter value %d: ", i);
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &newNode -> x);

    struct node * old = tail -> prev;       //'old' node not dynam allocate
    old -> next = newNode;
    tail -> prev = newNode;
    newNode -> prev = old;
    newNode -> next = tail;
  }

  struct node* temp = head -> next;
  while (temp -> next != NULL){  //go thru linked list
    printf("%d\n", temp -> x);  
    temp = temp -> next;
    free(temp -> prev);       //deletes the previous node
  }
  free(head);                //deletes dummy head and tails
  free(tail);
}
