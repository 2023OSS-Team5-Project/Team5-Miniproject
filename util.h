#include  <stdio.h>
#include "manager.h"
#include "user.h"

void loadData(){}
void selectMode(){
    int mode;
    printf("�ȳ��ϼ���! Mom's Cafe�Դϴ�!\n");
    printf("Mode�� �������ּ���.\n\n");
    printf("0. Manager Mode\t1.User Mode : ");
    scanf("%d",&mode);
    if(mode) userMode();
    else managerMode();
}