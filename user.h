#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[100];
    char size;
    int price;
    int count;

} ShoppingBasket;

typedef struct
{
    char name[20];
    char size;
    int price;
    int sale;
} MenuUser;

int userSelectMenu();
int loadData(MenuUser *s);
void userReadMenu(MenuUser *s, int menuCount);
void userChooseMenu(MenuUser *s, int menuCount, ShoppingBasket *b, int *basketCount);
void userReadShoppingBasket(ShoppingBasket *b, int basketCount);
void userUpdateShoppingBasket(ShoppingBasket *b, int *basketCount, MenuUser *s, int menuCount);
int Pay(ShoppingBasket *b, int basketCount, MenuUser *s, int menuCount);
int usingCoupon(ShoppingBasket *b, int menuCount, int totalPrice, MenuUser *s);
int purchase(ShoppingBasket *b, int menuCount, int totalPrice, MenuUser *s);

void userMode()
{
    // printf("\nUser 모드 입니다.\n");
    ShoppingBasket *b;
    b = (ShoppingBasket *)malloc(sizeof(ShoppingBasket) * 100);
    MenuUser *s;
    s = (MenuUser *)malloc(sizeof(MenuUser) * 100);
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
            int back = 0;
            printf("돌아가시겠습니까? [0. 확인] => ");
            scanf("%d", &back);
        }
        else if (menu == 3)
        {
            if (basketCount == 0)
            {
                printf("\n장바구니에 담긴 메뉴가 없습니다.\n");
                continue;
            }
            userUpdateShoppingBasket(b, &basketCount, s, menuCount);
        }
        else if (menu == 4)
        {
            int pay = Pay(b, basketCount, s, menuCount);
            if (pay == 0)
            {
                break;
            }
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
void userReadMenu(MenuUser *s, int menuCount)
{
    printf("\n----------맘스 카페 메뉴----------\n\n");
    printf("        Menu       Size  Price\n");
    for (int i = 0; i < menuCount; i++)
    {
        printf("%d. %-17s%-5c%d \n", i + 1, s[i].name, s[i].size, s[i].price);
    }

    printf("\n----------------------------------\n");
    printf("\n");
}
void userChooseMenu(MenuUser *s, int menuCount, ShoppingBasket *b, int *basketCount)
{

    userReadMenu(s, menuCount);
    int selectedMenu;
    int isAlready = 0;
    int alreadyIndex = 0;
    do
    {
        printf("\n원하시는 메뉴를 선택해 주세요 [0. 돌아가기] => ");
        scanf("%d", &selectedMenu);
    } while (selectedMenu < 0 || selectedMenu > menuCount);

    if (selectedMenu == 0)
    {
        return;
    }

    selectedMenu--;
    for (int i = 0; i < *basketCount; i++)
    {
        if (strstr(s[selectedMenu].name, b[i].name) != NULL)
        {
            if (s[selectedMenu].size == b[i].size)
            {
                isAlready++;
                alreadyIndex = i;
            }
        }
    }
    if (isAlready > 0)
    {
        int alreadyCount = 0;
        while (alreadyCount <= 0)
        {
            printf("\n원하시는 수량을 입력해 주세요 => ");
            scanf("%d", &alreadyCount);
        }
        b[alreadyIndex].count += alreadyCount;
        b[alreadyIndex].price = s[selectedMenu].price * b[alreadyIndex].count;
    }
    else
    {
        while (b[*basketCount].count <= 0)
        {
            printf("\n원하시는 수량을 입력해 주세요 => ");
            scanf("%d", &b[*basketCount].count);
        }
        strcpy(b[*basketCount].name, s[selectedMenu].name);
        b[*basketCount].size = s[selectedMenu].size;
        b[*basketCount].price = s[selectedMenu].price * b[*basketCount].count;
        *basketCount += 1;
    }
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
}
void userUpdateShoppingBasket(ShoppingBasket *b, int *basketCount, MenuUser *s, int menuCount)
{
    userReadShoppingBasket(b, *basketCount);
    int selectedMenu;
    int updateMenu;
    while (selectedMenu < 0 || selectedMenu > *basketCount)
    {
        printf("\n수정하시려는 메뉴 번호를 입력해 주세요 [0. 돌아가기] => ");
        scanf("%d", &selectedMenu);
    }
    if (selectedMenu == 0)
    {
        return;
    }
    selectedMenu--;
    while (updateMenu < 0 || updateMenu > 3)
    {
        printf("\n무엇을 하시겠습니까? [1. 사이즈 변경 / 2. 수량 변경 / 3. 메뉴 삭제 / 0. 돌아가기 ] => ");
        scanf("%d", &updateMenu);
    }
    if (updateMenu == 0)
    {
        return;
    }
    else if (updateMenu == 1)
    {
        char selectedSize = ' ';
        int hasChanged = 0;
        do
        {
            printf("\n원하시는 사이즈를 입력해 주세요 [S/M/L] => ");
            scanf(" %c", &selectedSize);
        } while (selectedSize != 'S' && selectedSize != 'M' && selectedSize != 'L');

        for (int i = 0; i < menuCount; i++)
        {
            if (strstr(s[i].name, b[selectedMenu].name) != NULL)
            {
                if (s[i].size == selectedSize)
                {
                    b[selectedMenu].size = selectedSize;
                    b[selectedMenu].price = s[i].price * b[selectedMenu].count;
                    hasChanged++;
                }
            }
        }
        if (hasChanged == 0)
        {
            int yes = 0;
            printf("\n변경하시려는 사이즈가 없는 메뉴입니다 [0. 돌아가기] => ");
            scanf("%d", &yes);
        }
    }
    else if (updateMenu == 2)
    {
        int prevPrice = b[selectedMenu].price / b[selectedMenu].count;
        do
        {
            printf("\n원하시는 수량을 입력해 주세요 => ");
            scanf("%d", &b[selectedMenu].count);
        } while (b[selectedMenu].count <= 0);

        b[selectedMenu].price = prevPrice * b[selectedMenu].count;
    }
    else if (updateMenu == 3)
    {
        for (selectedMenu; selectedMenu <= *basketCount - 1; selectedMenu++)
        {
            b[selectedMenu] = b[selectedMenu + 1];
        }
        printf("\n메뉴가 삭제되었습니다.\n");
        *basketCount -= 1;
    }
}
int loadData(MenuUser *s)
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
        fscanf(fp, "%c\n%d\n%d\n", &s[i].size, &s[i].price, &s[i].sale);
        i++;
    }
    fclose(fp);
    return i;
}
int Pay(ShoppingBasket *b, int basketCount, MenuUser *s, int menuCount)
{
    userReadShoppingBasket(b, basketCount);
    int totalPrice = 0;
    int payHow;
    for (int i = 0; i < basketCount; i++)
    {
        totalPrice += b[i].price;
    }
    printf("결제하실 금액은 총 %d원 입니다.\n", totalPrice);
    do
    {
        printf("결제하시겠습니까? [1. 결제/ 2. 쿠폰 사용/ 0. 돌아가기] => ");
        scanf("%d", &payHow);
    } while (payHow < 0 || payHow > 2);

    if (payHow == 0)
    {
        return 1;
    }
    else if (payHow == 1)
    {
        return purchase(b, menuCount, totalPrice, s);
    }
    else if (payHow == 2)
    {
        return usingCoupon(b, menuCount, totalPrice, s);
    }
}
int usingCoupon(ShoppingBasket *b, int menuCount, int totalPrice, MenuUser *s)
{
    int couponNum;
    int pay;
    int totalPrice2;
    while (1)
    {
        int totalPrice2 = totalPrice;
        printf("\n---------쿠폰함---------\n\n");
        printf("1. 새학기 맞이 10%% 할인쿠폰\n");
        printf("2. 생일 축하 50%% 할인쿠폰\n");
        printf("3. 총장님이 쏘신 30%% 할인쿠폰\n");
        printf("\n--------------------------------\n");
        printf("\n");
        do
        {
            printf("\n사용하실 쿠폰 번호를 입력해 주세요 => ");
            scanf("%d", &couponNum);
        } while (couponNum < 1 || couponNum > 3);

        if (couponNum == 1)
        {
            totalPrice2 *= 0.9;
            totalPrice2 = (totalPrice2 + 9) / 10 * 10;
        }
        else if (couponNum == 2)
        {
            totalPrice2 *= 0.5;
            totalPrice2 = (totalPrice2 + 9) / 10 * 10;
        }
        else if (couponNum == 3)
        {
            totalPrice2 *= 0.7;
            totalPrice2 = (totalPrice2 + 9) / 10 * 10;
        }
        printf("\n할인된 결제하실 금액은 총 %d원 입니다.\n", totalPrice2);
        printf("결제하시겠습니까? [1. 결제/ 2. 쿠폰 다시 선택/ 0. 돌아가기] => ");
        scanf("%d", &pay);
        if (pay == 1)
        {
            totalPrice = totalPrice2;
            purchase(b, menuCount, totalPrice, s);
            return 0;
        }
        if (pay == 0)
        {
            return 1;
        }
    }
}
int purchase(ShoppingBasket *b, int menuCount, int totalPrice, MenuUser *s)
{
    FILE *fp = NULL;
    fp = fopen("menu.txt", "wt");

    for (int i = 0, j = 0; i < menuCount; i++)
    {
        if (i < menuCount - 1)
        {

            if ((strstr(b[j].name, s[i].name) != NULL) && (b[j].size == s[i].size))
            {
                fprintf(fp, "%s\n%c\n%d\n%d\n", s[i].name, s[i].size, s[i].price, b[j].count + s[i].sale);
                j++;
            }
            else
            {
                fprintf(fp, "%s\n%c\n%d\n%d\n", s[i].name, s[i].size, s[i].price, s[i].sale);
            }
        }
        else if (i == menuCount - 1)
        {
            if ((strstr(b[j].name, s[i].name) != NULL) && (b[j].size == s[i].size))
            {
                fprintf(fp, "%s\n%c\n%d\n%d", s[i].name, s[i].size, s[i].price, b[j].count + s[i].sale);
                j++;
            }
            else
            {
                fprintf(fp, "%s\n%c\n%d\n%d", s[i].name, s[i].size, s[i].price, s[i].sale);
            }
        }
    }
    fclose(fp);
    printf("\n결제가 완료되었습니다.\n");
    return 0;
}
