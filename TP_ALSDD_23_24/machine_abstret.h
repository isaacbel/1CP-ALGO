#ifndef MACHINE_ABSTRACT_H_INCLUDED
#define MACHINE_ABSTRACT_H_INCLUDED

typedef struct K2{
    int y;
   struct K2 *next4;
}vehicle_list;

typedef struct Node {
    int identifier;
    float weight;
    int wilaya;
    char status[30]; // Specify array size
    struct Node *next;
    char date[20]; // Specify array size
    vehicle_list *item_list;
} ItemL;

typedef struct Node2 {
    int identifierV;
    float capacityV;
    char type[30];
    struct Node2 *next2;
} VehicleL;

typedef VehicleL*ptrV;
typedef ItemL *ptr;


typedef struct N {
    int identm;
    float cptm;
    int trip;
    char work[20];
    vehicle_list*suivant;
    struct N *suiv;
} M;
typedef struct N2 {
    int identV;
    float cptV;
    int tripV;
    char workV[20];
    vehicle_list*suivantV;
    struct N2 *suiv2;
} V;
typedef M*ptrm;
typedef V*ptrv;
typedef struct {
    ptrm head;
    ptrm tail;
    int size;
} MotoQ;

typedef struct {
    ptrv headv;
    ptrv tailv;
    int sizev;
} VanQ;

void Allocate(ptr *p);

void Ass_iden(ptr P, int iden);

void Ass_weight(ptr P, float weight);

void Ass_wilaya(ptr P, int wilaya) ;

void Ass_status(ptr P, char status[]) ;


void Ass_date(ptr P, char date[]);

void Ass_adr(ptr P, ptr Q) ;

ptr Next(ptr P) ;

int ident_item(ptr P) ;

float weight_item(ptr P) ;

int wilaya_item(ptr P);

char *date_item(ptr P) ;

char *status_item(ptr P) ;


/*---------------------------------------------------------------------------------------*/
void AllocateV(ptrV *p) ;

void Ass_idenV(ptrV P, int identV);

void Ass_capacityV(ptrV P, float capacityV) ;

void Ass_type(ptrV P, char *type);

void Ass_adrV(ptrV P, ptrV Q);

ptrV NextV(ptrV P);
int ident_V(ptrV P) ;

float capacity_V(ptrV P);

char *type(ptrV P);
/*---------------------------------------------------------*/
void Allocatem(ptrm *p) ;

void Ass_idenm(ptrm P, int identV) ;
void Ass_capacitym(ptrm P, float capacityV) ;
void Ass_trip(ptrm P, int t) ;

void Ass_work(ptrm P,char *work);

void Ass_adrm(ptrm P, ptrm Q) ;


void Ass_vehm(ptrm P,vehicle_list* Q);

ptrm Nextm(ptrm P);

int identm(ptrm P) ;

int tripm(ptrm P) ;

char *workm(ptrm P);

float capacitym(ptrm P);
/*---------------------------------------------------------*/

void Allocate_v(ptrv *p) ;

void Ass_iden_v(ptrv P, int identV);

void Ass_trip_v(ptrv P, int t) ;

void Ass_capacity_v(ptrv P, float capacityV);

void Ass_work_v(ptrv P ,char *work);
void Ass_adrm_v(ptrv P, ptrv Q) ;
void Ass_veh_v(ptrv P,vehicle_list* Q);
ptrv Next_v(ptrv P) ;

int ident_v(ptrv P) ;

int trip_v(ptrv P) ;
char *workm_v(ptrv P);

float capacity_v(ptrv P) ;

#endif // MACHINE_ABSTRACT_H_INCLUDED