#include "poly_lib.h"
#include "poly_lib.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Display.h"
#include <string.h>
#include <time.h>
#include <conio.h>


#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"
#define reset "\e[0m"
void ViderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
void Remove_Entree(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
void speak(char string[])
{
    char chaine[256];
    sprintf(chaine,"echo m=\"%s\" > file.vbs",string);
    system(chaine);
    sprintf(chaine,"echo CreateObject(\"SAPI.SpVoice\").Speak m >> file.vbs");
    system(chaine);
    sprintf(chaine,"file.vbs");
    system(chaine);
    remove("file.vbs");
}

void Animate_str(char string[],int speed)
{
    char *c = string;
    while(*c != 0)
    {
        printf("%c", *c);
        c++;
        usleep(speed);//90000
    }
}



int choix_polynome ( void )
{
    char chaine[256] = "";
    int i = 2;
    Clear_Screen();
    printf("\t\t\t\t\t ");
    Cyan();
    Animate_str("=== MENU ===",0);
    printf("\n\n\n");
    printf("\t__________________________________________________________________________________________________");
    for ( int i = 1 ; i<=8 ; i++ )
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
    Animate_str("1 --- Create a Polynomial", 4000);
    printf("\n\t\t ");
    Animate_str("2 --- Calculate the polynomial at a given point x.", 4000);
    printf("\n\t\t ");
    Animate_str("3 --- Derivative of a polynomial.", 4000);
    printf("\n\t\t ");
    Animate_str("4 --- Sum of two polynomials.", 4000);
    printf("\n\t\t ");
    Animate_str("5 --- Product of two polynomials.", 4000);
    printf("\n\t\t ");
    Animate_str("6 --- Quit", 4000);
    Reset();
    printf("\n\n\n\n");


    int did = 0;
Here:
     if (did == 0) {
        printf("\r\t\t\t\t ");
        Animate_str("Choix : ", 4000);
        printf("\r\t\t\t\t\t ");
    } else {
        Go_up(1);
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
    if ((strlen(Ans) != 1) || ((rep < '1') || (rep > '6'))) {
        Go_up_Clear_line(1);
        goto Here;
    }
    return atoi(Ans);
}


void polynomial_menu(void) {
    bool Q1, Q2, Q3, Q4, Q5;
    Q1 = Q2 = Q3 = Q4 = Q5 = false;
    int choice;
    char choice_char;

    do {
        system("cls");
        choice = choix_polynome();

        do {
            system("color 07");
            if (choice == 0 || choice > 6) {
                printf("Enter your choice between 0 and 9\n");
            }
        } while (choice == 0 || choice > 6);

        system("cls");
        switch (choice) {
            case 1:
                go1 :
                Q1 = true;
                system("cls");
                printf(HGRN"1. Create a Polynomial\n"reset);
                int degree;
                list *head;
                
                printf(HBLU"\nEnter size ",reset);
                scanf("%d", &degree);

                head = lect_poly(degree);
                Yellow();
                writepoly(head);
                Reset();
                if(Q1 && (choice ==2 || choice ==3)){
                     Q5 = true;
                    if(choice ==2){
                       goto go2; 
                    }else{goto go3;}
                  
                 
                }else{
                printf("\n> Press ENTER to continue ... ");
                ViderBuffer();
                }
                break;

            case 2:
                if (Q1 == true) {
                    go2 :
                    if(!Q5){system("cls");}
                    
                    printf(HGRN"2. Calculate Polynomial at a Given Point 'x'\n",reset);
                    printf("ENTER x: ");
                    int x, sum;
                    scanf("%d", &x);
                    sum = calcule(head, x);
                    Yellow();
                    printf("\nThe sum is: %d ", sum);
                    Reset();
                    printf("\n> Press ENTER to continue ... ");
                    ViderBuffer();
                } else {
                    printf("Perform step 1 first");
                    goto go1;
                }
                break;

            case 3:
                if(Q1){
                    go3:
                    if(!Q5){system("cls");}
                
                printf(HGRN"3. Calculate the Derivative of a Polynomial\n",reset);
                list *drv;
                derive(head, &drv);
                Yellow();
                writepoly(drv);
                Reset();
                printf("\n> Press ENTER to continue ... ");
                ViderBuffer();
                }else{
                    printf("Perform step 1 first");
                    goto go1;
                }
                break;

            case 4:
                system("cls");
                printf(HGRN"4. Sum of Two Polynomials\n",reset);
                int degree1, degree2;
                list *head1, *head2;

                printf(HGRN"Enter size for Polynomial 1: ",reset);
                scanf("%d", &degree1);
                head1 = lect_poly(degree1);
                Yellow();
                writepoly(head1);
                Reset();
                printf(HGRN"Enter size for Polynomial 2: ",reset);
                scanf("%d", &degree2);
                head2 = lect_poly(degree2);
                Yellow();
                writepoly(head2);
                
                list *sum_head = somme_poly(head1, head2);
                writepoly(sum_head);
                Reset();
                printf("\n> Press ENTER to continue ... ");
                ViderBuffer();
                break;

            case 5:
                system("cls");
                printf("5. Product of Two Polynomials\n");
                int degree3, degree4;
                list *head3, *head4;

                printf("Enter size for Polynomial 1: ");
                scanf("%d", &degree3);
                head3 = lect_poly(degree3);
                writepoly(head3);

                printf("Enter size for Polynomial 2: ");
                scanf("%d", &degree4);
                head4 = lect_poly(degree4);
                writepoly(head4);

                list *product_head = Mul_poly(head3, head4);
                writepoly(product_head);

                printf("\n> Press ENTER to continue ... ");
                ViderBuffer();
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);    

            default:
                printf("Invalid choice\n");
        }

        Reset();
        Red();
        printf("\nThis code will be repeated. Enter 'Y' to repeat or any other key to exit: ");
        Reset();

        scanf(" %c", &choice_char); // Note the space before %c to consume the newline character
        Reset();
        // Clear the input buffer
        while (getchar() != '\n');

    } while (choice_char == 'Y' || choice_char == 'y');
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void welcome()

{
    int k;
    system("Cls");
    for (k = 0; k < 10; k++)
    {
        if (k % 2 == 0)
            Cyan();
        if (k % 2 == 1)
            Yellow();
        printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t  .----------------.  .----------------.  .----------------.\n");
    printf("\t\t\t\t\t\t | .--------------. || .--------------. || .--------------. |\n");
    printf("\t\t\t\t\t\t | |  _________   | || |    _______   | || |     _____    | |\n");
    printf("\t\t\t\t\t\t | | |_   ___  |  | || |   /  ___  |  | || |    |_   _|   | |\n");
    printf("\t\t\t\t\t\t | |   | |_  \\_|  | || |  |  (__ \\_|  | || |      | |     | |\n");
    printf("\t\t\t\t\t\t | |   |  _|  _   | || |   \'.___`-.   | || |      | |     | |\n");
    printf("\t\t\t\t\t\t | |  _| |___/ |  | || |  |`\\____) |  | || |     _| |_    | |\n");
    printf("\t\t\t\t\t\t | | |_________|  | || |  |_______.\'  | || |    |_____|   | |\n");
    printf("\t\t\t\t\t\t | |              | || |              | || |              | |\n");
    printf("\t\t\t\t\t\t | \'--------------\' || \'--------------\' || \'--------------\' |\n");
    printf("\t\t\t\t\t\t  \'----------------\'  \'----------------\'  \'----------------\'\n");
    Reset();
    Sleep(200);
    system("cls");
    }
    Cyan();
    printf("\t\t\t\t\t\t          R%cpublique Alg%crienne D%cmocratique et Populaire           \n", 130, 130, 130);
    printf("\t\t\t\t\t\tMinist%cre de l'Enseignement Sup%crieur et de la Recherche Scientifique\n\n\n", 130, 130);
    printf("\t\t\t\t\t\t     _______________________________________________________\n");
    printf("\t\t\t\t\t\t    |        _______     _______     _                      |\n");
    printf("\t\t\t\t\t\t    |       |  _____|   |  _____|   | |  %ccole nationale    |\n", 130);
    printf("\t\t\t\t\t\t    |       | |_____    | |_____    | |                     |\n");
    printf("\t\t\t\t\t\t    |       |  _____|   |_____  |   | |  sup%crieure         |\n", 130);
    printf("\t\t\t\t\t\t    |       | |_____     _____| |   | |                     |\n");
    printf("\t\t\t\t\t\t    |       |_______|   |_______|   |_|  d'informatique     |\n");
    printf("\t\t\t\t\t\t    |_______________________________________________________|\n\n\n");
    Reset();
    Yellow();
    printf("\t\t\t\t\t\t\tCPI - 1%cre Ann%ce - Ann%ce Universitaire 2022/2023 \n\n\n", 138, 130, 130);
    printf("\t\t\t\t\t\t ___________________________________________________________________\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t| REALISE PAR :             BELATRACHE  ISHAK                       |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           SECTION : B           GROUPE: 05                        |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           EXO :            Polynome                               |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|___________________________________________________________________|\n\n\n");

    Reset();
    Sleep(200);
    Sleep(200);
    Cyan();
    printf("\n");
    speak("Welcome to the program, press any key to continue");
    printf("\t\t\t\t\t\t                             PLease                                         \n");
    printf("\t\t\t\t\t\t                    Press any key to continue..                             ");
    getch();
    Reset();
}
// charrgement affichage:
void Chargement()
{
    int i;
    for (i = 0; i < 2; i++)
    {
        system("cls");
        Yellow();
        gotoxy(12, 17);
        printf("\t\t\t\t\t\t\t\t  Loading.\n\n");
        Sleep(200);
        system(";cls");
        gotoxy(12, 17);
        printf("\t\t\t\t\t\t\t\t  Loading..\n\n");
        Sleep(200);
        system(";cls");
        gotoxy(12, 17);
        printf("\t\t\t\t\t\t\t\t  Loading...\n\n");
        Sleep(200);
        system(";cls");
        Reset();
    }
}

int main(){
    welcome();
   
    Chargement();
    
    polynomial_menu();

    return 0;
}
