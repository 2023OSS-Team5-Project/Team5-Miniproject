#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "user.h"

void selectMode()
{
    int mode;

    printf("\n\n******���� ī�信 ���� ���� ȯ���մϴ�!******\n\n");
    printf("----------------------------\n");
    printf("0. �Ŵ��� ��� \n1. ���� ��� \n");
    printf("----------------------------\n");
    printf("\n���Ͻô� ��带 �����ϼ��� => ");
    scanf("%d", &mode);
    if (mode)
        userMode();
    else
        managerMode();
}