#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "user.h"

void selectMode()
{
    int mode;

    printf("\n\n******¸¾½ºÄ«Æä¿¡ ¿À½Å °ÍÀ» È¯¿µÇÕ´Ï´Ù!******\n\n");
    printf("----------------------------\n");
    printf("0. ????? ??? \n1. ??????? \n");
    printf("----------------------------\n");
    printf("\n?????? ??? ????? ????? => ");
    scanf("%d", &mode);
    if (mode)
        userMode();
    else
        managerMode();
}