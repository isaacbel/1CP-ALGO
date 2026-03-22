#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h> 
#include <windows.h> 
#include "machine_abstret.h"
#include "machine_abstret.c"


vehicle_list*new_node_vehicle(int y) {
    vehicle_list *tmp = (vehicle_list *)malloc(sizeof(vehicle_list));  
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tmp->y = y;
    tmp->next4 = NULL;
    return tmp;
}

/*---------------------------------------------------------*/
MotoQ* create_queue_M() {
    MotoQ *q = (MotoQ*)malloc(sizeof(MotoQ));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

vehicle_list* list_insert(vehicle_list *head, int y){
    if (head == NULL){
        head = new_node_vehicle(y);
        return head;
    }
    else{
        vehicle_list*t = head;
        while(t->next4 != NULL){
            t = t->next4;
        }
        t->next4 = new_node_vehicle(y);
        return head;
    }
}

int size_queue_M(MotoQ *q) {
    return q->size;
}

bool is_empty_M(MotoQ *q) {
    return (q->size == 0);
}

void enqueue_M(MotoQ *q, float capacity, int identifier,int trip,char*work,vehicle_list *ptr) {
    ptrm node;
    Allocatem(&node);
    Ass_vehm(node , ptr);
    Ass_idenm(node, identifier);
    Ass_capacitym(node, capacity);
    Ass_work(node,work);
    Ass_adrm(node, NULL);
    Ass_trip(node,trip);
    if (is_empty_M(q)) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->suiv = node;
        q->tail = node;
    }
    q->size++;
}

void dequeue_M(MotoQ *q, bool *status, int *ident, float *cap,int* trip,char*work,vehicle_list**head) {
    if (is_empty_M(q)) {
        *status = false;
        return;
    }
    *ident = q->head->identm;
    *cap = q->head->cptm;
    *status = true;
    *trip = q->head->trip;
    *head = q->head->suivant;
    strcpy(work, q->head->work);
    ptrm p = q->head;
    if (q->size == 1) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->suiv;
    }
    q->size--;
    free(p);
}


float peek_M(MotoQ*q, bool *status){
    if (is_empty_M(q)){
        *status = false;
        return -1;
    }   
    *status =true;
    return q->head->cptm;  
}

void destroy_M(MotoQ *q) {
    ptrm p = q->head;
    while (p != NULL) {
        ptrm u = p;
        p = p->suiv;
        free(u);
    }
    free(q);
}
/*--------------------------------------------------------------------------------------*/

VanQ* create_queue_V() {
    VanQ *q = (VanQ*)malloc(sizeof(VanQ));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    q->headv = NULL;
    q->tailv = NULL;
    q->sizev = 0;

    return q;
}

int size_queue_V(VanQ *q) {
    return q->sizev;
}

bool is_empty_V(VanQ *q) {
    return (q->sizev == 0);
}

void enqueue_V(VanQ *q, float capacity, int identifier,int tripv,char*work,vehicle_list *ptr) {
    ptrv node;
    Allocate_v(&node);
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    Ass_veh_v(node , ptr);
    Ass_capacity_v(node, capacity);
    Ass_iden_v(node, identifier);
    Ass_adrm_v(node, NULL);
    Ass_work_v(node,work);
    Ass_trip_v(node,tripv);
    
    if (is_empty_V(q)) {
        q->headv = node;
        q->tailv = node;
    } else {
        q->tailv->suiv2 = node;
        q->tailv = node;
    }
    q->sizev++;
}

void dequeue_V(VanQ *q, bool *status, int *ident, float *cap, int *tripv, char *work, vehicle_list **head) {
    if (is_empty_V(q)) {
        *status = false;
        return;
    }
    
    *ident = q->headv->identV;
    *cap = q->headv->cptV;
    *status = true;
    *tripv = trip_v(q->headv);
    *head = q->headv->suivantV;
    strcpy(work, q->headv->workV);

    ptrv p = q->headv;
    if (q->sizev == 1) {
        q->headv = NULL;
        q->tailv = NULL;
    } else {
        q->headv = q->headv->suiv2;
    }
    q->sizev--;
    free(p);
}


float peek_V(VanQ*q, bool *status){
    if (is_empty_V(q)){
        *status = false;
        return -1;
    }   
    *status =true;
    return q->headv->cptV;  
}

void destroy_V(VanQ *q) {
    ptrv p = q->headv;
    while (p != NULL) {
        ptrv u = p;
        p = p->suiv2;
        free(u);
    }
    free(q);
}
/*----------------------------------------------------------*/


/*----------------------------------------------------------*/

ptr new_node(float w, int wi, int ident, char* sta, char* dat) {
    ptr tmp;
    Allocate(&tmp);  
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    Ass_iden(tmp, ident);
    Ass_weight(tmp, w);
    Ass_wilaya(tmp, wi);
    Ass_status(tmp, sta);
    Ass_date(tmp, dat);
    Ass_adr(tmp, NULL);
    return tmp;
}


ptrV new_nodeV(int ident, float cpt,char *type) {
    ptrV tmp;
    AllocateV(&tmp);
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    Ass_idenV(tmp, ident);
    Ass_capacityV(tmp, cpt);
    Ass_type(tmp,type);
    Ass_adrV(tmp, NULL);
    return tmp;
}
