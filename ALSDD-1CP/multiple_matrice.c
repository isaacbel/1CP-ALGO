#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 1000
#define MaxL 100
#define MaxC 100

typedef int Tind;
typedef int TindL;
typedef int TindC;

typedef int TABD1[Max];
typedef int TabD2[MaxL][MaxC];

void lecttabD2(TabD2 array, TindL *nbl, TindC *nbc) {
    printf("Enter the number of rows: ");
    scanf("%d", nbl);
    printf("Enter the number of columns: ");
    scanf("%d", nbc);
    for (int i = 0; i < *nbl; i++) {
        for (int j = 0; j < *nbc; j++) {
            printf("Enter array[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
}
void LecRandD2(TabD2 T, TindL *NbL, TindC *NbC) {
    int minI, maxI, i, j;

    printf("Donner le Nb de lignes du tableau : ");
    scanf("%d", NbL);
    printf("Donner le Nb de colonnes du tableau : ");
    scanf("%d", NbC);

    printf("Intervalle [minI, maxI] des valeurs %c prendre al%catoirement\n",133,130);
    printf("---------------------------------------------------------\n");
    printf("Donner la borne inf%crieure : ",130);
    scanf("%d", &minI);
    printf("Donner la borne sup%crieure : ",130);
    scanf("%d", &maxI);

    // Seed the random number generator
    srand(time(NULL));

    for (i = 0; i < *NbL; i++) {
        for (j = 0; j < *NbC; j++) {
            T[i][j] = minI + rand() % (maxI - minI + 1);
        }
    }
}
void writetabD2(TabD2 array, TindL nbl, TindC nbc) {
    for (int i = 0; i < nbl; i++) {
        for (int j = 0; j < nbc; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

void produitMatrice(TabD2 T1, TabD2 T2, TabD2 T3, TindC nbc1, TindC nbc2, TindL nbl1) {
    for (int i = 0; i < nbl1; i++) {
        for (int k = 0; k < nbc2; k++) {
            int S = 0;
            for (int j = 0; j < nbc1; j++) {
                S += T1[i][j] * T2[j][k];
            }
            T3[i][k] = S;
        }
    }
}

int main() {
    TabD2 T1, T2, T3;
    TindL Nbl1, Nbl2;
    TindC Nbc1, Nbc2;
    LecRandD2(T1, &Nbl1, &Nbc1);
    LecRandD2(T2, &Nbl2, &Nbc2);
    
   // lecttabD2(T1, &Nbl1, &Nbc1);
   // lecttabD2(T2, &Nbl2, &Nbc2);
    printf("\nMatrix T1:\n");
    writetabD2(T1, Nbl1, Nbc1);
    printf("\nMatrix T2:\n");
    writetabD2(T2, Nbl2, Nbc2);
    if (Nbc1 == Nbl2){
      produitMatrice(T1, T2, T3, Nbc1, Nbc2, Nbl1);
     printf("\nResultant Matrix T3:\n");
     writetabD2(T3, Nbl1, Nbc2);
    }
    else{
        printf("Error");
    }
    return 0;
}
