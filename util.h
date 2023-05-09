#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "user.h"

// int loadData(Menu *s)
// {
//     FILE *fp = NULL;
//     fp = fopen("menu.txt", "rt");
//     if (fp == NULL)
//     {
//         printf("No file!\n");
//         return 0;
//     }
//     int i = 0;

//     while (!feof(fp))
//     {
//         fgets(s[i].name, sizeof(s[i].name), fp);
//         s[i].name[strlen(s[i].name) - 1] = '\0';
//         fscanf(fp, "%c\n%d\n", &s[i].size, &s[i].price);
//         i++;
//     }
//     fclose(fp);
//     printf("==> Loading Success!\n");
//     return i;
// }
void selectMode()
{
    int mode;

    printf("\n******맘스카페에 오신 것을 환영합니다!******\n\n");
    printf("----------------------------\n");
    printf("0. 매니저 모드 \n1. 유저모드 \n");
    printf("----------------------------\n");
    printf("\n원하시는 모드를 입력해 주세요 => ");
    scanf("%d", &mode);
    if (mode)
        userMode();
    else
        managerMode();
}