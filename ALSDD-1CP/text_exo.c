#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


#define STRING_BUFFER_LENGTH 1000
#define TOTAL_STRINGS 15
#define Max 1000
#define MaxL 100
#define MaxC 5
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define YELB "\e[43m"
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"
//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"
typedef char Tabstr[TOTAL_STRINGS][STRING_BUFFER_LENGTH];


typedef int TABD1[Max];
typedef int TabD2[MaxL][MaxC];
typedef struct {
    int pos ;
    int line ;
    char mot[STRING_BUFFER_LENGTH] ;

}exo;
typedef struct{
    char word[STRING_BUFFER_LENGTH] ;
    int repeat;
    TabD2 tab;
}ens;



void Textecolor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, 
        //and add in the forgournd color
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

// manipuler les cordonn�s de la console gotoxy :
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
            Textecolor(5);
        if (k % 2 == 1)
            Textecolor(3);
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
    Sleep(200);
    system("cls");
    }
    Textecolor(5);
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
    Textecolor(3);
    printf("\t\t\t\t\t\t\tCPI - 1%cre Ann%ce - Ann%ce Universitaire 2022/2023 \n\n\n", 138, 130, 130);
    printf("\t\t\t\t\t\t ___________________________________________________________________\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t| REALISE PAR :             Your name                               |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           SECTION : B           GROUPE: 05                        |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|           EXO :        STRING TABLE                               |\n");
    printf("\t\t\t\t\t\t|                                                                   |\n");
    printf("\t\t\t\t\t\t|___________________________________________________________________|\n\n\n");
    Sleep(200);
    Sleep(200);
    Textecolor(5);
    printf("\n");
    printf("\t\t\t\t\t\t                             PLease                                         \n");
    printf("\t\t\t\t\t\t                    Press any key to continue..                             ");
    getch();
}
// charrgement affichage:
void Chargement()
{
    int i;
    for (i = 0; i < 2; i++)
    {
        system("cls");
        Textecolor(4);
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
    }
}

void lecttext(Tabstr text, int *Tai) {
    printf("Enter the number of lines: ");
    scanf(" %d", Tai);
    getchar();

    for (int i = 0; i < *Tai; i++) {
        printf("Enter line %d: ", i + 1);

        fgets(text[i], STRING_BUFFER_LENGTH, stdin);

        int length = strlen(text[i]);
        if (text[i][length - 1] == '\n') {
            text[i][length - 1] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }
}

void preDifinetext(Tabstr text,int *Tai) {
    *Tai =3;
    strcpy(text[0], "   Artificial Intelligence (AI) refers to the development of computer systems that can perform tasks that typically require human intelligence.");
    strcpy(text[1], "  These tasks include learning, reasoning, problem-solving, understanding natural language, speech recognition, and visual perception, among others.");
    strcpy(text[2], "  AI systems can be categorized into two main types: narrow or weak AI and general or strong AI.");
}

bool is_special_character(char c) {
    // ASCII values of special characters
    // You can add more special characters as needed
    if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64) ||
        (c >= 91 && c <= 96) || (c >= 123 && c <= 126)) {
        return true;
    }
    return false;
}


int  rempli_struct(exo P[], Tabstr text, int Tai) {
     int cpt = 0;


    for (int i = 0; i < Tai; i++) {
        int j = 0;
        char ch[STRING_BUFFER_LENGTH];
        int k = 0;
        int l =0;
        while (text[i][k] != '\0') {
            // Ignorer les espaces initiaux
            while (is_special_character(text[i][k])) {
                k++;
            }

            // Copier le mot
            while (!is_special_character(text[i][k] ) && text[i][k] != '\0') {
                ch[j] = text[i][k];
                j++;
                k++;
            }

            // Terminer le mot
            ch[j] = '\0';
            j = 0;

            // Ajouter le mot à la structure
            if (strlen(ch) > 0) {
                P[cpt].pos = l + 1;
                P[cpt].line = i + 1;
                strcpy(P[cpt].mot, ch);
                cpt++;
                l++;
            }

        }

    }
   return cpt ;
}

int repeat_mot(char ch[],exo P[],int Tai){
    int cpt=0;
    for(int i=0;i<Tai;i++){
        if (strcmp(strlwr(ch), strlwr(P[i].mot)) == 0){
             cpt ++;
        }
    }
    return cpt;
}

void cordonne_mot(ens T[],int u,exo P[],int Tai,char ch[]){
    int i=0;

        for(int j=0;j<Tai;j++){
        if (strcmp(strlwr(ch), strlwr(P[j].mot)) == 0){
             T[u].tab[i][0]=P[j].pos;
             T[u].tab[i][1]=P[j].line;
             i++;
        }
    }
}

void tab_mot_repeter(int *taille, ens T[], exo P[], int Tai) {
    *taille = 0;
    for (int i = 0; i < Tai; i++) {
        bool trouv = true;
        for (int j = 0; j < *taille; j++) {
            if (strcmp(strlwr(T[j].word), strlwr(P[i].mot)) == 0) {
                trouv = false;
                break;
            }
        }
        if (trouv) {

            strcpy(T[*taille].word, P[i].mot);
            T[*taille].repeat = repeat_mot(P[i].mot, P, Tai);
            cordonne_mot(T,*taille,P,Tai,P[i].mot);
            (*taille)++;
        }
    }
}

void TriBulle(ens T[], int Tai) {
    ens temp;
    bool b;
    do {
        b = false;
        for (int i = 0; i < Tai - 1; i++) {
            if (T[i].repeat < T[i + 1].repeat) {
                // Swap repeat counts
                int tempRepeat = T[i].repeat;
                T[i].repeat = T[i + 1].repeat;
                T[i + 1].repeat = tempRepeat;

                // Swap words
                char tempWord[STRING_BUFFER_LENGTH];
                strcpy(tempWord, T[i].word);
                strcpy(T[i].word, T[i + 1].word);
                strcpy(T[i + 1].word, tempWord);

                // Swap tab arrays
                for (int j = 0; j < MaxL; j++) {
                    for (int k = 0; k < MaxC; k++) {
                        int tempValue = T[i].tab[j][k];
                        T[i].tab[j][k] = T[i + 1].tab[j][k];
                        T[i + 1].tab[j][k] = tempValue;
                    }
                }

                b = true; // Set flag to indicate that a swap occurred
            }
        }
    } while (b); // Continue while at least one swap occurred in the last iteration
}


void write_freq_mot(ens T[]) {
    printf("|------------------|---------|-------|-------|\n");
    printf("| %-16s | %-7s | %-5s | %-5s |\n", "Mot", "Repeat", "Ligne", "Pos");
    printf("|------------------|---------|-------|-------|\n");

    for (int i = 0; i < 5; i++) {
        printf("| %-16s | %-7d | %-5d | %-5d |\n", T[i].word, T[i].repeat, T[i].tab[0][1], T[i].tab[0][0]);

        for (int j = 1; j < T[i].repeat; j++) {
            printf("|                  |         | %-5d | %-5d |\n", T[i].tab[j][1], T[i].tab[j][0]);
        }
        printf("|------------------|---------|-------|-------|\n");
        //sleep(1);
    }
}





void Entete() {
    printf(BRED "   **********************\n"reset);//BHYEL
    printf(BRED "   * S2Ex01-04: TABLEAU *\n"reset);
    printf(BRED"   **********************\n\n"reset);
    printf(BHYEL"   belatarche isaac 1cp groupe 5\n\n"reset);
    printf(BRED"  L'ennonce du l'%cxercice : \n\n"reset, 130);
    printf("  Ecrire l'%calgorithme qui r%ccupere tous les mots d%cun texte donn%c dans un tableau.\n", 130, 130, 39, 130);
    printf("  Chaque l%cl%cment du tableau est un enregistrement %c trois champs : Le champ 1 contient le mot.\n", 39, 130, 133);
    printf("  Le champ 2 contient le num%cro de la ligne contenant le mot et le champ3 contient la position du mot dans la ligne.\n", 130);
    printf("  Rechercher les mots les plus fr%cquents (les 5 premiers) en indiquant leurs coordonn%ces.\n", 130, 130);
}

void Menu ()
{
    Entete();
    printf("\n");
    printf(YEL"***********   MENU   **********\n\n"reset);
    printf (HRED"1. Cr%cer un votre text \n\n"reset, 130);
    printf (HRED"2. Text predefini \n\n"reset);
    printf (HRED"3. Quitter \n\n"reset);
    printf (HRED"> Votre choix : "reset);
}


void writeTabchar(Tabstr text, int Tai) {
    for (int i = 0; i < Tai; i++) {
        printf("%s\n", text[i]);
    }
}


   void afficher_tableau2(exo P[], int taille) {
    if (taille > 30) {
        int remaining = taille / 2; // Number of elements beyond the first 15

        // Print headers for both tables
        printf(HRED"|------------------|-------|-------|   |------------------|-------|-------|\n"reset);
        printf(HRED"| %-16s | %-5s | %-5s |   | %-16s | %-5s | %-5s  |\n", "Mot", "Ligne", "Pos", "Mot", "Ligne","Pos "reset);
        printf(HRED"+------------------|-------|-------|   +------------------|-------|-------|\n"reset);

        // Print rows in parallel until one table is exhausted
        for (int i = 0; i < remaining || i < taille - remaining; i++) {
            // Print row from the first table
            if (i < remaining) {
                printf("| %-16s | %-5d | %-5d |   ", P[i].mot, P[i].line, P[i].pos);
            } else {
                printf("| %-16s | %-5s | %-5s |   ", "", "", "");
            }

            // Print row from the second table if available
            if (i < taille - remaining) {
                printf("| %-16s | %-5d | %-5d |\n", P[i + remaining].mot, P[i + remaining].line, P[i + remaining].pos);
            } else {
                printf("| %-16s | %-5s | %-5s |\n", "", "", "");
            }
            //sleep(1);
        }
        printf("|__________________|_______|_______|   |__________________|_______|_______|\n");
    }else{
         printf("|------------------|-------|-------|\n");
         printf("| %-16s | %-5s | %-5s |\n", "Mot", "Ligne", "Pos");
         printf("|------------------|-------|-------|\n");

        for (int i = 0; i < taille; i++) {
        printf("| %-16s | %-5d | %-5d |\n", (P+i)->mot, P[i].line, P[i].pos);

       }
       printf("|__________________|_______|_______|");
      // sleep(1);
    }
    printf(HRED"\nLe nombre des mots est : %d \n\n"reset,taille);
}

void ViderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/******************************************************/
/**************   Programme principal  ****************/
/******************************************************/

int main() {


    welcome();
    Chargement();
    char choice1,choice2;
 do {
    system("Cls");


    Tabstr text;
    int Tai;
    int choix;
    int cpt ;
    do {
      system("cls");
     Menu ();
     scanf ("%d", &choix);
    }while(choix > 3);
     switch(choix) {
            case 1 :
                system("cls");
                printf ("1. Cr%cer  votre text \n\n", 130);
                lecttext(text, &Tai);
                printf("\n Le texte qui vous entez est : \n");
                writeTabchar(text, Tai);
                printf ("\n> Appuyer sur ENTREE  pour continuer ... ");
                ViderBuffer();
               // getchar();

                break;
            case 2:
                system("cls");
                printf ("2. Text predefini : \n\n");
                preDifinetext(text,&Tai);
                writeTabchar(text, Tai);
                printf ("\n> Appuyer sur ENTREE  pour continuer ... ");
                ViderBuffer();
               // getchar();
                break;
            case 3:
                goto jump;
                break;
            default :

                  printf("Invalid choice\n");
       }

    exo mots[100]; // Tableau de structures pour stocker les mots
    cpt = rempli_struct(mots, text, Tai);

    printf("\nAffichage des mots avec leurs lignes et positions :\n");

      afficher_tableau2(mots,cpt );

      int taille;
      ens T[100];
      tab_mot_repeter(&taille,T,mots,cpt);
      TriBulle(T,taille);
      write_freq_mot(T);
      jump :
            Textecolor(5);

            printf(BHGRN "\t\t\t\t\t\t\t\tERCI\n\n"reset);
            Textecolor(1);
      printf("\t\t\t\t\this code will be repeated. Enter 'Y' to repeat or any other key to exit: ");
     // printf("\n");
      //printf("\n");
        scanf(" %c", &choice1); // Note the space before %c to consume the newline character

        // Clear the input buffer
        while (getchar() != '\n');

    } while (choice1 == 'Y' || choice1 == 'y') ;


    return 0;
}
