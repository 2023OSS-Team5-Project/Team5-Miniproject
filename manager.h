#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int price;
} Menu;

int managerSelectMenu();
int managerCreateMenu(Menu *m);
void managerReadMenu(Menu *m[], int index);


void managerMode(){
    printf("Manager 모드 입니다.\n");
    Menu *mp[20];
    int result = 0, menu;
    int index=0;
    int count=0;
    while(1){
        menu = managerSelectMenu();
        if(menu==1){
            if(count>0){
                managerReadMenu(mp, index); 
            }else printf("데이터가 없습니다.");
            }
        else if(menu==2){
            mp[index] = (Menu *)malloc(sizeof(Menu));
            managerCreateMenu(mp[index++]);
            count++;
            }
        else if(menu==3){}
        else if(menu==4){}
        else if(menu==5){}
        else if(menu==6){}
        else if(menu==0){break;}

    }
    printf("프로그램을 종료합니다");
};

int managerSelectMenu(){
    int menu;
    printf("\n*** Mom's Cafe ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 매출확인\n");
    printf("0. 종료\n\n");
    scanf("%d", &menu);
    return menu;
}
void managerSaveData(){}
int managerCreateMenu(Menu *m){
    printf("메뉴명은? ");
    getchar();
    fgets(m->name,20,stdin);    
    m->name[strlen(m->name)-1] = '\0';    
    printf("가격은? ");
    scanf("%d", &m->price);
    return 1;
}
void managerUpdateMenu(){}
void managerDeleteMenu(){}
void managerReadMenu(Menu *m[], int index){
    printf("========================================\n");
    for(int i=0; i<index; i++){
        if(m[i]==NULL) continue;
        printf("%d     %s   %d원\n",i+1,m[i]->name, m[i]->price);
        // printf("");

    }
}
void managerConfirmSale(){}