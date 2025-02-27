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

typedef struct {
    list *top;
    list *tail;
    int size;
}stack;


stack* creat_stack();
int size_queue(stack*q);
bool is_empty(stack*q);
int peek(stack*q, bool *status);
void push(stack*q,int value);
void write_stack(stack*q,int size);
int pop(stack*q,bool *status );
void destroy(stack*q);

int main(){

    stack*q =creat_stack();
    char choix;
    int values,maxI,minI;
    bool status;
    Red();
   // printf("enter the size of the queue :");
    //scanf("%d",&values);
    printf("Intervalle [minI, maxI] des valeurs %c prendre al%catoirement\n",133,130);
    printf("---------------------------------------------------------\n");
    printf("Donner la borne inf%crieure : ",130);
    scanf("%d", &minI);
    printf("Donner la borne sup%crieure : ",130);
    scanf("%d", &maxI);
    Reset();
    values = minI + rand() % (maxI - minI + 1);
    for(int i=1;i<=values;i++){
        int val=minI + rand() % (maxI - minI + 1);;
        Blue ();
       // printf("queue[%d] : ",i);
        //scanf("%d",&val);
        Reset();
        push(q,val);
    }
    printf("\n");
    Yellow();
    int size = q->size;
    write_stack(q,size);
    Reset();
    Sleep(1);

    do{
       int V = pop(q,&status);
       int size = q->size;
       if(status){
       Red();
       printf("the value is %d\n",V);
       Reset();
       Green ();
       printf("the new queue is : \n");
       write_stack(q,size);
       Reset();
       Red();
       printf("\n\nIf u wanna pop another value enter 'Y' to repeat or any other key to exit: ");
       }else{
        printf("the queue is empty\n");
        break;
       }
       
    
        scanf(" %c", &choix); 
        while (getchar() != '\n');
        Reset();
    } while (choix == 'Y' || choix == 'y') ;

    printf("enter a value u wanna push : ");
    int valeur;
    scanf("%d",&valeur);
    push(q,valeur);
    Green ();
    printf("the new queue is : \n");
    write_stack(q,size);
    Reset();
    
    
  return 0;
    
}


stack* creat_stack(){
    stack*q =(stack*)malloc(sizeof(stack));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    q->top = NULL;
    q->tail =NULL;
    q->size =0;

    return q;
}
int size_queue(stack*q){
    return q->size;
}
bool is_empty(stack*q){
    return(q->size == 0);
}
int peek(stack*q, bool *status){

    if (is_empty(q)){
        *status = false;
        return -1;
    }
    
    *status =true;
    return q->top->x;
}


void push(stack*q,int value){

    list *new_node = (list*)malloc(sizeof(list));
    new_node->x = value;
    new_node->next = NULL;
    if(is_empty(q)){
        q->top =new_node;
        q->tail =new_node;
    }
    else{
        new_node->next =q->top;
        
    }
    q->top = new_node;
    q->size++;
}
void write_stack(stack*q,int size){

     if (is_empty(q)) {
        printf("The queue is empty.\n");
    } 
    else if (size == 1){
        printf("         +------------------+------------------+\n");
        printf("         | %-16s | %-16s |\n", "Value", "Address");
        printf("         +------------------+------------------+\n");
        printf(" rear--->| %-16d | %-16p | <--- top \n", q->top->x, q->top);
        printf("         +------------------+------------------+\n");
    }
    else {
       
        printf("+------------------+------------------+\n");
        printf("| %-16s | %-16s |\n", "Value", "Address");
        printf("+------------------+------------------+\n");
        printf("| %-16d | %-16p | <--- top \n", q->top->x, q->top);
        printf("+------------------+------------------+\n");
        list* p = q->top->next;

        while (p != NULL) {
            if(p->next == NULL){
                printf("| %-16d | %-16p | <--- rear\n", p->x, p);
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
int pop(stack*q,bool *status ){

    if(is_empty(q)){
        *status = false;
        return -1;
    }
    int value =q->top->x;
    *status =true;
    list*p = q->top;
     if(q->size == 1){
        q->top =NULL;
        q->tail =NULL;
    }
    else{
    q->top =q->top->next;
    }
    q->size--;
    free(p);

    return value;
}
void destroy(stack*q){
     list*p = q->top;
    while(p != NULL){
        list*u=p;
        p=p->next;
        free(u);
    }
    free(q);
}



