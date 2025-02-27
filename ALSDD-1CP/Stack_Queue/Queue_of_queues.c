#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Display.h"
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

typedef struct node{
    int x;
   struct node *next;
}list;

typedef struct node2{
    struct node2*next2;
    list*ptr;  
}list2;

typedef struct {
    list *head;
    list *tail;
    int size;
}queue;

typedef struct {
    list2 *head2;
    list2 *tail2;
    int size;
}queue2;

queue* creat_queue();
int size_queue(queue*q);
bool is_empty(queue*q);
int peek(queue*q, bool *status);
void enqueue(queue*q,int value);
void write_queue(queue*q,int size);
int dequeue(queue*q,bool *status );
void destroy(queue*q);
void free_list(list *head);

queue2* creat_queue2();
void write_queue22(queue*q1, int size1, queue*q2, int size2);
int size_queue2(queue2*qu);
bool is_empty2(queue2*qu);
list* peek2(queue2*qu, bool *status);
void enqueue2(queue2*qu);
void write_queue2(queue2*qu);
queue* dequeue2(queue2*qu,bool *status );
void destroy2(queue2*qu);

int main() {
    queue2* qu = creat_queue2();
    char choix;
    int values, maxI, minI;
    bool status;
    Green();

    printf("Intervalle [minI, maxI] des valeurs %c prendre al%catoirement (how many queues)\n", 133, 130);
    printf("---------------------------------------------------------\n");
    printf("Donner la borne inf%crieure : ", 130);
    scanf("%d", &minI);
    printf("Donner la borne sup%crieure : ", 130);
    scanf("%d", &maxI);
    Reset();
    values = minI + rand() % (maxI - minI + 1);
    for (int i = 1; i <= values; i++) {
        Blue();
        enqueue2(qu);
        Reset();
    }
    printf("\n");
    Yellow();
    int size = size_queue2(qu);
    write_queue2(qu);
    Reset();
    Sleep(1);
 /*
    do {
        queue* V = dequeue2(qu, &status);
        int size = size_queue(V);
        if (status) {
            Red();
            write_queue(V, size);
            Reset();
            Green();
            printf("the new queue is : \n");
            size = size_queue2(qu);
            write_queue2(qu);
            Reset();
            Red();
            printf("\n\nIf you want to dequeue another value, enter 'Y' to repeat or any other key to exit: ");
        } else {
            printf("the queue is empty\n");
            break;
        }
        scanf(" %c", &choix);
        while (getchar() != '\n');
        Reset();
    } while (choix == 'Y' || choix == 'y');*/

    destroy2(qu); // Free memory allocated for queue2
    return 0;
}


queue* creat_queue(){
    queue*q =(queue*)malloc(sizeof(queue));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    q->head =NULL;
    q->tail=NULL;
    q->size =0;

    return q;
}
int size_queue(queue*q){

    return q->size;
}
bool is_empty(queue*q){
    return (q->size ==0);
}
int peek(queue*q, bool *status){

    if (is_empty(q)){
        *status = false;
        return -1;
    }
    
    *status =true;
    return q->head->x;
    
}
void enqueue(queue*q,int value){
    list *node =(list*)malloc(sizeof(list));
    node->x = value;
    node->next =NULL;

    if(is_empty(q)){
        q->head =node;
        q->tail =node;
    }
    else{
        q->tail->next =node;
    }
    q->tail =node;
    q->size++;

}

void write_queue(queue*q,int size) {
    if (is_empty(q)) {
        printf("The queue is empty.\n");
    } 
    else if (size == 1){
        printf("         +------------------+------------------+\n");
        printf("         | %-16s | %-16s |\n", "Value", "Address");
        printf("         +------------------+------------------+\n");
        printf(" tail--->| %-16d | %-16p | <--- head \n", q->head->x, q->head);
        printf("         +------------------+------------------+\n");
    }
    else {
       
        printf("+------------------+------------------+\n");
        printf("| %-16s | %-16s |\n", "Value", "Address");
        printf("+------------------+------------------+\n");
        printf("| %-16d | %-16p | <--- head \n", q->head->x, q->head);
        printf("+------------------+------------------+\n");
        list* p = q->head->next;

        while (p != NULL) {
            if(p->next == NULL){
                printf("| %-16d | %-16p | <--- tail\n", p->x, p);
                printf("+------------------+------------------+\n");
            }
            else{
            printf("| %-16d | %-16p |\n", p->x, p);
            printf("+------------------+------------------+\n");
            }
            p = p->next;
        }    
       
    }
}


int dequeue(queue*q,bool *status ){

    if(is_empty(q)){
        *status =false;
        return -1;
    }
    int value =q->head->x;
    *status =true;
    list*p = q->head;
    if(q->size == 1){
        q->head =NULL;
        q->tail =NULL;
    }
    else{
    q->head =q->head->next;
    }
    q->size--;
    free(p);

    return value;
}
void destroy(queue*q){

    list*p = q->head;
    while(p != NULL){
        
        list*u=p;
        p=p->next;
        free(u);
    }
    free(q);
}


queue2* creat_queue2(){
    queue2*qu =(queue2*)malloc(sizeof(queue2));
    if (qu == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    qu->head2 = NULL;
    qu->tail2 = NULL;
    qu->size = 0;
    return qu;
}

bool is_empty2(queue2*qu){
    return qu->size ==0;
}
list* peek2(queue2*qu, bool *status){
    if(is_empty2(qu)){
        *status =false;
        return NULL;
    }
    *status =true;
    return qu->head2->ptr;
}

int size_queue2(queue2*qu){
    return qu->size;
}

void enqueue2(queue2*qu){
    queue*q= creat_queue();
    int Tai,maxI,minI;
    bool status;
    Red();
   
    printf("Intervalle [minI, maxI] des valeurs %c prendre al%catoirement\n",133,130);
    printf("---------------------------------------------------------\n");
    printf("Donner la borne inf%crieure : ",130);
    scanf("%d", &minI);
    printf("Donner la borne sup%crieure : ",130);
    scanf("%d", &maxI);
    Reset();
    Tai = minI + rand() % (maxI - minI + 1);
    for(int i=1;i<=Tai;i++){
        int val=minI + rand() % (maxI - minI + 1);
        Blue ();
        enqueue(q,val);
        Reset();
    }

    list2*node2 =(list2*)malloc(sizeof(list2));
    node2->ptr = q->head;
    node2->next2 = NULL;
    if(is_empty2(qu)){
        qu->head2 = node2;
        qu->tail2 = node2;
    }
    else{
        qu->tail2->next2 =node2;
    }
    qu->tail2 =node2;
    qu->size++;

}

void write_queue23(queue*q1, int size1, queue*q2, int size2) {
    if (is_empty(q1) && is_empty(q2)) {
        printf("The queues are empty.\n");
    } 
    else if (is_empty(q1) && !is_empty(q2)) {
        write_queue(q2,size2);
    }
    else if (!is_empty(q1) && is_empty(q2)) {
        write_queue(q1,size1);
    }
    else if (size1 == 1 && size2 == 1) {
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf("         | %-16s | %-16s |           | %-16s | %-16s |\n", "Value", "Address", "Value", "Address");
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf(" tail--->| %-16d | %-16p | <--- head               tail--->| %-16d | %-16p | <--- head\n", q1->head->x, q1->head, q2->head->x, q2->head);
        printf("         +------------------+------------------+           +------------------+------------------+\n");
    }
    else if (size1 > 1 && size2 == 1) {
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf("         | %-16s | %-16s |           | %-16s | %-16s |\n", "Value", "Address", "Value", "Address");
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf("         | %-16d | %-16p | <--- head               tail--->| %-16d | %-16p | <--- head\n", q1->head->x, q1->head, q2->head->x, q2->head);
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        list* p1 = q1->head->next;
        while (p1 != NULL) {
            if (p1->next == NULL) {
                printf("         | %-16d | %-16p | <--- tail\n", p1->x, p1);
                printf("         +------------------+------------------+\n");
            } else {
                printf("         | %-16d | %-16p |\n", p1->x, p1);
                printf("         +------------------+------------------+\n");
            }
            p1 = p1->next;
        }
    }
    else if (size1 == 1 && size2 > 1) {
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf("         | %-16s | %-16s |           | %-16s | %-16s |\n", "Value", "Address", "Value", "Address");
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf(" tail--->| %-16d | %-16p | <--- head           | %-16d | %-16p | <--- head\n", q1->head->x, q1->head, q2->head->x, q2->head);
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        list* p2 = q2->head->next;
        while (p2 != NULL) {
            if (p2->next == NULL) {
                printf("                                                  tail --->| %-16d | %-16p |\n", p2->x, p2);
                printf("                                                  +------------------+------------------+\n");
            } else {
                printf("                                                           | %-16d | %-16p |\n", p2->x, p2);
                printf("                                                  +------------------+------------------+\n");
            }
            p2 = p2->next;
        }
    }
    /*
    else if (size1 > 1 && size2 > 1) {
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf("         | %-16s | %-16s |           | %-16s | %-16s |\n", "Value", "Address", "Value", "Address");
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf("         | %-16d | %-16p | <--- head | %-16d | %-16p | <--- head\n", q1->head->x, q1->head, q2->head->x, q2->head);
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        list* p1 = q1->head->next;
        list* p2 = q2->head->next;
        while (p1 != NULL || p2 != NULL) {
            if (p1 != NULL) {
                 if (p1->next == NULL) {
                printf("tail --->| %-16d | %-16p |\n", p1->x, p1);
                printf("         +------------------+------------------+");
            } else {
                printf("         | %-16d | %-16p |\n", p1->x, p1);
                printf("         +------------------+------------------+");
                //printf("                                                 ")
            }
                p1 = p1->next;
            }
            if (p2 != NULL) {
                 if (p2->next == NULL) {
                printf("   tail--->| %-16d | %-16p |", p2->x, p2);
                printf("                                                           +------------------+------------------+\n");
            } else {
                printf("           | %-16d | %-16p |", p2->x, p2);
                printf("                                                           +------------------+------------------+\n");
            }
                p2 = p2->next;
            }
            
        }
        printf("\n\n");
    }*/
    else if (size1 > 1 && size2 > 1) {
    printf("         +------------------+------------------+           +------------------+------------------+\n");
    printf("         | %-16s | %-16s |           | %-16s | %-16s |\n", "Value", "Address", "Value", "Address");
    printf("         +------------------+------------------+           +------------------+------------------+\n");
    printf("         | %-16d | %-16p | <--- head           | %-16d | %-16p | <--- head\n", q1->head->x, q1->head, q2->head->x, q2->head);
    printf("         +------------------+------------------+           +------------------+------------------+\n");

    list* p1 = q1->head->next;
    list* p2 = q2->head->next;

    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL) {
            if (p1->next == NULL) {
                printf("         | %-16d | %-16p | <--- tail\n", p1->x, p1);
                printf("         +------------------+------------------+\n");
            } else {
                printf("         | %-16d | %-16p |\n", p1->x, p1);
                printf("         +------------------+------------------+\n");
            }
            p1 = p1->next;
        }

        if (p2 != NULL) {
            if (p2->next == NULL) {
                printf("                                                  tail --->| %-16d | %-16p |\n", p2->x, p2);
                printf("                                                  +------------------+------------------+\n");
            } else {
                printf("                                                           | %-16d | %-16p |\n", p2->x, p2);
                printf("                                                  +------------------+------------------+\n");
            }
            p2 = p2->next;
        }
    }
}

 printf("\n\n");  

}
void write_queue22(queue *q1, int size1, queue *q2, int size2) {
    if (is_empty(q1) && is_empty(q2)) {
        printf("The queues are empty.\n");
    } 
    else {
        printf("         +------------------+------------------+           +------------------+------------------+\n");
        printf("         | %-16s | %-16s |           | %-16s | %-16s |\n", "Value", "Address", "Value", "Address");
        printf("         +------------------+------------------+           +------------------+------------------+\n");

        list *p1 = q1->head;
        list *p2 = q2->head;

        while (p1 != NULL || p2 != NULL) {
            if (p1 != NULL) {
                printf("         | %-16d | %-16p |", p1->x, (void *)p1);
                p1 = p1->next;
            } else {
                printf(" %-47s", ""); // Printing empty space
            }

            if (p2 != NULL) {
                printf("           | %-16d | %-16p |", p2->x, (void *)p2);
                p2 = p2->next;
            }
            else {
                printf(" %-47s", ""); // Printing empty space
            }

            printf("\n");
        }

        printf("         +------------------+------------------+           +------------------+------------------+\n");
    }
}


void write_queue2(queue2* qu) {
    if (is_empty2(qu)) {
        printf("Both queues are empty.\n");
        return;
    }

    list2* current = qu->head2;
    queue* q1 =(queue*)malloc(sizeof(queue));
    queue* q2 =(queue*)malloc(sizeof(queue));
    while (current != NULL) {
        q1->head = current->ptr;
        current = current->next2;

        if (current != NULL) { // If there's another queue, process both
            q2->head = current->ptr;
            write_queue23(q1, q1->size, q2, q2->size);
            current = current->next2; // Move to the next pair of queues
        } else { // Only one queue left, write it using write_queue
            write_queue(q1, q1->size);
        }
    }
}

queue* dequeue2(queue2*qu,bool *status ){
    if(is_empty2(qu)){
        *status =false;
        return NULL;
    }
    queue*p=(queue*)malloc(sizeof(queue));;
    p->head =qu->head2->ptr;
    list2*t = qu->head2;

    *status = true;
    if(qu->size == 1){
        qu->head2 = NULL;
        qu->tail2 = NULL; 
    }
    else{
        qu->head2 = qu->head2->next2;
    }
    qu->size--;
    //free_list(t->ptr);
    free(t);
    return p;

}
void free_list(list *head) {
    list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void destroy2(queue2*qu){
    list2*p = qu->head2;
    while(p != NULL){
        list*u =p->ptr;
        list2*t =p;
        p=p->next2;
        free_list(u);
        free(t);
    }
    
    free(p);
    free(qu);
}




