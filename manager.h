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
    printf("Manager ��� �Դϴ�.\n");
    Menu *mp[20];
    int result = 0, menu;
    int index=0;
    int count=0;
    while(1){
        menu = managerSelectMenu();
        if(menu==1){
            if(count>0){
                managerReadMenu(mp, index); 
            }else printf("�����Ͱ� �����ϴ�.");
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
    printf("���α׷��� �����մϴ�");
};

int managerSelectMenu(){
    int menu;
    printf("\n*** Mom's Cafe ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ���� ����\n");
    printf("6. ����Ȯ��\n");
    printf("0. ����\n\n");
    scanf("%d", &menu);
    return menu;
}
void managerSaveData(){}
int managerCreateMenu(Menu *m){
    printf("�޴�����? ");
    getchar();
    fgets(m->name,20,stdin);    
    m->name[strlen(m->name)-1] = '\0';    
    printf("������? ");
    scanf("%d", &m->price);
    return 1;
}
void managerUpdateMenu(){}
void managerDeleteMenu(){}
void managerReadMenu(Menu *m[], int index){
    printf("========================================\n");
    for(int i=0; i<index; i++){
        if(m[i]==NULL) continue;
        printf("%d     %s   %d��\n",i+1,m[i]->name, m[i]->price);
        // printf("");

    }
}
void managerConfirmSale(){}