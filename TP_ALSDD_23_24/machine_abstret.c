#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h> 
#include <windows.h> 
#include "machine_abstret.h"




void Allocate(ptr *p) {
    *p = (ItemL*)malloc(sizeof(ItemL)); 
}

void Ass_iden(ptr P, int iden) {
    P->identifier = iden;
}

void Ass_weight(ptr P, float weight) {
    P->weight = weight;
}

void Ass_wilaya(ptr P, int wilaya) {
    P->wilaya = wilaya;
}

void Ass_status(ptr P, char status[]) {
    strcpy(P->status, status); 
}


void Ass_date(ptr P, char date[]) {
    strcpy(P->date, date); 
}

void Ass_adr(ptr P, ptr Q) {
    P->next = Q;
}

ptr Next(ptr P) {
    return P->next;
}

int ident_item(ptr P) {
    return P->identifier;
}

float weight_item(ptr P) {
    return P->weight;
}

int wilaya_item(ptr P) {
    return P->wilaya;
}

char *date_item(ptr P) {
    return P->date;
}

char *status_item(ptr P) {
    return P->status;
}


/*---------------------------------------------------------------------------------------*/
void AllocateV(ptrV *p) {
    *p = malloc(sizeof(VehicleL));
}

void Ass_idenV(ptrV P, int identV) {
    P->identifierV = identV;
}

void Ass_capacityV(ptrV P, float capacityV) {
    P->capacityV = capacityV;
}

void Ass_type(ptrV P,  char *type) {
    strcpy(P->type, type);
    
}

void Ass_adrV(ptrV P, ptrV Q) {
    P->next2 = Q;
}

ptrV NextV(ptrV P) {
    return P->next2;
}

int ident_V(ptrV P) {
    return P->identifierV;
}

float capacity_V(ptrV P) {
    return P->capacityV;
}

char *type(ptrV P) {
    return P->type;
}
/*---------------------------------------------------------*/
void Allocatem(ptrm *p) {
    *p = malloc(sizeof(M));
}

void Ass_idenm(ptrm P, int identV) {
    P->identm= identV;
}

void Ass_capacitym(ptrm P, float capacityV) {
    P->cptm = capacityV;
}

void Ass_trip(ptrm P, int t) {
    P->trip = t;
}

void Ass_work(ptrm P,char *work){
    strcpy(P->work,work);
}

void Ass_adrm(ptrm P, ptrm Q) {
    P->suiv = Q;
}

void Ass_vehm(ptrm P,vehicle_list* Q){
    P->suivant = Q;

}

ptrm Nextm(ptrm P) {
    return P->suiv;
}

int identm(ptrm P) {
    return P->identm;
}

int tripm(ptrm P) {
    return P->trip;
}

char *workm(ptrm P){
    return P->work;
}

float capacitym(ptrm P) {
    return P->cptm;
}

/*---------------------------------------------------------*/

void Allocate_v(ptrv *p) {
    *p = malloc(sizeof(V));
}

void Ass_iden_v(ptrv P, int identV) {
    P->identV= identV;
}

void Ass_trip_v(ptrv P, int t) {
    P->tripV= t;
}

void Ass_capacity_v(ptrv P, float capacityV) {
    P->cptV = capacityV;
}

void Ass_work_v(ptrv P ,char *work){
    strcpy(P->workV,work);
}

void Ass_adrm_v(ptrv P, ptrv Q) {
    P->suiv2 = Q;
}
void Ass_veh_v(ptrv P,vehicle_list* Q){
    P->suivantV = Q;

}

ptrv Next_v(ptrv P) {
    return P->suiv2;
}

int ident_v(ptrv P) {
    return P->identV;
}

int trip_v(ptrv P) {
    return P->tripV;
}
char *workm_v(ptrv P){
    return P->workV;
}

float capacity_v(ptrv P) {
    return P->cptV;
}
