#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    char size;
    int price;
} Menu;

int managerSelectMenu();
int managerCreateMenu(Menu *m);
void managerReadMenu(Menu *m[], int index);
int managerUpdateMenu(Menu *m);
void managerDeleteMenu(Menu *m, int *count);
int selectN();

void managerMode()
{
    printf("Manager Mode.\n");
    Menu *mp[20];
    int result = 0, menu;
    int index=0;
    int count=0;
    while(1){
        menu = managerSelectMenu();
        if(menu==1){
            if(count>0){
                managerReadMenu(mp, index); 
            }else printf("There are no data.");
            }
        else if(menu==2){
            mp[index] = (Menu *)malloc(sizeof(Menu));
            managerCreateMenu(mp[index++]);
            count++;
            }
        else if(menu==3){
            int n;
            if(count>0){
                managerReadMenu(mp, index);
                n = selectN();
                managerUpdateMenu(mp[n-1]); 
            }else printf("There are no data.");

        }
        else if(menu==4){
            int n;
            if(count>0){
                managerReadMenu(mp, index);
                n = selectN();
                if(mp[n-1]){
                free(mp[n-1]);
                mp[n-1]=NULL;
        count--;
    }
            }else printf("There are no data.");
        }
        else if(menu==5){}
        else if(menu==6){}
        else if(menu==0){break;}

    }
    printf("Thank you!");
};

int selectN(){
    int n;
    printf("number (cancel :0)? ");
    scanf("%d", &n);
    return n;
}

int managerSelectMenu(){
    int menu;
    printf("\n*** Mom's Cafe ***\n");
    printf("1. Read\n");
    printf("2. Add\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("5. Save\n");
    printf("6. Confirm\n");
    printf("0. Exit\n\n");
    scanf("%d", &menu);
    return menu;
}

void managerSaveData(){}

int managerCreateMenu(Menu *m){
    printf("name? ");
    getchar();
    fgets(m->name,20,stdin);    
    m->name[strlen(m->name)-1] = '\0';    
    printf("size? ");
    scanf("%c", &m->size);
    printf("price? ");
    scanf("%d", &m->price);
    return 1;
}

int managerUpdateMenu(Menu *m){
    printf("new name? ");
    getchar();
    fgets(m->name,20,stdin);    
    m->name[strlen(m->name)-1] = '\0';    
    printf("new size? ");
    scanf("%c", &m->size);
    printf("new price? ");
    scanf("%d", &m->price);
    return 1;
    }

void managerDeleteMenu(Menu *m, int *count){
    if(m){
        free(m);
        m=NULL;
        count--;
    }

}
void managerReadMenu(Menu *m[], int index){
    printf("========================================\n");
    for(int i=0; i<index; i++){
        if(m[i]==NULL) continue;
        printf("%d\t\t%s\t\t%c\t\t%d won\n",i+1,m[i]->name,m[i]->size, m[i]->price);
        // printf("");

    }
}
void managerConfirmSale(){}

