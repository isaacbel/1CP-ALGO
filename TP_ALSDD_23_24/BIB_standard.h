#ifndef __BIB__H__
#define __BIB__H__


    //--------------------------------------------------------------------------------------------------------
    // Déclaration des constantes
    //--------------------------------------------------------------------------------------------------------

    #define TAILLE_CHAINE_MAX 100
    #define NOMBRE_LANGUES 10
    #define MAX_LANGUES NOMBRE_LANGUES
    #define NOMBRE_COMPETENCES 16
    #define MAX_COMPETENCES NOMBRE_COMPETENCES
    #define MAX_DIPLOME 10



    //--------------------------------------------------------------------------------------------------------
    // Déclarations des structures des données
    //--------------------------------------------------------------------------------------------------------

    /* Définition du type booléen */

    typedef enum
    {
        False, // 0
        True   // 1
    } Bool;


    /* Définition du type date */

    typedef struct Date
    {
        int jour;
        int mois;
        int annee;
    } Date;


    /* Définition du type tableau des langues */

    typedef Bool Langues[MAX_LANGUES];


    /* Définition du type tableau des compétences */

    typedef Bool Competences[MAX_COMPETENCES];



    //--------------------------------------------------------------------------------------------------------
    // Déclarations des modules
    //--------------------------------------------------------------------------------------------------------


    int StrToInt(char *string); // fonction pour transformer une chaîne de caractère qui contient un nombre en un entier
    Bool comparerStr(char *string1, char *string2); // comparer deux chaînes de caractères sans tenir compte au majuscule et minuscule

    void scanCompetences(Competences tabCompetences); // fonction pour remplir le tableau des compétences par l'utilisateur
    void scanLangues(Langues tabLangues); //  fonction pour remplir le tableau des langues par l'utilisateur
    void scanDiplomes(char diplomes[MAX_DIPLOME][TAILLE_CHAINE_MAX]); // fonction pour remplir le tableau des diplômes par l'utilisateur
    void scanDate(Date *date); // fonction qui permet à l'utilisateur d'entrer une date
    void dateToString(Date date, char *dateString);
    int datecmp(Date date1, Date date2); // fonction pour comparer deux date

    void afficherLanguesCodes(void); // afficher les langues et leurs codes depuis le fichier
    void afficherCompetencesCodes(void); // afficher les compétences et leurs codes depuis le fichier
    void decoderLangue(int code, char langue[]); // trouver la langue correspondante à un code donné
    void decoderCompetence(const int code, char competence[]); // trouver la compétence correspondante à un code donné
    int get_langue(void); // permettre à l'utilisateur d'entrer le code d'une langue
    int get_competence(void); // permettre à l'utilisateur d'entrer le code d'une compétence

    void pause(void); // Arrêter le programme jusqu'à ce que l'utilisateur appuie sur un bouton
    Bool isPressedEnter(void); // detecter si l'utilisateur a cliqué sur la touche ENTRER
    void consoleCursor(Bool show); // afficher et masquer le curseur dans la console
    void deleteConsoleLines(int number_of_lines_to_delete); // Supprimer des lines dans la console cmd
    void speak(char string[]);

#endif
