#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(){
    char **strings ;

    int total =0;
    printf("Enter the number of string : ");
    scanf("%d",&total);

    strings = malloc(total*sizeof(char *));

    char Buffer[BUFFER_SIZE];
    int lenght =0;

    while (getchar() != '\n');
    printf("\n");

    for(int i=0;i<total;i++){
        printf("Enter the string %d ",i+1);
        fgets(Buffer,BUFFER_SIZE,stdin);
        lenght = strlen(Buffer);
        Buffer[lenght-1]='\0';
        strings[i]=malloc(lenght*sizeof(char));
        strcpy(strings[i],Buffer);
    }
    printf("\nResulting string array \n\n");
    for (int i=0;i<total;i++){
        printf("string[%d]= %s\n",i+1,strings[i]);
    }



}