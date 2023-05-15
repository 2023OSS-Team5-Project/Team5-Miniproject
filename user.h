#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"

typedef struct
{
    char name[100];
    char size;
    int price;
    int count;

} ShoppingBasket;

int userSelectMenu();
int loadData(Menu *s);
void userReadMenu(Menu *s, int menuCount);
void userChooseMenu(Menu *s, int menuCount, ShoppingBasket *b, int *basketCount);
void userReadShoppingBasket(ShoppingBasket *b, int basketCount);
void userUpdateShoppingBasket(ShoppingBasket *b, int *basketCount);
void Pay();
void usingCoupon();
void purchase();

void userMode()
{
    // printf("\nUser 모드 입니다.\n");
    ShoppingBasket *b;
    b = (ShoppingBasket *)malloc(sizeof(ShoppingBasket) * 100);
    Menu *s;
    s = (Menu *)malloc(sizeof(Menu) * 100);
    int menuCount = loadData(s);
    int basketCount = 0;
    int menu;

    while (1)
    {
        menu = userSelectMenu();
        if (menu == 0)
        {
            printf("\n");
            break;
        }
        if (menu == 1)
        {
            userChooseMenu(s, menuCount, b, &basketCount);
        }
        else if (menu == 2)
        {
            userReadShoppingBasket(b, basketCount);
        }
        else if (menu == 3)
        {
            userUpdateShoppingBasket(b, &basketCount);
        }
        else if (menu == 4)
        {
            Pay();
        }
    }
    printf("방문해 주셔서 감사합니다!\n");
    free(s);
};

int userSelectMenu()
{
    int menu;
    printf("\n**********맘스 카페**********\n");
    printf("             /\\            \n");
    printf("            /  \\           \n");
    printf("----------------------------\n");
    printf("|   1. 메뉴 선택하기       |\n");
    printf("|   2. 장바구니 확인하기   |\n");
    printf("|   3. 장바구니 수정하기   |\n");
    printf("|   4. 결제하기            |\n");
    printf("|   0. 나가기              |\n");
    printf("----------------------------\n");
    printf("\n원하시는 서비스를 입력해 주세요 => ");
    scanf("%d", &menu);
    return menu;
}
void userReadMenu(Menu *s, int menuCount)
{
    printf("\n---------맘스 카페 메뉴---------\n\n");
    for (int i = 0; i < menuCount; i++)
    {
        printf("%d. %s %c %d \n", i + 1, s[i].name, s[i].size, s[i].price);
    }

    printf("\n--------------------------------\n");
    printf("\n");
}
void userChooseMenu(Menu *s, int menuCount, ShoppingBasket *b, int *basketCount)
{

    userReadMenu(s, menuCount);
    int selectedMenu;
    printf("\n원하시는 메뉴를 선택해 주세요 => ");
    scanf("%d", &selectedMenu);
    selectedMenu--;
    printf("\n원하시는 수량을 입력해 주세요 => ");
    scanf("%d", &b[*basketCount].count);
    strcpy(b[*basketCount].name, s[selectedMenu].name);
    b[*basketCount].size = s[selectedMenu].size;
    b[*basketCount].price = s[selectedMenu].price * b[*basketCount].count;
    *basketCount += 1;
}
void userReadShoppingBasket(ShoppingBasket *b, int basketCount)
{
    printf("\n------------장바구니------------\n\n");
    for (int i = 0; i < basketCount; i++)
    {
        printf("%d. %s %c %d %d \n", i + 1, b[i].name, b[i].size, b[i].count, b[i].price);
    }
    printf("\n--------------------------------\n");
    printf("\n");
    int back = 0;
    printf("돌아가시겠습니까? [0. 확인] => ");
    scanf("%d", &back);
}
void userUpdateShoppingBasket(ShoppingBasket *b, int *basketCount)
{
    userReadShoppingBasket(b, *basketCount);
    int selectedMenu;
    int updateMenu;
    printf("\n수정하시려는 메뉴 번호를 입력해 주세요 => ");
    scanf("%d", &selectedMenu);
    selectedMenu--;
    printf("\n무엇을 하시겠습니까? [1.사이즈 변경 / 2. 수량 변경 / 3. 메뉴 삭제] => ");
    scanf("%d", &updateMenu);
    if (updateMenu == 1)
    {
        printf("\n원하시는 사이즈를 입력해 주세요 [S/M/L] => ");
        scanf(" %c", &b[selectedMenu].size);
    }
    else if (updateMenu == 2)
    {
        int prevPrice = b[selectedMenu].price / b[selectedMenu].count;
        printf("\n원하시는 수량을 입력해 주세요 => ");
        scanf("%d", &b[selectedMenu].count);
        b[selectedMenu].price = prevPrice * b[selectedMenu].count;
    }
    else if (updateMenu == 3)
    {
        for (selectedMenu; selectedMenu <= *basketCount - 1; selectedMenu++)
        {
            b[selectedMenu] = b[selectedMenu + 1];
        }
        printf("\n삭제됨!\n");
        *basketCount -= 1;
    }
}
int loadData(Menu *s)
{
    FILE *fp = NULL;
    fp = fopen("menu.txt", "rt");
    if (fp == NULL)
    {
        printf("No file!\n");
        return 0;
    }
    int i = 0;

    while (!feof(fp))
    {
        fgets(s[i].name, sizeof(s[i].name), fp);
        s[i].name[strlen(s[i].name) - 1] = '\0';
        fscanf(fp, "%c\n%d\n", &s[i].size, &s[i].price);
        i++;
    }
    fclose(fp);
    printf("==> Loading Success!\n");
    return i;
}
void Pay() {}
void usingCoupon() {}
void purchase() {}
