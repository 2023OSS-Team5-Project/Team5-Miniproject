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
// int loadData(Menu *s);
void userReadMenu(Menu *s, int menuCount);
void userChooseMenu(Menu *s, int menuCount, ShoppingBasket *b, int *basketCount);
void userReadShoppingBasket(ShoppingBasket *b, int basketCount);
void userUpdateShoppingBasket(ShoppingBasket *b, int *basketCount);
void Pay();
void usingCoupon();
void purchase();

void userMode()
{
    // printf("\nUser ��� �Դϴ�.\n");
    ShoppingBasket *b;
    b = (ShoppingBasket *)malloc(sizeof(ShoppingBasket) * 100);
    Menu *s;
    s = (Menu *)malloc(sizeof(Menu) * 100);
    int menuCount = 0;
    // int menuCount = loadData(s);
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
    printf("�湮�� �ּż� �����մϴ�!\n");
    free(s);
};

int userSelectMenu()
{
    int menu;
    printf("\n**********���� ī��**********\n");
    printf("             /\\            \n");
    printf("            /  \\           \n");
    printf("----------------------------\n");
    printf("|   1. �޴� �����ϱ�       |\n");
    printf("|   2. ��ٱ��� Ȯ���ϱ�   |\n");
    printf("|   3. ��ٱ��� �����ϱ�   |\n");
    printf("|   4. �����ϱ�            |\n");
    printf("|   0. ������              |\n");
    printf("----------------------------\n");
    printf("\n���Ͻô� ���񽺸� �Է��� �ּ��� => ");
    scanf("%d", &menu);
    return menu;
}
void userReadMenu(Menu *s, int menuCount)
{
    printf("\n---------���� ī�� �޴�---------\n\n");
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
    printf("\n���Ͻô� �޴��� ������ �ּ��� => ");
    scanf("%d", &selectedMenu);
    selectedMenu--;
    printf("\n���Ͻô� ������ �Է��� �ּ��� => ");
    scanf("%d", &b[*basketCount].count);
    strcpy(b[*basketCount].name, s[selectedMenu].name);
    b[*basketCount].size = s[selectedMenu].size;
    b[*basketCount].price = s[selectedMenu].price * b[*basketCount].count;
    *basketCount += 1;
}
void userReadShoppingBasket(ShoppingBasket *b, int basketCount)
{
    printf("\n------------��ٱ���------------\n\n");
    for (int i = 0; i < basketCount; i++)
    {
        printf("%d. %s %c %d %d \n", i + 1, b[i].name, b[i].size, b[i].count, b[i].price);
    }
    printf("\n--------------------------------\n");
    printf("\n");
    int back = 0;
    printf("���ư��ðڽ��ϱ�? [0. Ȯ��] => ");
    scanf("%d", &back);
}
void userUpdateShoppingBasket(ShoppingBasket *b, int *basketCount)
{
    userReadShoppingBasket(b, *basketCount);
    int selectedMenu;
    int updateMenu;
    printf("\n�����Ͻ÷��� �޴� ��ȣ�� �Է��� �ּ��� => ");
    scanf("%d", &selectedMenu);
    selectedMenu--;
    printf("\n������ �Ͻðڽ��ϱ�? [1.������ ���� / 2. ���� ���� / 3. �޴� ����] => ");
    scanf("%d", &updateMenu);
    if (updateMenu == 1)
    {
        printf("\n���Ͻô� ����� �Է��� �ּ��� [S/M/L] => ");
        scanf(" %c", &b[selectedMenu].size);
    }
    else if (updateMenu == 2)
    {
        int prevPrice = b[selectedMenu].price / b[selectedMenu].count;
        printf("\n���Ͻô� ������ �Է��� �ּ��� => ");
        scanf("%d", &b[selectedMenu].count);
        b[selectedMenu].price = prevPrice * b[selectedMenu].count;
    }
    else if (updateMenu == 3)
    {
        for (selectedMenu; selectedMenu <= *basketCount - 1; selectedMenu++)
        {
            b[selectedMenu] = b[selectedMenu + 1];
        }
        printf("\n������!\n");
        *basketCount -= 1;
    }
}
void Pay() {}
void usingCoupon() {}
void purchase() {}
