#include <stdio.h>
#include <stdlib.h>

#include "affichage.c"
#include "conio2.h"


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


#define F2 60

int choix_case1 ( void )
{
    char chaine[256] = "";
    int i = 2;
    Clear_Screen();
    printf("\t\t\t\t\t ");
    Cyan();
    printStrAnim(0,"=== MENU ===");
    printf("\n\n\n");
    printf("\t__________________________________________________________________________________________________");
    for ( int i = 1 ; i<=9 ; i++ )
    {
        printf("\n\t|                                                                                                |");
        usleep(30000);
    }
    printf("\n\t|________________________________________________________________________________________________|");usleep(30000);
    printf("\n\t\t\t|                                     |");usleep(30000);
    printf("\n\t\t\t|                                     |");usleep(30000);
    printf("\n\t\t\t|_____________________________________|");usleep(30000);
    Reset();
    Go_up(11);
    printf("\n\t\t ");
    Red();
    printStrAnim(4000,"1 ---> Create Items list (remplir_ItemL) ");
    printf("\n\t\t ");
    printStrAnim(4000,"2 ---> Create Vehicle list (remplir_Vehicle). ");
    printf("\n\t\t ");
    printStrAnim(4000,"3 ---> Create Van Queue (VanQ) and Create Moto Queue (MotoQ). ");
    printf("\n\t\t ");
    printStrAnim( 4000,"4 ---> Display the Item list . ");
    printf("\n\t\t ");
    printStrAnim(4000,"5 ---> Display Vehicle list and  Queues (van queue and moto queue). ");
    printf("\n\t\t ");
    printStrAnim(4000,"6 ---> Summary . ");
    printf("\n\t\t ");
    printStrAnim( 4000,"7 ---> Quit");
    Reset();
    printf("\n\n\n");


    int did = 0;
Here:
     if (did == 0) {
        printf("\r\t\t\t\t ");
        printStrAnim(4000,"Choix : ");
        printf("\r\t\t\t\t\t ");
    } else {
        Go_up(2);
        Cyan();
        printf("\n\t\t\t|                                     |");
        Red();
        printf("\r\t\t\t\t Choix : ");
        Reset();
    }
    char Ans[100];
    char rep;
    fgets(Ans, 100, stdin);
    rep = toupper(Ans[0]);
    Remove_Entree(Ans);
    did = 1;
    if ((strlen(Ans) != 1) || ((rep < '1') || (rep > '7'))) {
        Go_up_Clear_line(1);
        goto Here;
    }


    return atoi(Ans);
}


void menu_case1(ptrV *headV,VanQ **q,MotoQ **p,ptr *head,bool *Q1,bool* Q2,bool* Q3,bool* Q4,bool* Q5) {

    int choice;


    menu:
        system("cls");
        choice = choix_case1();

        do {
            system("color 07");
            if (choice == 0 || choice > 7) {
                printf("Enter your choice between 1 and 7\n");
            }
        } while (choice == 0 || choice > 7);

        system("cls");
        switch (choice) {
     case 1:
        if (!*Q1) {
            system("cls");
            printf(HGRN" 1 ---> Create Items list (remplir_ItemL)\n"reset);
            *head = remplir_ItemL();
            Succes();
            Purple();
            printf("\n\t\t\t________________________________________________");
            printf("\n\t\t\t|                                               |");
            printf("\n\t\t\t|the creation of the item list succed           |");
            printf("\n\t\t\t|_______________________________________________|");

            speak("the creation of the item list succed");
            Reset();
           * Q1 = true;
        } else {
            printf("You have already completed step 1.\n");
        }
        printf(BHYEL"\n\t\t\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto menu;
        break;

    case 2:
        if (*Q1 && !*Q2) {
            system("cls");
            printf(HGRN"2 ---> Create Vehicle list (remplir_Vehicle)\n"reset);
            *headV =remplir_VehicleL();
            Succes();
            Purple ();
            printf("\n\t\t\t___________________________________________________");
            printf("\n\t\t\t|                                                  |");
            printf("\n\t\t\t|the creation of the Vehicle list succed           |");
            printf("\n\t\t\t|__________________________________________________|");

            Reset();
            speak("the creation of the Vehicle list  succed");
            *Q2 = true;
        } else {
            printf("You need to complete step 1 before proceeding to step 2 or Step 2 is already completed.\n");
        }
        printf(BHYEL"\n\t\t\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto menu;
        break;

    case 3:
        if (*Q2 ) {
            system("cls");
            printf(HGRN" 3 ---> Create Van Queue (VanQ) and Create Moto Queue (MotoQ)\n"reset);
            *q = create_queue_V(); // creating a pointer to VanQ
            *p = create_queue_M(); // creating a pointer to MotoQ
            rempli_Queue(*p, *q, *headV);
            Succes();
            Purple ();
            printf("\n\t\t\t__________________________________________________________________");
            printf("\n\t\t\t|                                                                 |");
            printf("\n\t\t\t|the creation of the Van Queue and Moto Queue   succed            |");
            printf("\n\t\t\t|_________________________________________________________________|");
            Reset();
            speak("the creation of the  Van Queue and Moto Queue  succed");
            *Q3 = true;
        } else {
            printf("You need to complete step 2 before proceeding to step 3 or Step 3 is already completed.\n");
        }
        printf(BHYEL"\n\t\t\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto menu;
        break;

    case 4:
        if (*Q1) {
            system("cls");
            printf(HGRN"4 ---> Display the Item list \n"reset);
            int X = long_list(*head);
            afficher_tableau2(*head, X);
            printf("\n");
        } else {
            printf("You need to complete step 1 before displaying the Item list.\n");
        }
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto menu;
        break;

    case 5:
        if (*Q3 && *Q2) {

            system("cls");
            
            printf(HGRN"\t\n\n\n5 ---> Display the Queues (van queue and moto queue)\n\n\n"reset);
            
            Red();
            printf("Vehicle list : \n");
            Reset();
            print_Vehicule(*headV);
            printf("\n");
            int size = size_queue_V(*q);
            int size2 = size_queue_M(*p);
            Red();
            printf("\nVans queue :\n");
            Reset();
            printf("\n");
            write_queue(*q, size);
            Red();
            printf("\nMotos queue :\n");
            Reset();
            write_queuem(*p, size2);
        } else {
            printf("You need to complete step 3 before displaying the Queues.\n");
        }
        printf(BHYEL"\n> Press ENTER to continue ... "reset);

        ViderBuffer();
        goto menu;
        break;
    case 6:
    if (*Q3 && *Q2 && *Q1) {
        system("cls");    
        printf(HGRN"\n\n6 ---> Sammury : \n\n\n"reset);
      int a1,a2,a3,a4,a5;
      a1 = size_queue_M(*p);
      a2 = size_queue_V(*q);
      a3 = long_list(*head);
      a4 = long_list2(*headV);
     Yellow();
     printf("The number of motorcycles is : %d\n\n",a1);
     printf("The number of vans is : %d\n\n",a2);
     printf("The number of items in the list  is : %d\n\n",a3);
     wil_num tab[58];
     int i;
     printf("\n\n==============================================\n\n");
     printf("The items of to day : %s \n",date_item(*head));
     Reset();
     rempli_wilya_ident(*head, wilayas, tab,&i);
     write_wil_num(tab,i);
    }else{
            printf("You need to complete steps 1,2 and 3 before displaying the Queues.\n");
    }

      printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto menu;
      break;    

    case 7:
        
        break;

    default:
        printf("Invalid choice\n");
}



}

int Menu_comeback ( void )
{
    Clear_Screen();
    Cyan();
    printf("\t\t\t\t\t ");
    printStrAnim(0,"=== Simulate the comeback of a vehicle ===");
    printf("\n\n\n");
    printf("\t__________________________________________________________________________________________________");
    printf("\n\t|                                                                                                |");
    printf("\n\t|                                                                                                |");
    printf("\n\t|                                                                                                |");
    printf("\n\t|                                                                                                |");
    printf("\n\t|                                                                                                |");
    printf("\n\t|                                                                                                |");
    printf("\n\t|________________________________________________________________________________________________|");
    printf("\n\t\t\t|                                     |");
    printf("\n\t\t\t|                                     |");
    printf("\n\t\t\t|_____________________________________|");
    Reset();
    Go_up(9);
    printf("\n\t\t ");
    printStrAnim(0,"1 ---> Remove delivered item from the Item list.");
    printf("\n\t\t ");
    printStrAnim(0,"2 ---> Comeback of a vehicle");
    printf("\n\t\t ");
    printStrAnim(0,"3 ---> Quitter");
    printf("\n\n\n\n");
    int did = 0;
Here:
    if ( did == 0 )
    {
        printf("\r\t\t\t\t Choix : ");
        printf("\r\t\t\t\t\t ");
    }
    else
    {
        Go_up(1);
        Cyan();
        printf("\n\t\t\t|                                     |");
        Red();
        printf("\r\t\t\t\t Choix : ");
        Reset();
    }
    char Ans[100];
    char rep;
    fgets(Ans,100,stdin);
    rep = toupper(Ans[0]);
    Remove_Entree(Ans);
    did = 1;
    if ( (strlen(Ans) != 1) || ( ( rep != '1' ) && ( rep != '2' ) && ( rep != '3' ) ))
    {
        Go_up_Clear_line(1);
        goto Here;
    }
    return atoi(Ans);
}


void menu_case6(ptrV *headV,ptr *head,MotoQ **p,VanQ **q,VanQ **next_day_q,MotoQ **next_day_p) {
    bool Q1, Q2, Q3, Q4, Q5;
    Q1 = Q2 = Q3 = Q4 = Q5 = false;
    int choice;
    char choice_char;

        menu6:
        system("cls");
        choice = Menu_comeback();

        do {
            system("color 07");
            if (choice == 0 || choice > 3) {
                printf("Enter your choice between 1 and 3\n");
            }
        } while (choice == 0 || choice > 3);

        system("cls");
        switch (choice) {
            case 1:
        {
            system("cls");
            printf(HGRN"1 ---> Remove delivered item from the Item list\n",reset);
            printf("\n");
            int X= long_list( *head);
            afficher_tableau2(*head,X) ;
            printf("\n");
            *head = delet_delivered_items(*head);
            printf("\n\n");
            print_ItemL(*head);
            printf("\n> Press ENTER to continue ... ");

            ViderBuffer();
            goto menu6;
            break;
        }

        case 2:
        {
            system("cls");
            printf(HGRN"2 ---> Comeback of a vehicle\n",reset);
            int size3 = size_queue_V(*next_day_q );
          if(size3 > 0){
            write_queue(*next_day_q , size3);
          }
            int size = size_queue_V(*q);
            write_queue(*q, size);

            int size5 = size_queue_M(*next_day_p);
            if(size5 >0){
            write_queuem(*next_day_p, size5);
            }
            int  size4= size_queue_M(*p);
            write_queuem(*p, size4);
            print_ItemL(*head);
            printf("\n> Press ENTER to continue ... ");
            ViderBuffer();
            goto menu6;
            break;
        }

        case 3:
        {
            break;

        }

        default:
            break;
     }

}




int Menu_end_of_day ( void )
{
    Clear_Screen();
    Cyan();
    printf("\t\t\t\t\t ");
    printStrAnim(0,"=== Simulate the end of the day  ===");
    printf("\n\n\n");
    printf("\t__________________________________________________________________________________________________");
    for ( int i = 1 ; i<=6 ; i++ )
    {
        printf("\n\t|                                                                                                |");
        usleep(30000);
    }
    printf("\n\t|________________________________________________________________________________________________|");usleep(30000);
    printf("\n\t\t\t|                                     |");usleep(30000);
    printf("\n\t\t\t|                                     |");usleep(30000);
    printf("\n\t\t\t|_____________________________________|");usleep(30000);
    Reset();
    Reset();
    Go_up(10);
    Red();
    printf("\n\t\t ");
    printStrAnim(0,"1 ---> Update item files ");
    printf("\n\t\t ");
    printStrAnim(0,"2 ---> Update vehicles files ");
    printf("\n\t\t ");
    printStrAnim(0,"3 ---> Generate end-of-day reports");
    printf("\n\t\t ");
    printStrAnim(0,"4 ---> update queues for next day ");
    printf("\n\t\t ");
    printStrAnim(0,"5 ---> Quitter");
    printf("\n\n\n ");
    Reset();
    int did = 0;
Here:
    if ( did == 0 )
    {
        printf("\r\t\t\t\t ");
        printStrAnim(4000,"Choix : ");
        printf("\r\t\t\t\t\t ");
    }
    else
    {
        Go_up(1);
        Cyan();
        printf("\n\t\t\t|                                     |");
        Red();
        printf("\r\t\t\t\t Choix : ");
        Reset();
    }
    char Ans[100];
    char rep;
    fgets(Ans,100,stdin);
    rep = toupper(Ans[0]);
    Remove_Entree(Ans);
    did = 1;
    if ( (strlen(Ans) != 1) || ( ( rep != '1' ) && ( rep != '2' ) && ( rep != '3' )&& ( rep != '4' ) && ( rep != '5' )))
    {
        Go_up_Clear_line(1);
        goto Here;
    }
    return atoi(Ans);
}



void choix_end_of_day(ptrV headV,ptr head,MotoQ *p,VanQ *q,int S,int H,int sum_new,int new_V,VanQ *next_day_q,MotoQ *next_day_p) {
    bool Q1, Q2, Q3, Q4, Q5;
    Q1 = Q2 = Q3 = Q4 = Q5 = false;
    int choice;
    char choice_char;

    ISAAC:
        system("cls");
        choice = Menu_end_of_day();

        do {
            system("color 07");
            if (choice == 0 || choice > 6) {
                printf("Enter your choice between 1 and 5\n");
            }
        } while (choice == 0 || choice >6 );

        system("cls");
        switch (choice) {
            case 1:
        {
            system("cls");
            printf(HGRN"1 ---> Update item files\n",reset);
            writeItemsToFile(head, "isaacbe.txt");
            printf("\n> Press ENTER to continue ... ");
            ViderBuffer();
            goto ISAAC;
            break;
        }

        case 2:
        {
            system("cls");
            printf(HGRN"2 ---> Update vehicles files\n",reset);
            writeVehicleToFile(headV, "isaacV.txt");
            printf("\n> Press ENTER to continue ... ");
            ViderBuffer();
            goto ISAAC;
            break;
        }

        case 3:
        {
            system("cls");
            Red();
            printf("3 ---> Generate end-of-day reports\n");
            printf("The number of the items delivred is  :  %d\n",H);
            printf("The number of the items returned is  :  %d\n",S);
            printf("The number of new items is   :  %d\n",sum_new);
            printf("The number of new vehicles is   :  %d\n",new_V);
            Reset();
            Yellow();
            printf("\n> Press ENTER to continue ... ");
            Reset();
            ViderBuffer();
            goto ISAAC;
            break;

        }
         case 4:
        {
          system("cls");
          printf("isaac\n\n");
          up_date_queues(p, q, next_day_q,next_day_p);
          int size = size_queue_V(q);
          write_queue(q, size);
          int size4= size_queue_M(p);
          write_queuem(p, size4);
          printf("\n> Press ENTER to continue ... ");
          ViderBuffer();
          goto ISAAC;
          break;
        }
        case 5:
        {
           printf("\n> Press ENTER to continue ... ");
            ViderBuffer();

        }
        default:
            break;
     }


}


void menu3(ptrV headV,ptr head,VanQ*q,MotoQ *p){
   next :
       printf("");
    VanQ *next_day_q =NULL;
        MotoQ *next_day_p=NULL;
        ptr Q;
        char yes;
        int sum_new =0;
        int new_V=0;
        int dele=0;
    int S,H;
    char choice_char;

    bool W1,W2, W3, W4, W5,W6,W7,W8,W9;
    W1=W2=W3=W4=W5=W6=W7=W8=W9=false;
    int  X;
    int si,si2;
   P:
       printf("");
    int choice;
    menu4(&choice);

    switch (choice)
    {
    case 1:
        system("cls");

        printf("\n\n\t\t\t    Affiche Items list , Vehicle litst,Van queue and Moto queue :  \n\n\n");
        X= long_list( head);
        afficher_tableau2(head,X) ;
        printf("\n");
        print_Vehicule( headV);
        printf("\n");
        si = size_queue_V(q);
        write_queue(q,  si);
        si2 = size_queue_M(p);
        write_queuem(p,  si2) ;
          printf(HGRN"\n\n\t\t Sammury : \n\n\n"reset);
      int a1,a2,a3,a4,a5;
      a1 = size_queue_M(p);
      a2 = size_queue_V(q);
      a3 = long_list(head);
      a4 = long_list2(headV);
     Yellow();
     printf("\t\tThe number of motorcycles is : %d\n\n",a1);
     printf("\t\tThe number of vans is : %d\n\n",a2);
     printf("\t\tThe number of items in the list  is : %d\n\n",a3);
     wil_num tabl[58];
     int i;
     printf("\n====================================================\n");
     printf("\t\tThe items of to day : %s \n",date_item(head));
     Reset();
     printf("\n %d",ident_item(head->next));
     printf("\n %s",date_item(head));
     rempli_wilya_ident(head, wilayas, tabl,&i);
     printf("\n %d",ident_item(head));
     write_wil_num(tabl,i);
        printf(BHYEL"\n\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;
    case 2:
        system("cls");
        sort_ItemL(&head) ;
        printf("\n\n\t\t\t    Add a new item to the ItemL list (new delivery item) :  \n\n\n");
        printf("\n\tthe day is : %s\n",date_item(head));
        printf("\t\Enter how many items you want to add : ");
        int cpt ;
        int ident;
        Date date;
        Red();
        scanf("%d",&cpt);
        Reset();
        while (getchar() != '\n');
        char sta[25]="awaiting-delivery";
        char day[25];
        int w;
        float wei;
        for (int i =0;i<cpt;i++){
            printf("\n\tEnter the date (yyyy-mm-dd): ");
            scanDate(&date);
            dateToString(date, day);
            printf("\tEnter the wilaya of the item: ");
            scanf("%d", &w);
        if (w > 58) {
            printf("\tError: Wilaya must be less than 58. Please enter again.\n");
            i--; // Decrement i to repeat this iteration
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer

        printf("\tEnter the weight of the item: ");
        scanf("%f", &wei);
        if (wei > 100) {
            Red();
            printf("\tError: Weight must be less than 100. Please enter again.\n");
            Reset();
            i--; // Decrement i to repeat this iteration
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer

         do{
            Yellow();
            printf("\tenter the indentifer of the Vehicule :");
            scanf("%d",&ident);
            Reset();
            while (getchar() != '\n');
            if (test_ident_exist(head, ident)) {
                Red();
                printf("\tIdentifier already exists. Please enter another identifier.\n");
                Reset();
            }
         }while( test_ident_exist(head,ident));// Clear input buffer

            head= ItemL_insert_pos(head,  wei,  w,  ident,  sta,  day) ;
        }
        sum_new = sum_new + cpt;
        sort_ItemL(&head) ;
        X= long_list( head);
        afficher_tableau2(head,X) ;
        goto P;
        printf(BHYEL"\n\n\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        break;

    case 3:
        system("cls");
        Red();
        printf("\n\n\t\t\t    Add a new vehicle to the VehicleL list :  \n\n\n");
        printf("\t\t\nEnter how many Vehicules you want to add : ");
        
        scanf("%d",&cpt);
        Reset();
        while (getchar() != '\n');
        char Ty[25];

        for (int i =0;i<cpt;i++){
            printf("\n\t\tentrer the type of the vahicule (motorcycles/vans): ");
            fgets(Ty,25,stdin);
            Ty[strlen(Ty)-1] = '\0';

            
            float wei;
            
            bool re;
    do {
        re = false;
        printf("\t\tEnter the capacity of the item: ");
        scanf("%f", &wei);
        if (strcmp(Ty, "motorcycles") == 0 && wei > 6) {
            printf("\t\tThe capacity of a motorcycle should be equal to or less than 6 kg.\n");
            re = true;
        }
    } while (re);
            
            
            do{
            printf("\t\tenter the indentifer of the Vehicule :");
            scanf("%d",&ident);
            while (getchar() != '\n');
             if (test_ident_exist_V(headV, ident)) {
                printf("\t\tIdentifier already exists. Please enter another identifier.\n");
             }
            }while( test_ident_exist_V(headV,ident));
            headV = VehicleL_insert_pos(headV,ident, wei,Ty,q,p);
        }
        new_V=new_V+cpt;
        print_Vehicule( headV);
        si = size_queue_V(q);
        write_queue(q,  si);
        printf(BHYEL"\n\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 4:
        system("cls");
        Red();
        printf("\n\n\t\t\t    delete a vehicle :  \n\n\n");
        Reset();
        print_Vehicule(headV);
        printf("\n");
        int id;

        do{
            printf("\t\tgive me the identifer of the vehicule : ");

            scanf("%d",&id);
            if (!test_ident_exist_V(headV, id)) {
                printf("\t\tIdentifier donesn't  exists. Please enter an identifier exist .\n");
            }
        }while(! test_ident_exist_V(headV,ident));
        char T[20];
        ptrV L = find_type(headV, id);
        strcpy(T, type(L));
        headV = list_supp_val(headV, id);

        
        if (strcmp(T, "vans") == 0) {
          q = del_van_queue(q, id);
        } else {
          p = del_moto_queue(p, id);
        }

        headV =list_supp_val(headV,id);
        int k3 = size_queue_M(p);
        int k2 = size_queue_V(q);
        printf("\n");
        write_queue(q,k2);
        printf("\n");
        write_queuem(p,k3);
        ViderBuffer();
        print_Vehicule(headV);
        printf("\n");
        headV=list_supp_val(headV,id);
        print_Vehicule( headV);
        dele++;
        printf(BHYEL"\n\n\t\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 5:
        if(!W1 && !W2 && !W3 && !W4){
        system("cls");
        sort_ItemL(&head) ;
        W5 = true;
        W1 = W2=W3=W4 = true;
        ptr Y = head;
        Red();
        printf("\n\n\t\t\t     Simulate the delivery operation   :  \n\n\n");
        Reset();
        sort_ItemL(&head) ;
        
        X= long_list(head);
        afficher_tableau2(head,X);
        printf("\n\n\n");

        next_day_q = create_queue_V();
        next_day_p = create_queue_M();
        sort_ItemL(&head) ;
        head = modify_status_list( head);
        X= long_list(head);
        afficher_tableau2(head,X);
        W5 = true;

        lanch_delivery2(head,p,q,next_day_q ,next_day_p,date_item(Y) );
        printf("\n");
        Succes();
        printf(BHYEL"\n\t\tThe delivry is done\n"reset);
        printf(BHYEL"\n\t\t> Press ENTER to see the result  ... \n"reset);
        ViderBuffer();
        system("cls");
        printf("\n");
        X= long_list( head);
        afficher_tableau2(head,X);
        printf("\n");

        Simulate_end( head,&S,&H);
        }
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 6:
     if (W5){
        W6=true;
        system("cls");
        printf("\n\n\t\t\t    Simulate the comeback of a vehicle :  \n\n\n");
        menu_case6(&headV, &head,&p,&q,&next_day_q,&next_day_p);
     }else{
        Red();
        printf("\t\t\nplease do step 5 before");
        Reset();
     }
        printf(BHYEL"\n\t\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;
    case 7:
      if(W6){
        system("cls");
        W7 = true;
        Red();
        printf("\n\n\t\t\t    Remove returned  and canceled items from the Item list:  \n\n\n");
        Reset();
        Yellow();
        printf("\n\tRemove cancled items first : \n");
        Reset();
        head =  delet_canceled_items( head);
        print_ItemL(head); 
        Yellow();
        printf("\n\tRemove returned  items  : \n");
        Reset();
        head = delet_return_items( head);
        print_ItemL(head);  
      }else{
        Red();
        printf("\n\tplease do step 6 before ");
        Reset();
      }
        printf(BHYEL"\n\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 8:
      if(W7){
        system("cls");
        printf("\n\n\t\t\t    Simulate the end of the day :  \n\n\n");
        W8=true;
        choix_end_of_day( headV, head,p,q,S, H, sum_new, new_V,next_day_q,next_day_p);

      }else{
        Red();
        printf("\n\tplease do step 7 before ");
        Reset();
      }
        printf(BHYEL"\n\n\t> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;
    case 9:
        system("cls");
        if(W8){
        printf("\n\n\t\t\t   Move for the next day  :  \n\n\n");
        char OUI;
         if (head == NULL){
                Red();
                printf("\nthere are no items in the list \n");
                Reset();
                goto ST;
            }

        printf("\t Do you want to move to the next day (Y/N) ? \n\n");
        scanf("%c",&OUI);
        if (OUI =='Y'|| OUI =='y'){

            goto next;
        }
        }else{
        Red();
        printf("\n\tplease do step 8 before ");
        Reset();
        }
        goto P;
        break;

     case 10 :
      ST:
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        break;


    default:
        break;
    }


}


void menu2(){
    ptrV headV=NULL;
    VanQ *q = NULL ;
    MotoQ *p =NULL;
    ptr head=NULL ;
    VanQ *next_day_q =NULL;
        MotoQ *next_day_p=NULL;
        ptr Q;
        char yes;
        int sum_new =0;
        int new_V=0;
        int dele=0;
    int S,H;
    char choice_char;
    bool Q1, Q2, Q3, Q4, Q5;
    bool W1,W2, W3, W4, W5,W6,W7,W8,W9;
    W1=W2=W3=W4=W5=W6=W7=W8=W9=false;
    int  X;
    Date date;
   P:
       printf("");
    int choice;
    menu(&choice);

    switch (choice)
    {
    case 1:

        system("cls");
        W1 = true;
        printf("\n\n\t\t\t    Create the different lists and queues models and get information loaded into lists and queues       :  \n\n\n");
        menu_case1( &headV,&q,&p,&head,&Q1, &Q2, &Q3,&Q4,&Q5) ;
        goto P;
        break;
    case 2:
       if( W1 &&!W2 ){
        system("cls");

        sort_ItemL(&head) ;
        Red ();
        printf("\n\n\t\t\t    Add a new item to the ItemL list (new delivery item) :  \n\n\n");
        Reset();
        printf("\nthe day is : %s\n",date_item(head));
        printf("Enter how many items you want to add : ");
        int cpt;
        Red();
        scanf("%d",&cpt);
        Reset();
        while (getchar() != '\n');
        char sta[25]="awaiting-delivery";

        char day[25];
        int w;
            int ident;
            float wei;
        for (int i =0;i<cpt;i++){
            scanDate(&date);
            dateToString(date, day);
            printf("Enter the wilaya of the item: ");
            scanf("%d", &w);
        if (w > 58) {
            printf("Error: Wilaya must be less than 58. Please enter again.\n");
            i--; // Decrement i to repeat this iteration
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer

        printf("Enter the weight of the item: ");
        scanf("%f", &wei);
        if (wei > 100) {
            printf("Error: Weight must be less than 100. Please enter again.\n");
            i--; // Decrement i to repeat this iteration
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer

         do{
            printf("enter the indentifer of the Vehicule :");
            scanf("%d",&ident);
            while (getchar() != '\n');
            if (test_ident_exist(head, ident)) {
                printf("Identifier already exists. Please enter another identifier.\n");
            }
         }while( test_ident_exist(head,ident));// Clear input buffer

            head= ItemL_insert_pos(head,  wei,  w,  ident,  sta,  day) ;
        }
        sum_new = sum_new + cpt;
        sort_ItemL(&head) ;
        X= long_list( head);
        afficher_tableau2(head,X) ;
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
       }else{
           Red();
           printf("You need to complete step 1 before proceeding to step 2 or step two done .\n");
           Reset();
       }
       printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 3:
      if(W1&&!W3){
        system("cls");
        Red();
        printf("\n\n\t\t\t    Add a new vehicle to the VehicleL list :  \n\n\n");
        Reset();
        
        printf("Enter how many Vehicules you want to add : ");
        int cpt;
        Red();
        scanf("%d",&cpt);
        Reset();
        while (getchar() != '\n');
        char Ty[25];
        float wei;

        for (int i =0;i<cpt;i++){
            printf("\nentrer the type of the vahicule (motorcycles/vans): ");
            fgets(Ty,25,stdin);
            Ty[strlen(Ty)-1] = '\0';

            int ident;
            bool re ;
            do {
                re = false;
                printf("Enter the capacity of the item: ");
                scanf("%f", &wei);
                if (strcmp(Ty, "motorcycles") == 0 && wei > 6) {
                printf("The capacity of a motorcycle should be equal to or less than 6 kg.\n");
                re = true;
               }
            } while(re);
            do{
            printf("enter the indentifer of the Vehicule :");
            scanf("%d",&ident);
            while (getchar() != '\n');
             if (test_ident_exist_V(headV, ident)) {
                printf("Identifier already exists. Please enter another identifier.\n");
            }
            }while( test_ident_exist_V(headV,ident));
            headV = VehicleL_insert_pos(headV,ident, wei,Ty,q,p);
        }
        new_V=new_V+cpt;
        print_Vehicule( headV);
        int si = size_queue_V(q);
        write_queue(q,  si);
      }else{
        printf("You need to complete step 1 before proceeding to step 3 or step tree done  .\n");
      }
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 4:
      if(W1 && !W4){
        system("cls");
        printf("\n\n\t\t\t    delete a vehicle :  \n\n\n");
        print_Vehicule(headV);
        printf("\n");
        int id;

        do{
            printf("give me the identifer of the vehicule : ");

            scanf("%d",&id);
            printf("\n");
            if (!test_ident_exist_V(headV, id)) {
                printf("Identifier donesn't  exists. Please enter an identifier exist .\n");
            }
        }while(! test_ident_exist_V(headV,id));

       char T[20];
        ptrV L = find_type(headV, id);
        strcpy(T, type(L));
        headV = list_supp_val(headV, id);

        
        if (strcmp(T, "van") == 0) {
          q = del_van_queue(q, id);
        } else {
          p = del_moto_queue(p, id);
        }

        headV =list_supp_val(headV,id);
        int k3 = size_queue_M(p);
        int k2 = size_queue_V(q);
        printf("\n");
        write_queue(q,k2);
        printf("\n");
        write_queuem(p,k3);
        ViderBuffer();
        print_Vehicule(headV);
        printf("\n");
        dele++;

      }else{
        printf("You need to complete step 1 before proceeding to step 4 or step 4 done.\n");
      }
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 5:
       if(W1){
        if(W5){
            printf("\n\n\n\t\tYou have already do Simulate the delivery operation\n\n");
            printf(BHYEL"\n\n> Press ENTER to continue ... "reset);
            ViderBuffer();
            goto P;
        }
        Clear_Screen();
        sort_ItemL(&head) ;
        ptr Y = head;
        Red();
        printf("\n\n\t\t\t     Simulate the delivery operation   :  \n\n\n");
        Reset();
        sort_ItemL(&head) ;
        X= long_list(head);
        afficher_tableau2(head,X);

        printf("\n\n\n");
        next_day_q = create_queue_V();
        next_day_p = create_queue_M();
        sort_ItemL(&head) ;
        head = modify_status_list( head);
        X= long_list(head);
        afficher_tableau2(head,X);

        W5 = true;

        lanch_delivery2( head,p,q,next_day_q ,next_day_p,date_item(Y) );
        printf("\n");
        Succes();
        printf(BHYEL"\n\t\tThe delivry is done\n"reset);
        printf(BHYEL"\n\t\t> Press ENTER to see the result  ... \n"reset);
        ViderBuffer();
        printf("\n\n\n\n\n");
        X= long_list( head);
        afficher_tableau2(head,X);
        printf("\n");
        //print_ItemL(head);
        W2=W3=W4 = true;
        Simulate_end( head,&S,&H);
       }else{
         printf("You have already completed step 1.\n");
       }
        printf(BHYEL"\n\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 6:
      if(W1 && W5){
        Clear_Screen();
        W6 = true;
        printf("\n\n\t\t\t    Simulate the comeback of a vehicle :  \n\n\n");
        menu_case6(&headV, &head,&p,&q,&next_day_q,&next_day_p);
      }else if(W1 == false){
        printf("You have already completed step 1 then step 4.\n");
      }else{
        printf("You have already completed step 5.\n");
      }
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;
    case 7:
      if(W6){
        Clear_Screen();
        Red();
        printf("\n\n\n\n\t\t\t    Remove returned  and canceled items from the Item list:  \n\n\n");
        Reset();
        Yellow();
        printf("\nRemove cancled items first : \n");
        Reset();
        head =  delet_canceled_items( head);
        print_ItemL(head); 
        Yellow();
        printf("\nRemove returned  items  : \n");
        Reset();
        head = delet_return_items( head);
        print_ItemL(head);
        W7 = true;
      }else{
        printf("You have already completed step 6.\n");
      }
        printf(BHYEL"\n> Press ENTER to continue ... "reset);
        ViderBuffer();
        goto P;
        break;

    case 8:
      if(W7){
        Clear_Screen();
        printf("\n\n\t\t\t    Simulate the end of the day :  \n\n\n");

        choix_end_of_day( headV, head,p,q,S, H, sum_new, new_V,next_day_q,next_day_p);
       // printf(BHYEL"\n> Press ENTER to continue ... "reset);
       // ViderBuffer();

       W8 = true;
      }else{
        printf("You have already completed step 7.\n");
      }
        goto P;
        break;
    case 9:
      if(W8){
        Clear_Screen();
        printf("\n\n\t\t\t   Move for the next day  :  \n\n\n");
        char OUI;
        printf("\t Do you want to move to the next day (Y/N) ? :");
        scanf(" %c", &OUI); // Notice the space before %c to consume any leading whitespace
       if (OUI =='Y'|| OUI =='y'){
        
        destroy_V(next_day_q);
        destroy_M(next_day_p);
        menu3(headV, head, q, p);
       }
      }else{
        printf("You have already completed step 8.\n");
      }
       goto P; // Regardless of the choice, go back to the main menu
        break;
    case 10 :
        free_list( head);
        break;
    default:
        break;
    }


}

void PRINCIPAL_MENU(){
    I:
        printf("");
    int choice;
    menu8(&choice);

    switch (choice){
        case 1:
            Clear_Screen();
            menu2();
            printf(BHYEL"\n\n\n\n> Press ENTER to continue ... "reset);
            ViderBuffer();
            goto I;
            break;
        case 2:
           Clear_Screen();
           PRINT_INFO2();
           printf(BHYEL"\n\n\n\n> Press ENTER to continue ... "reset);
           ViderBuffer();
           goto I;
           break;
        case 3:
            about_us();
            printf(BHYEL"\n\n\n\n> Press ENTER to continue ... "reset);
            ViderBuffer();
            goto I;
            break;
        case 4:
           
            Clear_Screen();
            fin_programme();
            break;
        default:
           break;

    }
}




void goku() {
    printf("              `\\-.   `\n");
    printf("                      \\ `.  `\n");
    printf("                       \\  \\ |\n");
    printf("              __.._    |   \\.       S O N - G O K U\n");
    printf("       ..---~~     ~ . |    Y\n");
    printf("         ~-.          `|    |\n");
    printf("            `.               `~~--.\n");
    printf("              \\                    ~.\n");
    printf("               \\                     \\__. . -- -  .\n");
    printf("         .-~~~~~      ,    ,            ~~~~~~---...._\n");
    printf("      .-~___        ,'/  ,'/ ,\\          __...---~~~\n");
    printf("            ~-.    /._\\_( ,(/_. 7,-.    ~~---...__\n");
    printf("           _...>-  P\"\"6=`_\"/6\"~   6)    ___...--~~~\n");
    printf("            ~~--._ `\\`--') `---'   9'  _..--~~~\n");
    printf("                  ~\\ ~~/_  ~~~   /`-.--~~\n");
    printf("                    `.  ---    .'   \\_\n");
    printf("                      `. \" _.-'     | ~-.,-------._\n");
    printf("                  ..._../~~   ./       .-'    .-~~~-.\n");
    printf("            ,--~~~ ,'...\\` _./.----~~.'/    /'       `- \n");
    printf("        _.-(      |\\    `/~ _____..-' /    /      _.-~~`.\n");
    printf("       /   |     /. ^---~~~~       ' /    /     ,'  ~.   \\\n");
    printf("      (    /    (  .           _ ' /'    /    ,/      \\   )\n");
    printf("      (` |     `\\   - - - - ~   /'      (   /         .  |\n");
    printf("       \\.\\|       \\            /'        \\  |`.           /\n");
    printf("       /.'\\\\      `\\         /'           ~-\\         .  /\\\n");
    printf("      /,   (        `\\     /'                `.___..-      \\\n");
    printf("     | |    \\         `\\_/'                  //      \\.     |\n");
    printf("     | |     |                 _Seal_      /' |       |     |\n");
    printf("```\n");

    
}




void goku2() {
    printf("⣿⣿⠿⠿⠿⠿⣿⣷⣂⠄⠄⠄⠄⠄⠄⠈⢷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣷⡾⠯⠉⠉⠉⠉⠚⠑⠄⡀⠄⠄⠄⠄⠄⠈⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠎⠄⠄⣀⡀⠄⠄⠄⠄⠄⠄⠄⠘⠋⠉⠉⠉⠉⠭⠿⣿\n");
    printf("⡀⠄⠄⠄⠄⠄⠄⠄⠄⡇⠄⣠⣾⣳⠁⠄⠄⢺⡆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
    printf("⣿⣷⡦⠄⠄⠄⠄⠄⢠⠃⢰⣿⣯⣿⡁⢔⡒⣶⣯⡄⢀⢄⡄⠄⠄⠄⠄⠄⣀⣤⣶\n");
    printf("⠓⠄⠄⠄⠄⠄⠸⠄⢀⣤⢘⣿⣿⣷⣷⣿⠛⣾⣿⣿⣆⠾⣷⠄⠄⠄⢀⣀⣼⣿⣿\n");
    printf("⠄⠄⠄⠄⠄⠄⠄⠑⢘⣿⢰⡟⣿⣿⣷⣫⣭⣿⣾⣿⣿⣴⠏⠄⠄⢀⣺⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣷⠶⠄⠄⠄⠹⣮⣹⡘⠛⠿⣫⣾⣿⣿⣿⡇⠑⢤⣶⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣯⣤⣤⣤⣤⣀⣀⡹⣿⣿⣷⣯⣽⣿⣿⡿⣋⣴⡀⠈⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣝⡻⢿⣿⡿⠋⡒⣾⣿⣧⢰⢿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⣏⣟⣼⢋⡾⣿⣿⣿⣘⣔⠙⠿⠿⠿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⡿⢟⠩⠉⣠⣴⣶⢆⣴⡶⠿⠟⠛⠋⠉⠩⠄⠉⢀⠠⠂⠈⠄⠐⠄⠄⠄\n");

}
