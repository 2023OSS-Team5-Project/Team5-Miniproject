#include  <stdio.h>
#include "manager.h"
#include "user.h"

void loadData(){}
void selectMode(){
    int mode;
    printf("안녕하세요! Mom's Cafe입니다!\n");
    printf("Mode를 선택해주세요.\n\n");
    printf("0. Manager Mode\t1.User Mode : ");
    scanf("%d",&mode);
    if(mode) userMode();
    else managerMode();
}