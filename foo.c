#include <stdio.h>
#include <stdlib.h>

struct node {
  int i;
  struct node *next;
};
struct node* head;
void print_list(struct node *);
void print_listh(struct node *, int a);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);


int main(){
  struct node n1;
  struct node * pn1 = &n1;
  struct node n2;
  struct node * pn2 = &n2;
  struct node n3;
  struct node * pn3 = &n3;
  n1.i = 1;
  n1.next = pn2;
  n2.i = 2;
  n2.next = pn3;
  n3.i = 3;
  n3.next = NULL;
  printf("data of n1 = 1, pn1 = &n1\n");
  printf("data of n2 = 2, pn2 = &n2\n");
  printf("data of n3 = 3, pn3 = &n3\n");
  printf("testing: print_list(pn1)\n");
  printf("-----------------\n");
  print_list(pn1);
  printf("-----------------\n");
  struct node * pn4 = insert_front(pn1, 4);
  printf("testing insert_front: adding a node with data value 4 to front, * pn4 = insert_front(pn1, 4)\n");
  printf("further testing: print_list(pn4):\n");
  printf("-----------------\n");
  print_list(pn4);
  free_list(pn4);
  printf("testing free(pn4): can't print_list(pn4) afterwards since pn4 doesn't have allocated memory anymore\n");
  //print_list(pn4);
  return 17;
}

struct node * free_list(struct node * n){
  struct node * next_kill;
  struct node * holder;
  if(n != NULL){
    next_kill = n->next;
    n->next = NULL;
    free_list(next_kill);
  }
  return holder;
}

struct node * insert_front(struct node * list, int a){
  struct node * new = (struct node*)malloc(sizeof(struct node));
  new->i = a;
  new->next = list;
  return new;
}

void print_list(struct node * n){
  print_listh(n, 0);
}

void print_listh(struct node * n, int a){
  printf("node %d: %d\n", a, n->i);
  if(n->next == NULL){
    return;
  }
  print_listh(n->next, a+1);
}
