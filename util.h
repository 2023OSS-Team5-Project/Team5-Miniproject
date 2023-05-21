#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "user.h"

void selectMode()
{
    int mode;

    printf("\n\n******맘스 카페에 오신 것을 환영합니다!******\n\n");
    printf("----------------------------\n");
    printf("0. 매니저 모드 \n1. 유저 모드 \n");
    printf("----------------------------\n");
    printf("\n원하시는 모드를 선택하세요 => ");
    scanf("%d", &mode);
    if (mode)
        userMode();
    else
        managerMode();
}