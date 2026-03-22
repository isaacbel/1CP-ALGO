#include <stdio.h>
#include <stdlib.h>
#include "menu.c"
#include "conio2.h"


int main() {

    Welcome2();
    Welcome1();

    PRINT_ESI();

    main_page();
    Disclaimer_Page ();

    PRINT_INFO5();

    PRINCIPAL_MENU();

    return 0;
}
