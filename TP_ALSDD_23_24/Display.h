#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>


//_____________________________________________________________________________________________________________________

/* Start Color Functions */

void Black ()
{
  printf("\033[1;30m");
}
void Red ()
{
    printf("\033[1;31m");
}
void Green ()
{
    printf("\033[1;32m");
}
void Yellow ()
{
    printf("\033[1;33m");
}
void Blue ()
{
    printf("\033[1;34m");
}
void Purple ()
{
    printf("\033[1;35m");
}
void Cyan ()
{
    printf("\033[1;36m");
}
void Reset ()
{
    printf("\033[0m");
}
void Set_Color_Console ()
{
    system("color 0f");
}
void Set_Width_Console ()
{
    system("mode con cols=120");
}
/* End Color Functions */

//_____________________________________________________________________________________________________________________

/* Start Some output functions */

/* This function goes up with the cursor n times */

void Go_up ( int times )
{
    for ( int i = 0 ; i<times ; i++ )
    {
        printf("\033[A");
    }
}

/* This functions goes up with the cursor and clears the line */

void Go_up_Clear_line ( int times )

{
    for ( int i = 0 ; i<times ; i++ )
    {
        printf("\033[A");
        printf("\033[2K");
    }
}

/* Thid function clears the current line */

void Clear_line ()
{
    printf("\033[2K");
}

/* This functions clears the screen */

void Clear_Screen()
{
    system("cls||clear");
}

/* End Some output functions */