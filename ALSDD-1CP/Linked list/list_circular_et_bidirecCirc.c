#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int x;
    struct Node *next;
} list;

typedef struct Node2 {
    int x;
    struct Node2 *next;
    struct Node2 *prev;
} list2;

list* new_crclr_node(int y) {
    list *head = (list*)malloc(sizeof(list));
    head->x = y;
    head->next = head;
    return head;
}

list2* new_B_crclr_node(int y) {
    list2 *head = (list2*)malloc(sizeof(list2));
    head->x = y;
    head->next = head;
    head->prev = head;
    return head;
}

list* creat_circular_list(int Tai) {
    list *head = NULL;
    list *t = NULL;

    printf("Enter node[1]: ");
    int h;
    scanf("%d", &h);
    head = new_crclr_node(h);
    t = head;
    for (int i = 2; i <= Tai; i++) {
        printf("Enter node[%d]: ", i);
        int y;
        scanf("%d", &y);
        list *tmp = new_crclr_node(y);
        t->next = tmp;
        t = tmp;
    }
    t->next = head;

    return head;
}

list2* creat_B_circular_list(int Tai) {
    list2 *head = NULL;
    list2 *t = NULL;

    printf("Enter node[1]: ");
    int h;
    scanf("%d", &h);
    head = new_B_crclr_node(h);
    t = head;
    for (int i = 2; i <= Tai; i++) {
        printf("Enter node[%d]: ", i);
        int y;
        scanf("%d", &y);
        list2 *tmp = new_B_crclr_node(y);
        t->next = tmp;
        tmp->prev = t;
        t = tmp;
    }
    t->next = head;
    head->prev = t;

    return head;
}

int long_list(list*head){
    list *t = head;
    int i=1;
    while(t->next != head){
       i++;
       t=t->next;
    }
    return i;
}
int long_list2(list2*head){
    list2 *t = head;
    int i=1;
    while(t->next != head){
       i++;
       t=t->next;
    }
    return i;
}

list* list_cir_insert_pos(list *head, int pos, int y) {
    list *t = head; 
    list *u = new_crclr_node(y); 

    if (pos == 1) { 
        if (head == NULL) { 
            u->next = u; 
        } else {
            while (t->next != head) { 
                t = t->next;
            }
            t->next = u; 
            u->next = head; 
        }
        head = u; 
    } else { 
        int l = long_list(head); 
        int cpt = 1;

        while (cpt < pos -1 && t->next != head) { 
            cpt++;
            t = t->next;
        }

        u->next = t->next; 
        t->next = u; 
    }

    return head;
}

list2 *list_B_cir_insert_pos(list2 *head, int pos, int y) {
    list2 *t = head;
    list2 *u = new_B_crclr_node(y);

    if (pos == 1) {
        if (head == NULL) {
            u->next = u;
            u->prev = u;
            head = u;
        } else {
            while (t->next != head) {
                t = t->next;
            }
            t->next = u;
            u->prev = t;
            head->prev = u;
            u->next = head;
            head = u;
        }
    } else {
        int l = long_list2(head);
        int cpt = 1;
        while (cpt < pos - 1 && t->next != head) {
            cpt++;
            t = t->next;
        }
        u->next = t->next;
        t->next->prev = u;
        t->next = u;
        u->prev = t;
    }
    
    return head;
}



void print_list_circular2(list *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    int pos;
    printf("enter the position you want begin to write : ");
    scanf("%d",&pos);
    list *q =head;
    list*t =head;
    
    int cpt =1;
    while(cpt < pos){
        q=t;
        t = t->next ;
        cpt++;
    }
    printf("List elements: ");
    printf("%d -> ",t->x);
    list *p =t;
    t=t->next;
    while (p !=t) {
        printf("%d", t->x);
        t = t->next;
        if (t != p)
            printf(" -> ");
    }

}

void print_B_list_circular2(list2 *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    int pos;
    printf("enter the position you want begin to write : ");
    scanf("%d",&pos);
    list2 *q =head;
    list2*t =head;
    
    int cpt =1;
    while(cpt < pos){
        q=t;
        t = t->next ;
        cpt++;
    }
    printf("List elements: ");
    printf("%d -> ",t->x);
    list2 *p =t;
    t=t->next;
    while (p !=t) {
        printf("%d", t->x);
        t = t->next;
        if (t != p)
            printf(" -> ");
    }

    printf("\n");
    printf("List elements: ");
    printf("%d -> ",p->x);
    t= p->prev;
    
    
    while (t != p) {
        printf("%d", t->x);
        //list2 *q=t;
        t = t->prev;
        if(t != p)
        printf(" -> ");
    }
    printf("\n");

    
}


int main() {
    int Tai, Tai2;
   /** printf("Enter Tai: ");
    scanf("%d", &Tai);

    list *head = creat_circular_list(Tai);
    print_list_circular2(head);
    printf("\nenter the value you wanna insert :");
    int o;
    scanf("%d",&o);
    printf("\nenter the position you wanna insert in :");
    int p;
    scanf("%d",&p);
    head= list_cir_insert_pos(head,p,o);
    print_list_circular2(head);
   */
    printf("\nEnter Tai2: ");
    scanf("%d", &Tai2);

    list2 *head2 = creat_B_circular_list(Tai2);
    print_B_list_circular2(head2);

    printf("\nenter the value you wanna insert :");
    int oo;
    scanf("%d",&oo);
    printf("\nenter the position you wanna insert in :");
    int pp;
    scanf("%d",&pp);
    head2= list_B_cir_insert_pos(head2,pp,oo);
    print_B_list_circular2(head2);

    return 0;
}
