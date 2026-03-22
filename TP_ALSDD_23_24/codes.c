#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h> 
#include <windows.h> 
#include "Display.h"

#include "queue_list.c"


#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"
#define reset "\e[0m"

#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

int long_list(ptr head){
    ptr t = head;
    int i=0;
    while(t != NULL){
       i++;
       t=t->next;
    }
    return i;
}

int long_list2(ptrV head){
    ptrV t = head;
    int i=0;
    while(t != NULL){
       i++;
       t=t->next2;
    }
    return i;
}


void Simulate_end(ptr head, int *S, int *H) {
    ptr t = head;
    *S=0;
    *H=0;
    // Iterate over the linked list
    while (t != NULL) {
        // Check if the status of the current item is "returned"
        if (strcmp(status_item(t), "returned") == 0) {
            // Increment the count of returned items
            (*S)++;
        }
        // Move to the next node
        t = t->next;
    }

    // Reset the pointer to the head of the linked list
    t = head;

    // Iterate over the linked list again
    while (t != NULL) {
        // Check if the status of the current item is "delivered"
        if (strcmp(status_item(t), "delivered") == 0) {
            // Increment the count of delivered items
            (*H)++;
        }
        // Move to the next node
        t = t->next;
    }
}


void print_list2(vehicle_list*head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    while (head != NULL) {
        printf("%d", head->y);
        head = head->next4;
        if (head != NULL)
            printf(" || ");
    }
    printf("\n");
}

int countLines(const char *filename) {
    FILE *fp;
    char buffer[1024]; // Buffer to store each line
    int line_count = 0;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read each line and count the number of lines
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        line_count++;
    }

    // Close the file
    fclose(fp);

    return line_count;
}

void free_list(ptr head) {
    ptr temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

ptr remplir_ItemL() {
    ptr head = NULL;
    ptr t = NULL;
    FILE *fichier = fopen("items.txt", "r");
    if (fichier == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char chaine[256] = "";
    fgets(chaine, sizeof(chaine), fichier); 

    float w;
    int wi, ident;
    char sta[30], dat[20];
    sscanf(chaine, "%d %s %d %f %s", &ident, dat, &wi, &w, sta);
    head = new_node(w, wi, ident, sta, dat);
    
    t = head;

    while (fgets(chaine, sizeof(chaine), fichier) != NULL) {
        sscanf(chaine, "%d %s %d %f %s", &ident, dat, &wi, &w, sta);
        ptr tmp = new_node(w, wi, ident, sta, dat);
        Ass_adr(t, tmp);
        t = tmp;
    }
    fclose(fichier);
    return head;
}

ptrV remplir_VehicleL() {
    ptrV head = NULL;
    ptrV t = NULL;
    FILE *fichier = fopen("files/vehicles.txt", "r");
    if (fichier == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char chaine[256] = "";
    fgets(chaine, sizeof(chaine), fichier);

    int ident;
    float cpt;
    char type[30] ="";
    sscanf(chaine, "%d %f %s", &ident, &cpt,type);
    head = new_nodeV(ident, cpt,type);

    t = head;

    while (fgets(chaine, sizeof(chaine), fichier) != NULL) {
       char type[30] ="";
        sscanf(chaine, "%d %f %s", &ident, &cpt,type);
        ptrV tmp = new_nodeV(ident, cpt,type);
        Ass_adrV(t, tmp);
        t = tmp;
    }
    fclose(fichier);
    return head;
}


ptr ItemL_insert_pos(ptr head, float w, int wi, int ident, char* sta, char dat[]) {
    ptr t = head; // Initialize t to head to traverse the list
    ptr q = NULL;
    
    // Create a new node
    ptr u = new_node(w, wi, ident, sta, dat);

    Ass_adr(u, head);
    head = u;
    // Return the head of the list
    return head;
}


ptrV VehicleL_insert_pos(ptrV head, int ident, float cpt, char type[],VanQ *qq,MotoQ *pp) {
    ptrV t;
    ptrV q;
    
    t = head;
    ptrV u = new_nodeV(ident, cpt, type);
    
    Ass_adrV(u, t);    
    head = u;   
    int trip =0;
    char work[20]="enable";

    // Enqueue capacity and identifier based on vehicle type
    if (strcmp(strlwr(type), "motorcycle") == 0) {
        enqueue_M(pp, cpt, ident,trip,work,NULL);
    } else if (strcmp(strlwr(type), "van") == 0) {
        enqueue_V(qq, cpt, ident,trip,work,NULL);
    }
    
    return head;
}


void rempli_Queue(MotoQ *q,VanQ *p,ptrV head){
    ptrV tmp = head;
    char ch[30];
    char work[20]="enable";
    while(tmp != NULL){
        strcpy(ch,type(tmp));

        if(strcmp(strlwr(ch), strlwr("motorcycle")) == 0){
            enqueue_M(q,capacity_V(tmp),ident_V(tmp),0,work,NULL);
        }
        else if(strcmp(strlwr(ch), strlwr("van")) == 0) {
            enqueue_V(p,capacity_V(tmp),ident_V(tmp),0,work,NULL);
        }
        tmp = NextV(tmp);
    }

}


void write_queue(VanQ *q, int size) {
    if (is_empty_V(q)) {
        printf("Their are no VANS \n");
    } else if (size == 1) {
        Yellow ();
        printf("\n\n\nVANS\n\n");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        printf("        | %-16s | %-16s |%-8s |%-10s | %-48s\n", "identifier", "maximum capacity", "trip","work", "item indentifier");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        Reset();
        Red();
        printf("head--->| %-16d | %-16f |%-8d |%-10s | ", q->headv->identV, q->headv->cptV, q->headv->tripV,q->headv->workV);
        print_list2(q->headv->suivantV); // Assuming it's print_list2, adjust as necessary
        printf("        +------------------+------------------+----------+------------------------------------------------------+\n");
        Reset();
    } else {
        Yellow();
        printf("\n\n\nVANS\n\n");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        printf("        | %-16s | %-16s |%-8s |%-10s | %-48s\n", "identifier", "maximum capacity", "trip","work" ,"item indentifier");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        Reset();
        Red();
        printf("head--->| %-16d | %-16f |%-8d |%-10s | ", q->headv->identV, q->headv->cptV, q->headv->tripV,q->headv->workV);
        print_list2(q->headv->suivantV);
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        Reset();
        ptrv p = q->headv->suiv2;

        while (p != NULL) {
            vehicle_list *t = p->suivantV;
            printf("        | %-16d | %-16f |%-8d |%-10s |", ident_v(p), capacity_v(p), trip_v(p),workm_v(p));
            if (p->suiv2 == NULL) {
                Red();
                printf("\ntail--->| %-16s | %-16s |%-8s |%-10s | ", "", "", "","");
                print_list2(t);
                printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
                Reset();
            } else {
               // printf("        | %-16s | %-16s |%-8s |%-10s | ", "", "", "","");
                print_list2(t);
                printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
            }
            p = Next_v(p);
        }
    }
}

void write_queuem(MotoQ *q, int size) {
    
    if (is_empty_M(q)) {
        Red();
        printf("\t\t\t\n\nTheir are no MOTOS \n");
        Reset();
    } else if (size == 1) {
        Yellow();
        printf("\n\n\nMOTO\n\n");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        printf("        | %-16s | %-16s |%-8s |%-10s | %-48s\n", "identifier", "maximum capacity", "trip","work", "item indentifier");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        Reset();
        Red();
        printf("head--->| %-16d | %-16f | %-8d | %-10s | ",q->head->identm, q->head->cptm,q->head->trip,q->head->work);
        print_list2(q->head->suivant); // Assuming it's print_list2, adjust as necessary
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        Reset();
    } else {
        Yellow();
        printf("\n\n\nMOTO\n\n");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        printf("        | %-16s | %-16s | %-8s | %-10s | %-48s\n", "identifier", "maximum capacity", "trip","work" ,"item indentifier");
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        Reset();
        Red();
        printf("head--->| %-16d | %-16f | %-8d | %-10s | ",q->head->identm, q->head->cptm,q->head->trip,q->head->work);
        print_list2(q->head->suivant);
        printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
        Reset();
        ptrm p = q->head->suiv;

        while (p != NULL) {
            vehicle_list *t = p->suivant;
            printf("        | %-16d | %-16f | %-8d | %-10s |", identm(p), capacitym(p), tripm(p),workm(p));
            if (p->suiv == NULL) {
                Red();
                printf("\ntail--->| %-16s | %-16s | %-8s | %-10s | ", "", "", "","");
                print_list2(t);
                printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
                Reset();
            } else {
               // printf("        | %-16s | %-16s |%-8s |%-10s | ", "", "", "","");
                print_list2(t);
                printf("        +------------------+------------------+----------+-----------+------------------------------------------------------+\n");
            }
            p = Nextm(p);
        }
    }
}



void print_ItemL(ptr head) {
    ptr current = head;
    Yellow();
    // Print table headers
    printf("|--------------|----------|----------|----------------------|------------|\n");
    printf("| %-12s | %-8s | %-8s | %-20s | %-10s |\n", "Identifier", "Weight", "Wilaya", "Status", "Date");
    printf("|--------------|----------|----------|----------------------|------------|\n");
    Reset();
    // Traverse the linked list
    while (current != NULL) {
        // Print the details of the current node in a formatted table row
        printf("| %-12d | %-8.2f | %-8d | %-20s | %-10s |\n", 
               ident_item(current), weight_item(current), wilaya_item(current),
               status_item(current), date_item(current));

        // Move to the next node
        current = Next(current);
    }
}
void print_Vehicule(ptrV head) {
    ptrV current = head;
     Yellow();
    // Print table headers
    printf("__________________________________________________\n");
    printf("| %-12s | %-8s | %-20s |\n", "Identifier", "Capacity", "Type");
    printf("|______________|__________|______________________|\n");
    Reset();

    // Traverse the linked list
    while (current->next2 != NULL) {
        // Print the details of the current node in a formatted table row
        printf("| %-12d | %-8.2f | %-20s |\n", 
               ident_V(current), capacity_V(current), type(current));

        // Move to the next node
        current = NextV(current);
    }
    printf("|______________|__________|______________________|\n");
}
// Function to link the list of items to the corresponding vehicle node


ptr accesspos(ptr head,int pos){
   ptr t=head;
    int i=1;

    while(t !=NULL){
        if(i == pos){
            return t;
            break;
        }
        t=t->next;
        i++;

    }
    if (t== NULL){
        return NULL;
    }
}

ptrV list_supp_val(ptrV head, int val) {
    ptrV t = head;
    ptrV q = NULL; // Pointer to the previous node

    // Check if the list is empty
    if (t == NULL)
        return NULL;

    // Check if the first node contains the value to be removed
    if (ident_V(t) == val) {
        head = t->next2;
        free(t);
        return head;
    }

    // Traverse the list to find the node with the specified value
    while (t != NULL && ident_V(t) != val) {
        q = t;
        t = NextV(t);
    }

    // If the node with the specified value is found, remove it
    if (t != NULL) {
        q->next2 = NextV(t);
        free(t);
    }

    return head;
}

VanQ* del_van_queue(VanQ *q, int val) {
    ptrv t =q->headv;
    ptrv p = NULL; // Pointer to the previous node

    // Check if the list is empty
    if (t == NULL)
        return NULL;

    // Check if the first node contains the value to be removed
    if (ident_v(t) == val) {
        q->headv = t->suiv2;
        free(t);
        return q;
    }

    // Traverse the list to find the node with the specified value
    while (t != NULL && ident_v(t) != val) {
        p = t;
        t = Next_v(t);
    }

    // If the node with the specified value is found, remove it
    if (t != NULL) {
        p->suiv2 = Next_v(t);
        free(t);
    }

    return q;
}

MotoQ* del_moto_queue(MotoQ *q, int val) {
    ptrm t =q->head;
    ptrm p = NULL; // Pointer to the previous node

    // Check if the list is empty
    if (t == NULL)
        return NULL;

    // Check if the first node contains the value to be removed
    if (identm(t) == val) {
        q->head = t->suiv;
        free(t);
        return q;
    }

    // Traverse the list to find the node with the specified value
    while (t != NULL && identm(t) != val) {
        p = t;
        t = Nextm(t);
    }

    // If the node with the specified value is found, remove it
    if (t != NULL) {
        p->suiv = Nextm(t);
        free(t);
    }

    return q;
}


ptrV find_type(ptrV head, int X) {
    ptrV t = head;
    
    while (t != NULL) {
        if (ident_V(t) == X) {
            return t; // Found the vehicle with the given identifier
        }
        t = t->next2;
    }
    
    return NULL; // Return NULL if the vehicle with the given identifier is not found
}



void writeItemsToFile(ptr head, const char *filename) {
    ptr t = head;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Modified display format
    fprintf(fp, "Identifier| Entry Date | Wilaya | Weight  |  Status\n");
    while (t != NULL) {
        // Modified display format
        fprintf(fp, "%9d | %-10s | %6d | %7.2f | %s\n", ident_item(t), date_item(t), wilaya_item(t), weight_item(t), status_item(t));
        t = Next(t);
    }

    fclose(fp);
    Red();
    printf("\n\nItems have been written to %s successfully.\n", filename);
    Reset();
}


void writeVehicleToFile(ptrV head, const char *filename) {
    ptrV t = head;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Modified display format
    fprintf(fp, "Identifier| cpacity  |  type\n");
    while (t != NULL) {
        // Modified display format
        fprintf(fp, "%9d | %7.2f | %s\n", ident_V(t), capacity_V(t), type(t));
        t = NextV(t);
    }

    fclose(fp);
    Red();
    printf("\n\nVehicles have been written to %s successfully.\n", filename);
    Reset();
}


void swap(ptr *a, ptr *b) {
    // Swap data between two nodes
    int temp_id = ident_item(*a);
    float temp_weight = weight_item(*a);
    int temp_wilaya = wilaya_item(*a);
    char temp_status[30];
    strcpy(temp_status, status_item(*a));
    char temp_date[20];
    strcpy(temp_date, date_item(*a));

    Ass_iden(*a, ident_item(*b));
    Ass_weight(*a, weight_item(*b));
    Ass_wilaya(*a, wilaya_item(*b));
    Ass_status(*a, status_item(*b));
    Ass_date(*a, date_item(*b));

    Ass_iden(*b, temp_id);
    Ass_weight(*b, temp_weight);
    Ass_wilaya(*b, temp_wilaya);
    Ass_status(*b, temp_status);
    Ass_date(*b, temp_date);
}

void sort_by_date(ptr *head) {
    int swapped;
    ptr ptr1;
    ptr lptr = NULL;
  
    /* Checking for empty list */
    if (*head == NULL)
        return;
  
    do {
        swapped = 0;
        ptr1 = *head;
  
        while (ptr1->next != lptr) {
            if (Next(ptr1) != NULL && strcmp(date_item(ptr1), date_item(Next(ptr1))) > 0) {
                ptr v = Next(ptr1);
                swap(&ptr1, &v);
                swapped = 1;
            }
            ptr1 = Next(ptr1);
        }
        lptr = ptr1;
    } while (swapped);
}

void sort_by_wilaya_within_date(ptr *head, ptr lptr) {
    int swapped;
    ptr *ptr1; // Pointer to pointer
  
    if (*head == NULL)
        return;
  
    do {
        swapped = 0;
        ptr1 = head;
  
        while (Next(*ptr1) != lptr) {
            if (strcmp(date_item(*ptr1), date_item(Next(*ptr1))) == 0 && wilaya_item(*ptr1) > wilaya_item(Next(*ptr1))) {
                ptr v = Next(*ptr1);
                swap(ptr1, &v);
                swapped = 1;
            }
            ptr1 = &((*ptr1)->next);
        }
        lptr = *ptr1;
    } while (swapped);
}

void sort_by_weight_within_wilaya_and_date(ptr *head, ptr lptr) {
    int swapped;
    ptr *ptr1; // Pointer to pointer
  
    if (*head == NULL)
        return;
  
    do {
        swapped = 0;
        ptr1 = head;
  
        while (Next(*ptr1) != lptr) {
            if (strcmp(date_item(*ptr1), date_item(Next(*ptr1))) == 0 &&
                wilaya_item(*ptr1) == wilaya_item(Next(*ptr1)) &&
                weight_item(*ptr1) > weight_item(Next(*ptr1))) {
                ptr v = Next(*ptr1);
                swap(ptr1, &v);
                swapped = 1;
            }
            ptr1 = &((*ptr1)->next);
        }
        lptr = *ptr1;
    } while (swapped);
}

void sort_ItemL(ptr *head) {
    // First, sort by date
    sort_by_date(head);
    
    ptr *current = head;
    while (*current != NULL) {
        ptr *start = current;
        // Iterate until the date changes
        while (*current != NULL && strcmp(date_item(*current), date_item(*start)) == 0) {
            current = &((*current)->next);
        }
        // Sort by wilaya within the same date
        sort_by_wilaya_within_date(start, *current);
    }

    // Now, sort by weight within each wilaya and date block
    current = head;
    while (*current != NULL) {
        ptr *start = current;
        // Iterate until the date or wilaya changes
        while (*current != NULL && strcmp(date_item(*current), date_item(*start)) == 0 && wilaya_item(*current) == wilaya_item(*start)) {
            current = &((*current)->next);
        }
        // Sort by weight within the same wilaya and date
        sort_by_weight_within_wilaya_and_date(start, *current);
    }
}



void simulate_delivery(ptr headd, MotoQ *p, VanQ *q, char *date,ptr *stop,ptrv O,ptrm H) {
    ptr t = headd;
    ptr prev = NULL;
    ptrv v = O;
    ptrm m = H;
    int x;
    ptr temp = t; // Temporary pointer to traverse the list without modifying t
    

    // Loop until all items for the given date have been processed  strcmp(status_item(t), "charged") == 0 && 
    while (t != NULL) {
        if (strcmp(date_item(t), date) == 0 &&  v != NULL && t != NULL) {
            bool st;
            temp = t; // Temporary pointer to traverse the list without modifying t
            prev = NULL; // Pointer to track the previous node

            // Check if the item can be delivered by a van
            if (wilaya_item(t) != 16 && capacity_v(v) >= weight_item(t) ) {
                float sum = 0;
                x = wilaya_item(t);
                vehicle_list *L = NULL;

                // Traverse the list to collect items for van delivery
                while (temp != NULL && sum + weight_item(temp) <= capacity_v(v) && strcmp(date_item(temp), date) == 0 && wilaya_item(temp) == x) {
                    if (strcmp(status_item(temp), "charged") == 0 ) {
                        sum += weight_item(temp); // Add weight to total
                        
                        L = list_insert(L, ident_item(temp));
                        prev = temp; // Update prev to track the last processed node
                    }
                    temp = temp->next;
                }
                while (v->suivantV != NULL && Next_v(v) != NULL){
                    v = Next_v(v);
                }
                Ass_veh_v(v, L);
                //v = v->suivantV; // Reset v to the beginning of the van queue
                v= Next_v(v);
                
            }
            // Check if the item can be delivered by a motorcycle
            else if (wilaya_item(t) == 16  && weight_item(t) <= 6 && m != NULL) {
                float sum = 0;
                int cpt = 0;
                vehicle_list *L = NULL;

                // Traverse the list to collect items for motorcycle delivery
                while (temp != NULL && cpt < 2 && sum + weight_item(temp) <= 6 && strcmp(date_item(temp), date) == 0) {
                    if (strcmp(status_item(temp), "charged") == 0 && wilaya_item(temp) == 16) {
                        sum += weight_item(temp); // Add weight to total
                        // Mark item as delivered
                        L = list_insert(L, ident_item(temp));
                        prev = temp; // Update prev to track the last processed node
                        cpt++;
                    }
                    temp = temp->next;
                }
                while (m->suivant != NULL  && Nextm(m) != NULL){
                    m = Nextm(m);
                }
                
                Ass_vehm(m, L);
                //m = m->suivant; // Reset m to the beginning of the motorcycle queue
                m = Nextm(m);
                
               
            } else if (wilaya_item(t) == 16 && weight_item(t) > 6 && capacity_v(v) >= weight_item(t) && v != NULL) {
                float sum = 0;
                int x = wilaya_item(t);
                vehicle_list *L = NULL;

                while (temp != NULL && sum + weight_item(temp) <= capacity_v(v) && strcmp(date_item(temp), date) == 0 && wilaya_item(temp) == x) {
                    if (strcmp(status_item(temp), "charged") == 0 ) {
                        sum += weight_item(temp); // Add weight to total
                         // Mark item as delivered
                        L = list_insert(L, ident_item(temp));
                        prev = temp;
                    }
                    temp = temp->next;
                }
                while (v->suivantV != NULL && Next_v(v) != NULL){
                    v = Next_v(v);
                }
                Ass_veh_v(v, L);
                v = Next_v(v);
            }
        }
        
        if (v->suivantV == NULL || m->suivant == NULL ){
            
            *stop = temp;
            break;
        }
        
        // Move to the next item
        t = t->next;

        // Move back to the last processed item if any delivery was made
        if (prev != NULL) {
            t = prev;
            prev = NULL; // Reset prev for the next iteration
        }
    }
}

ptr delet_delivered_items(ptr head) {
    ptr t = head;
    ptr prev = NULL;
    while (t != NULL) {
        if (strcmp(status_item(t), "delivered") == 0) {
            if (t == head) {
                head = Next(t);
                free(t);
                t = head;
            } else {
                prev->next = Next(t);
                free(t);
                t = prev->next;
            }
        } else {
            prev = t;
            t = Next(t);
        }
    }
    return head;
}
ptr delet_return_items(ptr head) {
    ptr t = head;
    ptr prev = NULL;
    while (t != NULL) {
        if (strcmp(status_item(t), "returned") == 0) {
            if (t == head) {
                head = Next(t);
                free(t);
                t = head;
            } else {
                prev->next = Next(t);
                free(t);
                t = prev->next;
            }
        } else {
            prev = t;
            t = Next(t);
        }
    }
    return head;
}

ptr delet_canceled_items(ptr head) {
    ptr t = head;
    ptr prev = NULL;
    while (t != NULL) {
        if (strcmp(status_item(t), "delivery-canceled") == 0) {
            if (t == head) {
                head = Next(t);
                free(t);
                t = head;
            } else {
                prev->next = Next(t);
                free(t);
                t = prev->next;
            }
        } else {
            prev = t;
            t = Next(t);
        }
    }
    return head;
}

char* random_status() {
    int i = rand() % 4; // Generate a random number between 0 and 3
    if (i < 3) { 
        // "delivered" will be returned for i values 0, 1, and 2
        return "delivered";
    } else { // "returned" will be returned for i value 3
        return "returned";
    }
}


char* random_status2() {
    int i = rand() % 9; // Generate a random number between 0 and 3
    if (i <= 7) { // "delivered" will be returned for i values 0, 1, and 2
        return "charged";
    } else { // "returned" will be returned for i value 3
        Red();
        return "delivery-canceled";
        Reset();
    }
}

ptr modify_status_list(ptr head){
    ptr t = head;
    sort_ItemL(&head);
    char day[20];
    strcpy(day,date_item(head));
    while(t != NULL && strcmp(day,date_item(t))==0){
        Ass_status(t,random_status2());
        t =t->next;
    }
    return head;
}


void recherche_identify_item(int x,ptr head){
    ptr t = head;
    while (t != NULL){
        if (x == ident_item(t) && strcmp(status_item(t),"charged")==0){
            strcpy(t->status, random_status());
            break;
        }
        t=Next(t);
    }

}

void items_status_V(vehicle_list*head,ptr head2){

    vehicle_list *t = head;
    ptr q=head2;
    int x;
    while(t != NULL){
        q=head2;
        x = t->y;
        recherche_identify_item(x,q);
        t = t->next4;
    }

}



void fin_queue(ptrv headv, ptrm head, ptrv *S, ptrm *K) {
    // Traverse the linked list of motorcycles to find the tail
    while (head->suiv != NULL) {
        head = head->suiv;
    }
    // Update pointer K to point to the tail of the motorcycles list
    *K = head;

    // Traverse the linked list of vehicles to find the tail
    while (headv->suiv2 != NULL) {
        headv = headv->suiv2;
    }
    // Update pointer S to point to the tail of the vehicles list
    *S = headv;
}




bool test_work(VanQ *q){
    
    ptrv t = q->headv;
    while(t != NULL){
        if (strcmp(workm_v(t),"next-day") != 0){
            return false;
            break;
        }
        t = Next_v(t);
    }
    return true;
}

void lanch_delivery2(ptr head, MotoQ *p, VanQ *q, VanQ *next_day_q, MotoQ *next_day_p, char *date) {
    ptr Q = head; // Pointer to traverse the queue
    ptrv S; // Pointer to hold the motorcycle being dequeued
    ptrm U; // Pointer to hold the van being dequeued
    vehicle_list* head2; // Head pointer for vehicle list
    int ident, tripv;
    bool status;
    float cap;
    char work[30];
    ptr k; // Temporary pointer for queue traversal
    
    // Loop until the date of the queue matches the given date
    while (Q != NULL && strcmp(date_item(Q), date) == 0) {
        // Simulate delivery for the current queue node
        simulate_delivery(Q, p, q, date, &k, q->headv, p->head);
        
        // Handle motorcycle delivery
        if (Q != NULL && wilaya_item(Q) == 16 && weight_item(Q) <= 6) {
            int c2 = tripm(p->head) + 1;
            Ass_trip(p->head, c2);
            items_status_V(p->head->suivant, head);
            int  size4= size_queue_M(p);
            write_queuem(p, size4);
            if (c2 == 3) {
                Ass_work(p->head, "next-day");
                // Dequeue the motorcycle from the current day's queue
                dequeue_M(p, &status, &ident, &cap, &tripv, work, &head2);
                
                // If the dequeue operation was successful, enqueue the motorcycle into the next day's queue
                if (status) {
                    enqueue_M(next_day_p, cap, ident, tripv, work, NULL);
                }
            } else {
                // Dequeue the motorcycle from the current day's queue
                dequeue_M(p, &status, &ident, &cap, &tripv, work, &head2);
                
                // If the dequeue operation was successful, enqueue the motorcycle back into the current day's queue
                if (status) {
                    enqueue_M(p, cap, ident, tripv, work, NULL);
                }
            }
       } else { // Handle van delivery
            
            // Increment the trip count for the van queue
            int c = trip_v(q->headv) + 1;
            Ass_trip_v(q->headv, c);
            items_status_V(q->headv->suivantV, head);
            int  size5= size_queue_V(q);
              write_queue(q, size5);
            // Check if the trip count exceeds 3
            if (c == 3) {
                Ass_work_v(q->headv, "next-day");
                // Dequeue the van from the current day's queue
                dequeue_V(q, &status, &ident, &cap, &tripv, work, &head2);
                
                // If the dequeue operation was successful, enqueue the van into the next day's queue
                if (status) {
                    enqueue_V(next_day_q, cap, ident, tripv, work, NULL);
                }
            } else {
                // Dequeue the van from the current day's queue
                dequeue_V(q, &status, &ident, &cap, &tripv, work, &head2);
                
                // If the dequeue operation was successful, enqueue the van back into the current day's queue
                if (status) {
                    enqueue_V(q, cap, ident, tripv, work, NULL);
                }
            }
       }
        
        // Move to the next node in the queue
        Q = Q->next;
        
        // If k is not null, update Q to point to k
        if (k != NULL) {
            Q = k;
        }
    }
    
    
    
}

void up_date_queues(MotoQ *p, VanQ *q, VanQ *next_day_q, MotoQ *next_day_p){
    vehicle_list* head2; // Head pointer for vehicle list
    int ident, tripv;
    bool status;
    float cap;
    char work[30];
    
    while(!is_empty_V(next_day_q)){
        dequeue_V(next_day_q,&status, &ident, &cap, &tripv, work, &head2);
        if (status) {
            tripv = 0;
            
            strcpy(work,"enable");
            enqueue_V(q, cap, ident, tripv, work, NULL);
        }
    }

    while(!is_empty_M(next_day_p)){
        dequeue_M(next_day_p,&status, &ident, &cap, &tripv, work, &head2);
        if (status) {
            tripv = 0;
            
            strcpy(work,"enable");
            enqueue_M(p, cap, ident, tripv, work, NULL);
        }
    }
    ptrv t = q->headv;
    while(t != NULL){
        Ass_trip_v(t, 0) ;
        t= Next_v(t);
    }
    ptrm o = p->head;
    while(o != NULL){
        Ass_trip(o, 0) ;
        o= Nextm(o);
    }
}

bool test_ident_exist(ptr head,int X){
    ptr t =head;
    while(t != NULL){
        if (X == ident_item(t)){
            
            return true;
        }
        t = t->next;
    }
    return false;
}
bool test_ident_exist_V(ptrV head,int X){
    ptrV t =head;
    while(t != NULL){
        if (X == ident_V(t)){
            
            return true;
        }
        t = t->next2;
    }
    return false;
}


 char wilayas[][50] = {
        "Adrar", "Chlef", "Laghouat", "Oum El Bouaghi",
        "Batna", "Bejaia", "Biskra", "Bechar",
        "Blida", "Bouira", "Tamanrasset", "Tebessa",
        "Tlemcen", "Tiaret", "Tizi-Ouzou", "Alger",
        "Djelfa", "Jijel", "Setif", "Saida",
        "Skikda", "Sidi-Bel-Abbes", "Annaba", "Guelma",
        "Constantine", "Medea", "Mostaganem", "Msila",
        "Mascara", "Ouargla", "Oran", "El-Bayadh",
        "Illizi", "Bordj-Bou-Arreridj", "Boumerdes", "El-Tarf",
        "Tindouf", "Tissemsilt", "El-Oued", "Khenchela",
        "Souk-Ahras", "Tipaza", "Mila", "Ain-Defla",
        "Naama", "Ain-Temouchent", "Ghardaia", "Relizane",
        "Timimoun", "Bordj Badji Mokhtar", "Ouled Djellal",
        "Beni Abbes", "In Salah", "In Guezzam", "Touggourt",
        "Djanet", "El M'Ghair", "El Meniaa"
    };

typedef struct wil_num{
    int x;
    char wily[50];
}wil_num;

void rempli_wilya_ident(ptr head, char wilayas[][50], wil_num tab[], int *i) {
    printf("\n isaaaaac\n");
    sort_ItemL(&head);
    char day[20];
    *i = 0;
    strcpy(day, date_item(head));
    ptr t = head;
    while (t != NULL && strcmp(day, date_item(t)) == 0) {
        
        int cpt = 1;
        while (t->next != NULL && wilaya_item(t) == wilaya_item(t->next)) {
            
            cpt++;
            t = t->next;
        }
        // Check if t is not NULL before accessing it
        if (t != NULL) {
            int wil = wilaya_item(t);
            tab[*i].x = cpt;
            strcpy(tab[*i].wily, wilayas[wil - 1]);
            t = t->next;
            (*i)++;
        }
    }
    *i = *i - 1;
   
}


void write_wil_num(wil_num tab[],int size){

        Red();
         printf("_______________________________________________\n");
         printf("| %-20s | %-20s |\n", "Wilaya", "number items");
         printf("|______________________|______________________|\n");
         Reset();
        for (int i = 0; i < size; i++) {
           printf("| %-20s | %-20d |\n",tab[i].wily ,tab[i].x);
               

       }
       printf("|______________________|______________________|");
      
}

