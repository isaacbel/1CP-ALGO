#ifndef Queue_list_H_INCLUDED
#define Queue_list_H_INCLUDED

#include "machine_abstret.h"
#include "machine_abstret.c"

vehicle_list*new_node_vehicle(int y) ;

/*---------------------------------------------------------*/
MotoQ* create_queue_M() ;

vehicle_list* list_insert(vehicle_list *head, int y);
int size_queue_M(MotoQ *q) ;

bool is_empty_M(MotoQ *q) ;

void enqueue_M(MotoQ *q, float capacity, int identifier,int trip,char*work,vehicle_list *ptr) ;

void dequeue_M(MotoQ *q, bool *status, int *ident, float *cap,int* trip,char*work,vehicle_list**head) ;


float peek_M(MotoQ*q, bool *status);
/*--------------------------------------------------------------------------------------*/

VanQ* create_queue_V();

int size_queue_V(VanQ *q) ;
bool is_empty_V(VanQ *q); 

void enqueue_V(VanQ *q, float capacity, int identifier,int tripv,char*work,vehicle_list *ptr) ;

void dequeue_V(VanQ *q, bool *status, int *ident, float *cap, int *tripv, char *work, vehicle_list **head) ;


float peek_V(VanQ*q, bool *status);

void destroy_V(VanQ *q);

ptr new_node(float w, int wi, int ident, char* sta, char* dat) ;


ptrV new_nodeV(int ident, float cpt,char *type) ;


#endif