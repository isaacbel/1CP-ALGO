#ifndef DOUBLY_LINKED_LIST_OPERATIONS_H
#define DOUBLY_LINKED_LIST_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node {
    int puiss;
    int conf;
    struct Node *next;
} list;

list *new_node(int x,int y);
list* lect_poly(int Tai) ;
void writepoly(list *head);
int calcule(list *head,int x);
void derive( list *head,list **drv);
int long_list(list*head);
list *somme_poly(list *head1, list *head2);
list * Mul_poly(list *head1 ,list *head2);

#endif