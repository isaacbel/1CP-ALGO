#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <synchapi.h>
#include "conio2.h"
#include "conio2.c"
#include <stdbool.h>
#include <conio.h>
#include <winsock.h>
#include "BIB_standard.h"
#include "codes.c"
#include "BIB_standard.c"
#include <ctype.h>
#include <time.h>



void ViderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void Textecolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
// Texte couleur et fond:
void Color(int couleurdutexte, int couleurdufond)
{

    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurdufond * 16 + couleurdutexte);
}

void Remove_Entree(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


void loading(void)
{
    consoleCursor(false);
    int len;
    char str[] = "\\|/-";
    int j = 0;
    int x = wherex(), y = wherey();
    char load[36] = {};
    strcpy(load, "  Loading  ");
    while(true)
    {
        len = strlen(load);
        if (len>=35)
            break;
        gotoxy(x, y);
        printf("%c", str[j++]);
        Sleep(200);
        printf("%s", load);
        load[len] = '.';
        if(j == 4)
            j = 0;
    }

    consoleCursor(true);
    printf("  100 %c ", 37);
}


void printStrAnim(int speed, char string[])
{
    char *c = string;
    while(*c != 0)
    {
        printf("%c", *c);
        c++;
        usleep(speed);//90000
    }
}


void main_page(void)
{
    int speed = 5000;
    system("cls");
    system("color f0");
    textbackground(WHITE);
    textcolor(BLACK);
    printStrAnim(1000, "\t\t\t  +----------------------------------------------------------------------------------------------------------------+\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |       "); textcolor(BLUE); printStrAnim(speed, "\033[4mLe premier TP d'Algorithmique et structures de donnees dynamiques sur la gestion des e-recrutements"); textcolor(BLACK); printf("      |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printStrAnim(speed, "\t\t\t  |                                             Done by : "); textcolor(LIGHTBLUE); printf("Belatrache Ishak and Yagoub anes"); textcolor(BLACK); printf("                         |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printStrAnim(speed, "\t\t\t  |                                                 Group : "); textcolor(LIGHTBLUE); printf("05"); textcolor(BLACK); printf("                                                     |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printStrAnim(speed, "\t\t\t  |                                                 Section : "); textcolor(LIGHTBLUE); printf("B"); textcolor(BLACK); printf("                                                    |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printStrAnim(speed, "\t\t\t  |                                  Under the supervision of : "); textcolor(LIGHTBLUE); printf("Madame Chader Asma "); textcolor(BLACK); printf("                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printStrAnim(speed, "\t\t\t  |                                     Academic year  : "); textcolor(LIGHTBLUE); printf("2023/2024"); textcolor(BLACK); printf("                                                 |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printf("\t\t\t  |                                                                                                                |\n");
    printStrAnim(1000, "\t\t\t  +----------------------------------------------------------------------------------------------------------------+\n");

    int x,y;
    gotoxy(5,2);
    x=wherex();
    y=wherey();
    gotoxy(x,y);
    printStrAnim(1, "\t\t\t\t ______  _____  __ ");
    gotoxy(x,y+1);
    printStrAnim(speed, "\t\t\t\t|  ____|/ ____||__|");
    gotoxy(x,y+2);
    printStrAnim(speed, "\t\t\t\t| |__  | (___   __ ");
    gotoxy(x,y+3);
    printStrAnim(speed, "\t\t\t\t|  __|  \\___ \\ |  |");
    gotoxy(x,y+4);
    printStrAnim(speed, "\t\t\t\t| |____ ____) ||  |");
    gotoxy(x,y+5);
    printStrAnim(speed, "\t\t\t\t|______|_____/ |__|");
    textcolor(LIGHTBLUE);
    gotoxy(x+15,y);
    printStrAnim(speed, "\t\t\t\t __");
    gotoxy(x+15,y+1);
    printStrAnim(speed, "\t\t\t\t|__|");
    textcolor(BLACK);
    gotoxy(x+21,y+1);
    printStrAnim(speed, "\t\t\t\tNational School");
    gotoxy(x+21,y+3);
    printStrAnim(speed, "\t\t\t\tof Computer Science");
    gotoxy(x+21,y+5);
    printStrAnim(speed, "\t\t\t\tSuperior");

    gotoxy(1, 29);
    printf("\t\t\t\t    ");
    pause();
    system("color 07");
    textbackground(BLACK);
    return;
}

//--------------------------------------------------------------------------------------------------------



void PRINT_ESI(void)
{
    printf("\n");
    system("color f1");
    int delay = 50;
    printf("\t\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                  @@@@@@@@@@      @@        @@@@@@@@@@@@@@@\n");Sleep(delay);
    printf("\t\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@ @@@         @@@@@@@@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@       @@@@@@@@@@@           @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@                 @@@@@         @@@@@              @@@@@@@            @@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@                    @@@@        @@@@                 @@@@@@           @@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@                    @@@       @@@@@                  @@@@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@          @@@        @@       @@@@@@                   @@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@          @@@                  @@@@@@@                  @@          @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@         @@@@                  @@@@@@@@@@@                          @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@        @@@@@                    @@@@@@@@@@@@@@@                    @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@@@@@@@@@@@@@@                      @@@@@@@@@@@@@@@@@                @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@@@@@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@            @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@        @@@@@                               @@@@@@@@@@@@@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@         @@@@                                     @@@@@@@@@         @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@          @@@                @@@@                    @@@@@@@        @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@          @@@         @@@    @@@@                     @@@@@@        @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@                     @@@@     @@@@                     @@@@@        @@@@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@                    @@@@      @@@@@@                   @@@@@         @@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@                  @@@@@@       @@@@@@                 @@@@@           @@@@@\n");Sleep(delay);
    printf("\t\t\t     @@@@@@                @@@@@@@        @@@@@@@@@            @@@@@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@ @@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@\n");Sleep(delay);
    printf("\t\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@    @@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@\n\n");Sleep(delay);

    printf("\033[4;34m\n\t\t\t\t\t\t\tTP 1  ALSDD");
    textbackground(WHITE);
    textcolor(BLUE);
    printf("\n\n\t\t\t\t\t");
    loading();
    speak("Welcome to the program, press any key to continue");
    printf("\n\t\t\t\t\tAppuyez sur une touche pour commencer ... ");
    getch();
}

//--------------------------------------------------------------------------------------------------------

void PRINT_INFO(void)
{
    system("cls");
    system("color 07");
    textbackground(BLACK);
    char chaine[256] = "";
    int i = 2;

    textcolor(WHITE);
    printf("  +----------------------------------------------------------------------------------------------------------------+\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  +----------------------------------------------------------------------------------------------------------------+\n");//27

    gotoxy(4,i);
    textcolor(LIGHTRED);
    FILE *fichier = fopen("files/Items.txt", "r");

        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(! feof(fichier))
        {
            fgets(chaine, 256, fichier);
            printStrAnim(40000, chaine);
            strcpy(chaine, "");
            i++;
            gotoxy(4, i);

            if(i > 11)
                textcolor(LIGHTBLUE);
        }

    fclose(fichier);


    gotoxy(1, 29);
    printf("\t\t\t\t    ");
    textcolor(WHITE);
    pause();
    system("color 07");
}

//--------------------------------------------------------------------------------------------------------

void fin_programme(void)
{
    consoleCursor(FALSE);
    system("cls");
    system("color f0");
    textbackground(WHITE);
    int i = 0;
    int maxColors = 3;
    int colors[] = {LIGHTBLUE, BLUE, BLACK};
    int speed = 10;
    while(1)
    {
        if(isPressedEnter())
            if(isPressedEnter())
                break;

        gotoxy(1,1);
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                  @@@@@@@@@@      @@        @@@@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@ @@@         @@@@@@@@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@       @@@@@@@@@@@           @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                 @@@@@         @@@@@              @@@@@@@            @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                    @@@@        @@@@                 @@@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@       @@@@@                  @@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@        @@       @@@@@@                   @@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                  @@@@@@@                  @@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                  @@@@@@@@@@@                          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                    @@@@@@@@@@@@@@@                    @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                      @@@@@@@@@@@@@@@@@                @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@            @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                               @@@@@@@@@@@@@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                                     @@@@@@@@@         @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                @@@@                    @@@@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@         @@@    @@@@                     @@@@@@        @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@                     @@@@     @@@@                     @@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@@      @@@@@@                   @@@@@         @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                  @@@@@@       @@@@@@                 @@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                @@@@@@@        @@@@@@@@@            @@@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@ @@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@    @@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@\n\n");

      textcolor(BLUE);
printf("\n\t\t\t\t\t\tThank you for using my TP\n\n");

textcolor(RED);
printf("\t\033[4mDone by :");

textcolor(LIGHTRED);
printf(" Belatrache Isaac    ");

textcolor(RED);
printf("\033[4mGroup :");

textcolor(LIGHTRED);
printf(" 05    ");

textcolor(RED);
printf("\033[4mSection :");

textcolor(LIGHTRED);
printf(" B    ");

textcolor(RED);
printf("\033[4mUnder the supervision of :");

textcolor(LIGHTRED);
printf(" Mrs. TEMGLIT Nacera \n\n");

textcolor(BLUE);
 printf("\t\t\t\t\t\tPress ENTER to exit ... ");
    speak("Thanks for using my program");
    system("color 07");
    system("cls");
    exit(0); // Sortit du programme !!
}

}
void Succes() {
Color(10,0);
Sleep(700);
printf("\n\t\t\t\t                                                                 /@@@@,         \n");
printf("\t\t\t\t                                                              @@@@@@@@@@       \n");Sleep(200);
printf("\t\t\t\t                                                          /@@@@@@@@@@@@@@,    \n");
printf("\t\t\t\t                                                         @@@@@@@@@@@@@@@@@@@@  \n");
printf("\t\t\t\t                                                      /@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t\t\t\t                                                     @@@@@@@@@@@@@@@@@@@@@@@@&  \n");Sleep(200);
printf("\t\t\t\t                                                  /@@@@@@@@@@@@@@@@@@@@@@@@.    \n");
printf("\t\t\t\t                                                @@@@@@@@@@@@@@@@@@@@@@@@&       \n");
printf("\t\t\t\t                                             /@@@@@@@@@@@@@@@@@@@@@@@@.         \n");
printf("\t\t\t\t            @,                             @@@@@@@@@@@@@@@@@@@@@@@@&            \n");
printf("\t\t\t\t         *@@@@@@                        /@@@@@@@@@@@@@@@@@@@@@@@@.              \n");Sleep(200);
printf("\t\t\t\t       @@@@@@@@@@@,                   @@@@@@@@@@@@@@@@@@@@@@@@&                 \n");
printf("\t\t\t\t    *@@@@@@@@@@@@@@@@              /@@@@@@@@@@@@@@@@@@@@@@@@.                   \n");
printf("\t\t\t\t  @@@@@@@@@@@@@@@@@@@@@,         @@@@@@@@@@@@@@@@@@@@@@@@&                      \n");
printf("\t\t\t\t @@@@@@@@@@@@@@@@@@@@@@@@&    /@@@@@@@@@@@@@@@@@@@@@@@@.                        \n");
printf("\t\t\t\t   *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&                           \n");
printf("\t\t\t\t      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                             \n");
printf("\t\t\t\t        *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&                                \n");Sleep(200);
printf("\t\t\t\t           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                                  \n");
printf("\t\t\t\t             *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                     \n");
printf("\t\t\t\t                @@@@@@@@@@@@@@@@@@@@@@@@.                                       \n");
printf("\t\t\t\t                  *@@@@@@@@@@@@@@@@@@@                                          \n");Sleep(200);
printf("\t\t\t\t                     @@@@@@@@@@@@@@.                                            \n");
printf("\t\t\t\t                       *@@@@@@@@@                                               \n");
printf("\t\t\t\t                          @@@@.                                                 \n");Sleep(200);
Color(15,0);
}


int up=80,down=72,margin=20;
void bleu(){textbackground(RED);}
void vert(){textcolor(GREEN);}
void noire(){textbackground(BLACK);}
void jaunet(){textcolor(BROWN);}
void noiret(){textcolor(WHITE);}
void bleut(){textcolor(BLUE);}
void rouget(){textcolor(RED);}


void menu(int* choix)
{
    clrscr();
    noire();
    int c ;
    int cpt = 1;
    int y=2;
    gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
    y++;
    gotoxy(margin,y++);bleut();printf("                       Delivery company management        \n");noiret();
    y++;
    gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
    y++;
    gotoxy(margin,y++);bleu();printf("Create the different lists and queues models and get information loaded into lists and queue \n");noire();
    y++;
    gotoxy(margin,y++);printf("                        Add a new item to the ItemL list (new delivery item)                         \n");
    y++;
    gotoxy(margin,y++);printf("                               Add a new vehicle to the VehicleL list                                \n");
    y++;
    gotoxy(margin,y++);printf("                                         delete a vehicle                                            \n");
    y++;
    gotoxy(margin,y++);printf("                                   Simulate the delivery operation                                    \n");
    y++;
    gotoxy(margin,y++);printf("                                  Simulate the comeback of a vehicle                                  \n");
    y++;
    gotoxy(margin,y++);printf("                   Simulate the returns pick-up (by the sender) or delivery cancellation               \n");
    y++;
    gotoxy(margin,y++);printf("                                      Simulate the end of the day                                      \n");
    y++;
    gotoxy(margin,y++);printf("                                      Move for the next day                                       \n");
    y++;
    gotoxy(margin,y++);printf("                                              QUITTER                                                   \n");
    y++;
    gotoxy(margin,y++);vert();printf("             =========================================================\n");noiret();
    do{
        c=getch();
        if(c==up){cpt%=11;cpt++;}
        if(c==down){cpt--;if(cpt==0)cpt=11;}
        noire();
        y=2;
        gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
        y++;
        gotoxy(margin,y++);bleut();printf("                       Delivery company management        \n");noiret();noire();
        y++;
        gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
        y++;
        gotoxy(margin,y++);if(cpt==1)bleu();printf("Create the different lists and queues models and get information loaded into lists and queue \n");noire();              
        y++;
        gotoxy(margin,y++);if(cpt==2)bleu();printf("                        Add a new item to the ItemL list (new delivery item)                  \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==3)bleu();printf("                                 Add a new vehicle to the VehicleL list                       \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==4)bleu();printf("                                            delete a vehicle                                  \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==5)bleu();printf("                                   Simulate the delivery operation                             \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==6)bleu();printf("                                  Simulate the comeback of a vehicle                           \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==7)bleu();printf("                Simulate the returns pick-up (by the sender) or delivery cancellation          \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==8)bleu();printf("                                      Simulate the end of the day                              \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==9)bleu();printf("                                      Move for the next day                                    \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==10)bleu();printf("                                              QUITTER                                         \n");noire();
        y++;
        gotoxy(margin,y++);vert();printf("             =========================================================\n");noiret();
    } while(c!=13);
    if(c==13)
    {
      *choix = cpt;
    }

}



void menu4(int* choix)
{
    clrscr();
    noire();
    int c ;
    int cpt = 1;
    int y=2;
    gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
    y++;
    gotoxy(margin,y++);bleut();printf("                       Delivery company management        \n");noiret();
    y++;
    gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
    y++;
    gotoxy(margin,y++);bleu();printf("             Affiche Items list , Vehicle litst,Van queue and Moto queue                      \n");noire();
    y++;
    gotoxy(margin,y++);printf("                        Add a new item to the ItemL list (new delivery item)                         \n");
    y++;
    gotoxy(margin,y++);printf("                               Add a new vehicle to the VehicleL list                                \n");
    y++;
    gotoxy(margin,y++);printf("                                         delete a vehicle                                            \n");
    y++;
    gotoxy(margin,y++);printf("                                   Simulate the delivery operation                                    \n");
    y++;
    gotoxy(margin,y++);printf("                                  Simulate the comeback of a vehicle                                  \n");
    y++;
    gotoxy(margin,y++);printf("                   Simulate the returns pick-up (by the sender) or delivery cancellation               \n");
    y++;
    gotoxy(margin,y++);printf("                                      Simulate the end of the day                                      \n");
    y++;
    gotoxy(margin,y++);printf("                                      Move for the next day                                            \n");
    y++;
    gotoxy(margin,y++);printf("                                              QUITTER                                                   \n");
    y++;
    gotoxy(margin,y++);vert();printf("             =========================================================\n");noiret();
    do{
        c=getch();
        if(c==up){cpt%=11;cpt++;}
        if(c==down){cpt--;if(cpt==0)cpt=11;}
        noire();
        y=2;
        gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
        y++;
        gotoxy(margin,y++);bleut();printf("                       Delivery company management        \n");noiret();noire();
        y++;
        gotoxy(margin,y++);vert();printf("            =========================================================\n");noiret();
        y++;
        gotoxy(margin,y++);if(cpt==1)bleu();printf("                  Affiche Items list , Vehicle litst,Van queue and Moto queue                      \n");noire();              
        y++;
        gotoxy(margin,y++);if(cpt==2)bleu();printf("                        Add a new item to the ItemL list (new delivery item)                  \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==3)bleu();printf("                                 Add a new vehicle to the VehicleL list                       \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==4)bleu();printf("                                            delete a vehicle                                  \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==5)bleu();printf("                                   Simulate the delivery operation                             \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==6)bleu();printf("                                  Simulate the comeback of a vehicle                           \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==7)bleu();printf("                Simulate the returns pick-up (by the sender) or delivery cancellation          \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==8)bleu();printf("                                      Simulate the end of the day                              \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==9)bleu();printf("                                      Move for the next day                                      \n");noire();
        y++;
        gotoxy(margin,y++);if(cpt==10)bleu();printf("                                              QUITTER                                         \n");noire();
        y++;
        gotoxy(margin,y++);vert();printf("             =========================================================\n");noiret();
    } while(c!=13);
    if(c==13)
    {
      *choix = cpt;
    }

}
void MOTO() {
  printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                                                                                                     .   \n");
    printf("                                                                                                   ..=#@@@@@@%+. \n");
    printf("                                                                                                  .#@@@@%#*%@@@@%: \n");
    printf("                                                                                                .:@@@*...  ...+@@@+. \n");
    printf("                                                                                                :@@@:.      ....@@@==+*+. \n");
    printf("                                                                                               .+@@@@@@@@@@@@@@@@@@@@@@@*. \n");
    printf("                                                                                               .*@@@@@@@%%@@@@@@@@@*..... \n");
    printf("                                                                                               .-@@%..        ..+@@#. \n");
    printf("                                                                                                .%@@%.        .+@@%. \n");
    printf("                                                                                                  *@@@#:....:*@@@%. \n");
    printf("                                                                                                 .-%@@@@@@@@@@@%:.. \n");
    printf("                                                                                               .-@@@@%##%@@@@=. \n");
    printf("                                                                                              .*@@@-..  ..:@@@*. \n");
    printf("                                                                                             .%@@#.        .#@@#. \n");
    printf("                                              ..+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.           .%@@*..         .%@@#. \n");
    printf("                                              .#@@%#########@@@###@@@#########@@@..         #@@*.           ..#@@+. \n");
    printf("                                              .@@@.........-@@#. -@@%...     .@@@:.       .*@@#.              .%@@+. \n");
    printf("                                              .@@@..      .-@@%*+*@@%.       .@@@:.      .:@@@..               .@@@-.                   .    .                                      \n");
    printf("                                              .@@@..      .-@@@@@@@@#.       .@@@:.      .@@@:..        .:+:.   .@@@-.           .....-=+*****=..                                  \n");
    printf("                                              .@@@..       .........         .@@@:.     .+@@*..         *@@@*.   :@@@-...    .=#%@@@@@@@@@@@@@@#.                                  \n");
    printf("                                              .@@@..                         .@@@:.     :@@@..        .+@@@@@*.  .-@@@@@@@@@@@@@@@@*=:......#@@=.                                  \n");
    printf("                                              .@@@..                         .@@@:.    .%@@=.         :@@@.%@@=.  ...:+%@@@@@@@@@@-..      .@@@..                                  \n");
    printf("                                              .@@@..                         .@@@:.    :@@@.         .@@@-..@@@=       .   ...:+@@@=.      .@@@.                                   \n");
    printf("                                       ........@@@...............            .@@@:.   .*@@#:......  .*@@+...:@@@@%+:.......    .-@@#.      :@@%.                                   \n");
    printf("                                      .#@@@@@@@@@@@@@@@@@@@@@@@@.            .@@@:.   .@@@@@@@@@@@#=-@@@.     *@@@@@@@@@@@%*-:.:@@@-.     .-@@#.                                   \n");
    printf("                                       .+******@@@************+:.            .@@@:.   =@@#..-+%%@@@@@@@-.     ......-+#%@@@@@@@@@@=.%@@@@#+*@@+                                    \n");
    printf("                                              .@@@...                        .@@@:.   *@@+.     ...:@@%:.....         .  ..-@@@+....%@@@@@@@@@:                                    \n");
    printf("                      .*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-.                 .@@@:. ..#@@-.        :@@@@@@@@@#+-:.....      -@@@.....@@@=.....                                     \n");
    printf("                      .-#%%%%%%%%%%%%%%%%%%%%%%@@@%%%%%%%#:                  .@@@:. ..#@@-          ...-+*%@@@@@@@@@@#=...  .#@@*....:@@@:.                                        \n");
    printf("                                                     ..@@@..                         .@@@-  .*@@@%=-:..-@@#........:-#@@@@=. .+@@@+.           .:#@@@@%%@@@-.                  \n");
    printf("                                                      .@@@=.   :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.   @@@.    .%@@:    .:@@@-.                                        \n");
    printf("                                                      .:@@@-.   ..*@@@@@*..   .=@@@..                                           ..%@@%.   ..=@@@@@%:.    :@@@=.                                 \n");
    printf("                                                       ..@@@#..      .       .%@@@.                                                *@@@-.      . ..    .+@@@=.                                  \n");
    printf("                                                        ..+@@@@-...     ...-@@@@+.                                                  .:@@@@+....    ...:#@@@%.                                    \n");
    printf("                                                          ..+@@@@@@#+++#@@@@@@+...                                                    .-%@@@@@%*++*%@@@@@#.                                      \n");
    printf("                                                            ...+%@@@@@@@@@#=......                                                      ..-#@@@@@@@@@%*:..                                       \n");
    printf("                                                                 .. ..............                                                          ..........                         \n");
    printf("                                                                                                                                                             \n");
    printf("                                                                                                                                                             \n");
    printf("                                                                                                                                                              \n");
    Sleep(20);
    system("cls");

}


void VAN() {
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                               =*-                                                            \n");
    printf("                                                                             =#####.                                                          \n");
    printf("                                                                           =##+  -##+                                                         \n");
    printf("                                                                         +##+      +##-                                                       \n");
    printf("                                                          :*##=        +##=         =##-                                                  \n");
    printf("                                                        .###-*##.   .*##=         :###-                                                   \n");
    printf("                                                      :*#*-   :*#*-*##-         -#####################*                                   \n");
    printf("                                                     ###:       =###-         =###.                 -#*                                   \n");
    printf("                                                     .*#*.        .         =##*.                   -#########*=:                         \n");
    printf("                                                       -##+               =##*                      -#* .##: :+####*.                     \n");
    printf("                                                         +##-           +##+                        -#* .##:     .=###-                   \n");
    printf("                                                         .###*.       +##+                          -#* .##:        .*##-                 \n");
    printf("                                                         .##*##=    +##+                            -#* .##:          .*#*.               \n");
    printf("                                                         .##: +##=+##=                              -#* .##:            =##.              \n");
    printf("                                                         .##:  :###=                                -#*  ##-             -##:             \n");
    printf("                                                         .##:                                       -#*  :##:             =#*             \n");
    printf("                                                         .##:                                       -#*   .##*.            ##:            \n");
    printf("                                                         .##:                                       -#*     -####**********##+            \n");
    printf("                                                         .##:                                       -#*         :==========+##            \n");
    printf("                                                         .##:                                       -#*                    .##            \n");
    printf("                                                         .##-.......................................=#*                    .##            \n");
    printf("                                                         .############################################+                    .##            \n");
    printf("                                                         .##:                                                              .##            \n");
    printf("                                                         .##:        .+###*:                                =*##*-         .##            \n");
    printf("                                                         .##:      -###=-=*##+                           :*##+--+##*.      .##            \n");
    printf("                                                         .##:     =#*.      +#*                         :##:      =##      :##            \n");
    printf("                                                          *#*-:::-*#-        *#=:::::::::::::::::::::::-*#+        +#+:::-+##:            \n");
    printf("                                                           :########=        #############################+        +#######=              \n");
    printf("                                                                  -##-     .##+                         .##=      *#*                     \n");
    printf("                                                                   .*##***###-                            +###**###+                      \n");
    printf("                                                                      :=+=-                                 .=++-.                        \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                                                                                              \n");
    printf("                                                                 -****-  ****+ =+    *-=*.  :*.+**** =***+.-*   *:                            \n");
    printf("                                                                 =*   ** #+..  +*    #= *+  #: *-..  ++  ** =*=#:                             \n");
    printf("                                                                 =*   ** #+..  +*    #=  *=*=  *-..  +#*#*.  -#.                               \n");
    printf("                                                                 =####=  ####*.=###*.#=  :**   *#### ++ .*=  :#                                \n");
    Sleep(20);
    system("cls");
}


void Welcome1()
{
    system("cls");
    for (int k = 0; k < 10; k++)
    {
        if (k % 2 == 0)
            Textecolor(5);
        if (k % 2 == 1)
            Textecolor(3);
printf("\n\n\n\n\n\n\n");
 Color(6,0);
    printf("\t\t\t\t\t\t         _____ ____    _      _    _     ____  ____  ____   \n");
    printf("\t\t\t\t\t\t       |_   _|  _ \\  / |    / \\  | |   / ___||  _ \\|  _ \\  \n");
    printf("\t\t\t\t\t\t          | | | |_) | | |   / _ \\ | |   \\___ \\| | | | | | | \n");
    printf("\t\t\t\t\t\t          | | |  __/  | |  / ___ \\| |___ ___) | |_| | |_| | \n");
    printf("\t\t\t\t\t\t          |_| |_|     |_| /_/   \\_\\_____|____/|____/|____/  \n\n\n");
printf("\t\t\t\t\t\t               ____       _ _                                          \n");
printf("\t\t\t\t\t\t               ____       _ _                                          \n");
printf("\t\t\t\t\t\t              |  _ \\  ___| (_)_   _____ _ __ _   _                     \n");
printf("\t\t\t\t\t\t              | | | |/ _ \\ | \\ \\ / / _ \\ '__| | | |                    \n");
printf("\t\t\t\t\t\t              | |_| |  __/ | |\\ V /  __/ |  | |_| |                    \n");
printf("\t\t\t\t\t\t              |____/ \\___|_|_| \\_/ \\___|_|   \\__, |                    \n");
printf("\t\t\t\t\t\t              ___ ___  _ __ ___  _ __   __ _ |___/ _   _               \n");
printf("\t\t\t\t\t\t             / __/ _ \\| '_ ` _ \\| '_ \\ / _` | '_ \\| | | |              \n");
printf("\t\t\t\t\t\t            | (_| (_) | | | | | | |_) | (_| | | | | |_| |              \n");
printf("\t\t\t\t\t\t             \\___\\___/|_| |_| |_| .__/ \\__,_|_| |_|\\__, |          _  \n");
printf("\t\t\t\t\t\t       _ __ ___   __ _ _ __   __|_| __ _  ___ _ __ |___/ ___ _ __ | |_ \n");
printf("\t\t\t\t\t\t      | '_ ` _ \\ / _` | '_ \\ / _` |/ _` |/ _ \\ '_ \\| | | |/ _ \\ '_ \\| __|\n");
printf("\t\t\t\t\t\t      | | | | | | (_| | | | | (_| | (_| |  __/ | | | |_| |  __/ | | | |_ \n");
printf("\t\t\t\t\t\t      |_| |_| |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_|\\__,_|\\___|_| |_|\\__|\n");
printf("\t\t\t\t\t\t                                   |___/                               \n");

Sleep(200);
system("cls");

}
    system("cls");
}

void Welcome2()
{
    system("cls");
    for (int k = 0; k < 2; k++)
    {
        if (k % 2 == 0)
            Textecolor(5);
        if (k % 2 == 1)
            Textecolor(3);
          MOTO();
          VAN();

    }
    system("cls");
}     


void afficher_tableau2(ptr head, int taille) {
    ptr current = head;
    if (head == NULL){
        printf("\nThe list is empty . \n");
    }
    if (taille > 30) {
        int remaining = taille / 2; // Number of elements beyond the first 15
        Red();
        printf("_________________________________________________________________________     _________________________________________________________________________\n");
        printf("| %-12s | %-8s | %-8s | %-20s | %-10s |   | %-12s | %-8s | %-8s | %-20s | %-10s |\n", "Identifier", "Weight", "Wilaya", "Status", "Date", "Identifier", "Weight", "Wilaya", "Status", "Date");
        printf("|--------------|----------|----------|----------------------|------------|   |--------------|----------|----------|----------------------|------------|\n");
        Reset();

        // Print rows in parallel until one table is exhausted
        for(int i = 0; i <= remaining || i <= taille - remaining ;i++) {
            // Print row from the first table
            if (i < remaining) {
               printf("| %-12d | %-8.2f | %-8d | %-20s | %-10s |   ", 
               ident_item(current), weight_item(current), wilaya_item(current),
               status_item(current), date_item(current));
            } else {
                printf("| %-12s | %-8.2s | %-8s | %-20s | %-10s |   ", "", "", "","","");
            }

            // Print row from the second table if available   accesspos(head,i + remaining)
            if (i < taille - remaining) {
                printf("| %-12d | %-8.2f | %-8d | %-20s | %-10s |\n",  ident_item(accesspos(head,i + remaining+1)), weight_item(accesspos(head,i + remaining+1)), wilaya_item(accesspos(head,i +1+ remaining)),
               status_item(accesspos(head,i + remaining+1)), date_item(accesspos(head,i + remaining+1)));
            } else {
                printf("| %-12s | %-8.2s | %-8s | %-20s | %-10s |\n", "", "", "","","");
            }
            
            current = Next(current);
        }
        printf("|______________|__________|__________|______________________|____________|   |______________|__________|__________|______________________|____________|");
        
    }else{
         Red();
         printf("|--------------|----------|----------|----------------------|------------|\n");
         printf("| %-12s | %-8s | %-8s | %-20s | %-10s |\n", "Identifier", "Weight", "Wilaya", "Status", "Date");
         printf("|--------------|----------|----------|----------------------|------------|\n");
         Reset();
        for (int i = 0; i < taille; i++) {
        printf("| %-12d | %-8.2f | %-8d | %-20s | %-10s |\n", ident_item(current), weight_item(current), wilaya_item(current),
               status_item(current), date_item(current));
               current = Next(current);

       }
       printf("|______________|__________|__________|______________________|____________|");
      
    }
    
}




void printPattern() {
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                               ..:++.     \n");
    printf("                             .-+*+:.      \n");
    printf("                         ..:****:.        \n");
    printf("                       .:+****-..         \n");
    printf("      ...             .=*****=.            \n");
    printf("    .:****=.       .:+*****=.              \n");
    printf("    .=*****-      :******+..               \n");
    printf("     .******.  .=******+..                 \n");
    printf("     .-*****+:+*******:..                  \n");
    printf("      .+***********+-.                     \n");
    printf("      .:**********-.                       \n");
    printf("       .=*******=.                         \n");
    printf("        .****+-..                          \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
    printf("                                           \n");
}



void Disclaimer_Page ( void )
{
    Clear_Screen();
    Red();
    printf("\n");
    printf("\t########################################################################################################\n");
    printf("\t########################################################################################################\n");
    for ( int i = 1 ; i<=30 ; i++ )
    {
        printf("\t##\t\t\t\t\t\t\t\t\t\t\t\t      ##\n");
        usleep(10000);
    }
    printf("\t########################################################################################################\n");
    printf("\t########################################################################################################\r");
    Go_up(26);
    printf("\t\t\t\t\t\t            *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t           * *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t          *   *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t         *  #  *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t        *   #   *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t       *    #    *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t      *     #     *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t     *      #      *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t    *       @       *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t   *                 *");printf("\n");usleep(20000);
    printf("\t\t\t\t\t\t  * * * * * * * * * * *");printf("\n\n");usleep(20000);
    
    printf("\t\t\t\t\t\t");
    printStrAnim(0, "      WARNING !!! ");
    Reset();
    printf("\n\n\n\t\t\t    ");
    printStrAnim(0, "** Please do not interrupt the execution of the program **");
    printf("\n\n\t\t\t          ");
    printStrAnim(0, "any progress will not be saved in this case");
    printf("\n\n\t\t\t          ");
    printStrAnim(0, "All instruction are interconnected and the order is respected ");
    Cyan();
    printf("\n\n\n\n\n\n\t\t\t\t\t");
    printStrAnim(0, "Press any key to continue...");
    Reset();
    fflush(stdin);
    getch();
}


void page_acceuil() {
    system("Cls"); // Effacer l'ecran
    int k ;
    for (k = 0 ; k<10 ; k++ ) {  // Afficher 10 fois le logo de ESI
        if (k % 2 == 0) // Les iterations paires s'afficherent en vert
        system("color 0A");
        if (k % 2 == 1) // Les iterations impaires s'afficherent en ciane
        system("color 0B");

        printf("\n\n\n\n\n\n"); // imprimer le logo de ESI
        printf(
            "\t\t\t\t                                              iiii\n"
            "\t\t\t\t                                             i::::i\n"
            "\t\t\t\t                                              iiii\n\n"
            "\t\t\t\t        eeeeeeeeeeee          ssssssssss    iiiiiii\n"
            "\t\t\t\t      ee::::::::::::ee      ss::::::::::s   i:::::i\n"
            "\t\t\t\t     e::::::eeeee:::::ee  ss:::::::::::::s   i::::i\n"
            "\t\t\t\t    e::::::e     e:::::e  s::::::ssss:::::s  i::::i\n"
            "\t\t\t\t    e:::::::eeeee::::::e   s:::::s  ssssss   i::::i\n"
            "\t\t\t\t    e:::::::::::::::::e      s::::::s        i::::i\n"
            "\t\t\t\t    e::::::eeeeeeeeeee          s::::::s     i::::i\n"
            "\t\t\t\t    e:::::::e             ssssss   s:::::s   i::::i\n"
            "\t\t\t\t    e::::::::e            s:::::ssss::::::s i::::::i\n"
            "\t\t\t\t     e::::::::eeeeeeee    s::::::::::::::s  i::::::i\n"
            "\t\t\t\t      ee:::::::::::::e     s:::::::::::ss   i::::::i\n"
            "\t\t\t\t        eeeeeeeeeeeeee      sssssssssss     iiiiiiii\n"
        );

        Sleep(200);     // Attendre 200 ms (0,2 s) a chaque iteration
        system("cls");
    }

    system("cls");  // effacer l'ecran
    printf("\t\t\t\033[96m           R%cpublique Alg%crienne D%cmocratique et Populaire           \033[0m\n", 130, 130, 130);
    printf("\t\t\t\033[96m  Minist%cre de l'Enseignement Sup%crieur et de la Recherche Scientifique\033[0m\n", 130, 130);
    printf("\t\t\t      \033[96m _______________________________________________________\n");
    printf("\t\t\t      \033[96m|        \033[92m_______\033[0m    \033[91m _______\033[0m    \033[97m _\033[0m                      \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|  _____|\033[0m   \033[97m| |\033[0m  \033[92m%ccole nationale\033[0m    \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m| |_____\033[0m    \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|_____  |\033[0m   \033[97m| |\033[0m  \033[91msup%crieure\033[0m         \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m _____| |\033[0m   \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|_______|\033[0m   \033[91m|_______|\033[0m   \033[97m|_|\033[0m  \033[97md'informatique\033[0m     \033[96m|\n");
    printf("\t\t\t      \033[96m|_______________________________________________________|\033[0m\n\n");

    printf("\t\t\t\t\033[96m  CPI - 1%cre Ann%ce - Ann%ce Universitaire 2022/2023 \n", 138, 130, 130);
    printf("\t\t\t\033[96m ___________________________________________________________________\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|     REALISE PAR :  \033[97mMOSTEFAI MOUNIR SOFIANE\033[96m                        |\n");
    printf("\t\t\t\033[96m|                              &                                    |\n");
    printf("\t\t\t\033[96m|                           \033[97mKHALEF BADIS\033[96m                            |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|               SECTION :  \033[97mB\033[96m          GROUPE: \033[97m04\033[96m                    |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|             TP1 :  \033[97mLes listes lin%caires chain%ces\033[96m                  |\n", 130, 130);
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|                         <  \033[97mdictionnaire\033[96m >                         |\n");
    printf("\t\t\t\033[96m|___________________________________________________________________|\n\n\n");


    printf("\t\t\t                            \033[91mS'il vous plait                                 \n");
    printf("\t\t\t          Appuyez sur n'importe quelle touche pour continuer...\033[0m               ");
    getch();

    system("cls");
}

void PRINT_INFO2(void) {
    system("cls");
    system("color 07");
    textbackground(BLACK);
    char chaine[256] = "";

    FILE *fichier = fopen("files/enonce.txt", "r");

    if (fichier == NULL) {
        printf("Probleme d'ouverture de fichier!\n");
        exit(EXIT_FAILURE);
    }

    int numLines = countLines("files/enonce.txt");
    int i = 1;

    printf("\n____________________________________________________________________________________________________________________________");
    for (int j = 1; j < numLines; j++) {
        
        fgets(chaine, 256, fichier);
        
        
       printf("\n|%s                                                                                                                           |", chaine);
        Go_up(1);                                                                                                                   // Adjust the width according to the width of your cadre
        usleep(30000);
    }
    printf("\n|__________________________________________________________________________________________________________________________|");
    usleep(30000);

    fclose(fichier);
    printf("\n");

}



void menu8(int* choix)
{
    clrscr();
    noire();
    int c ;
    int cpt = 1;
    int y = 2;
    gotoxy(margin, y++); vert(); printf(" =========================================================\n"); noiret();
    y++;
    gotoxy(margin, y++); bleut(); printf("                PRINCIPAL MENU\n"); noiret();
    y++;
    gotoxy(margin, y++); vert(); printf(" =========================================================\n"); noiret();
    y++;
    gotoxy(margin, y++); bleu(); printf("               1. START        \n"); noire();
    y++;
    gotoxy(margin, y++); printf("               2. TP TEXTE           \n");
    y++;
    gotoxy(margin, y++); printf("               3. ABOUT US           \n");
    y++;
    gotoxy(margin, y++); printf("\n");
    gotoxy(margin, y++); printf("               4. QUITTER           \n");
    gotoxy(margin, y++); printf("\n");
    gotoxy(margin, y++); vert(); printf(" =========================================================\n");

    do {
        c=getch();
        if(c==up){cpt%=11;cpt++;}
        if(c==down){cpt--;if(cpt==0)cpt=11;}
        noire();
        y=2;
        clrscr();
        noire();

        // Display menu options
        gotoxy(margin, y++); vert(); printf(" =========================================================\n"); noiret();
        y++;
        gotoxy(margin, y++); bleut(); printf("               PRINCIPAL MENU\n"); noiret(); noire();
        
        y++;
        gotoxy(margin, y++); vert(); printf("  =========================================================\n"); noiret();
        y++;
        if (cpt == 1) bleu();
        gotoxy(margin, y++); printf("               1. START           \n"); noire();
        y++;
        if (cpt == 2) bleu();
        gotoxy(margin, y++); printf("               2. TP TEXTE          \n"); noire();
        y++;
        if (cpt == 3) bleu();
        gotoxy(margin, y++); printf("               3. ABOUT US          \n"); noire();
        y++;
        if (cpt == 4) bleu();
        gotoxy(margin, y++); printf("               4. QUITTER          \n"); noire();
        y++;
        gotoxy(margin, y++); vert(); printf(" =========================================================\n");

    } while (c != 13);

    if (c == 13) {
        *choix = cpt;
    }
}



void about_us(void)
{


    int choix;

    system("cls");
    system("color 07");
    textbackground(BLACK);
    char chaine[256] = "";
    int i = 2;
    textcolor(WHITE);
    printf("  +----------------------------------------------------------------------------------------------------------------+\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  +----------------------------------------------------------------------------------------------------------------+\n");//27

    gotoxy(4,i);
    textcolor(LIGHTRED);
    FILE *fichier = fopen("files/about_us.txt", "r");

        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(! feof(fichier))
        {
            fgets(chaine, 256, fichier);
            printStrAnim(4000,chaine);
            strcpy(chaine, "");
            i++;
            gotoxy(4, i);

            if(i > 8)
              textcolor(LIGHTBLUE);
        }

    fclose(fichier);

    printf("\n\n\n\n\n");


   

}




void PRINT_INFO5(void) {
    system("cls");
    system("color 07");
    textbackground(BLACK);
    char chaine[256] = "";

    FILE *fichier = fopen("files/DO.txt", "r");

    if (fichier == NULL) {
        printf("Probleme d'ouverture de fichier!\n");
        exit(EXIT_FAILURE);
    }

    int numLines = countLines("files/DO.txt");
    int i = 1;
Red();
    printf("\t\t\t\t\t\t\t\tA summary about what this code Do ");
 Reset();
    printf("\n____________________________________________________________________________________________________________________________");
    for (int j = 1; j <= numLines; j++) {
        
        fgets(chaine, 256, fichier);
        
        
       printf("\n|%s                                                                                                                           |", chaine);
        Go_up(1);                                                                                                                   // Adjust the width according to the width of your cadre
        usleep(30000);
    }
    printf("\n|__________________________________________________________________________________________________________________________|");
    usleep(30000);

    fclose(fichier);
    printf("\n");

    
    Red();
    pause();
    Reset();
}