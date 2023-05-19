#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    char size;
    int price;
    int sale;
} Menu;

int managerSelectMenu();
int managerCreateMenu(Menu *m);
void managerReadMenu(Menu *m[], int index);
int managerUpdateMenu(Menu *m);
void managerDeleteMenu(Menu *m, int *count);
int selectN();
void managerSaveData(Menu *m[], int index);
int managerLoadData(Menu *m[]);
void managerConfirmSale();

void managerMode()
{
    printf("Manager Mode.\n");
    Menu *mp[20];
    int result = 0, menu;
    int index = 0;
    int count = 0;
    count = managerLoadData(mp);
    index = count;
    while (1)
    {
        menu = managerSelectMenu();
        if (menu == 1)
        {
            if (count > 0)
            {
                managerReadMenu(mp, index);
            }
            else
                printf("There are no data.");
        }
        else if (menu == 2)
        {
            mp[index] = (Menu *)malloc(sizeof(Menu));
            managerCreateMenu(mp[index++]);
            count++;
        }
        else if (menu == 3)
        {
            int n;
            if (count > 0)
            {
                managerReadMenu(mp, index);
                n = selectN();
                managerUpdateMenu(mp[n - 1]);
            }
            else
                printf("There are no data.");
        }
        else if (menu == 4)
        {
            int n;
            if (count > 0)
            {
                managerReadMenu(mp, index);
                n = selectN();
                if (mp[n - 1])
                {
                    free(mp[n - 1]);
                    mp[n - 1] = NULL;
                    count--;
                }
            }
            else
                printf("There are no data.");
        }
        else if (menu == 5)
        {
            managerSaveData(mp, index);
        }
        else if (menu == 6)
        {
            managerConfirmSale(mp, index);
        }
        else if (menu == 0)
        {
            break;
        }
    }
    printf("Thank you!");
};

int selectN()
{
    int n;
    printf("number (cancel :0)? ");
    scanf("%d", &n);
    return n;
}

int managerSelectMenu()
{
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

void managerSaveData(Menu *m[], int index)
{
    FILE *fp;
    fp = fopen("menu.txt", "wt");
    for (int i = 0; i < index; i++)
    {
        if (m[i] == NULL)
            continue;
        fprintf(fp, "%s\n%c\n%d\n%d\n", m[i]->name, m[i]->size, m[i]->price, m[i]->sale);
    }
    fclose(fp);
    printf("=> Complete!");
}

int managerLoadData(Menu *m[])
{
    FILE *fp;
    fp = fopen("menu.txt", "rt");
    if (fp == NULL)
    {
        printf("No Data!\n");
        return 0;
    }
    int i = 0;
    char str[20];

    while (!feof(fp))
    {
        m[i] = (Menu *)malloc(sizeof(Menu));
        fgets(str, 20, fp);
        str[strlen(str) - 1] = '\0';
        strcpy(m[i]->name, str);
        fscanf(fp, "%c\n%d\n%d\n", &m[i]->size, &m[i]->price, &m[i]->sale);
        i++;
    }
    fclose(fp);
    printf("==> Loading Success!\n");
    return i;
}

int managerCreateMenu(Menu *m)
{
    printf("name? ");
    getchar();
    fgets(m->name, 20, stdin);
    m->name[strlen(m->name) - 1] = '\0';
    printf("size? ");
    scanf("%c", &m->size);
    printf("price? ");
    scanf("%d", &m->price);
    m->sale = 0;
    return 1;
}

int managerUpdateMenu(Menu *m)
{
    printf("new name? ");
    getchar();
    fgets(m->name, 20, stdin);
    m->name[strlen(m->name) - 1] = '\0';
    printf("new size? ");
    scanf("%c", &m->size);
    printf("new price? ");
    scanf("%d", &m->price);
    return 1;
}

void managerDeleteMenu(Menu *m, int *count)
{
    if (m)
    {
        free(m);
        m = NULL;
        count--;
    }
}
void managerReadMenu(Menu *m[], int index)
{
    printf("========================================================\n");
    for (int i = 0; i < index; i++)
    {
        if (m[i] == NULL)
            continue;
        printf("%d\t\t%s\t\t%c\t\t%d won\n", i + 1, m[i]->name, m[i]->size, m[i]->price);
    }
}

void managerConfirmSale(Menu *m[], int index)
{
    int n = 0;
    Menu temp[20];
    for (int i = 0; i < index; i++)
    {
        if (!m[i])
            continue;
        // printf("%s %c\t\t%d ===> %d Won\n",m[i]->name,m[i]->size, m[i]->sale, m[i]->price*m[i]->sale);
        strcpy(temp[n].name, m[i]->name);
        temp[n].price = m[i]->price;
        temp[n].size = m[i]->size;
        temp[n].sale = m[i]->sale;
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        int max = temp[i].price * temp[i].sale;
        int count = i;
        for (int j = i; j < n; j++)
        {
            if (max < temp[j].price * temp[j].sale)
            {
                max = temp[j].price * temp[j].sale;
                count = j;
            }
        }
        Menu tmp = temp[i];
        temp[i] = temp[count];
        temp[count] = tmp;
    }
    printf("=====Sales Ranking=====\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d.\t%s\t\t%c\t\t%d ===> %d Won\n", i + 1, temp[i].name, temp[i].size, temp[i].sale, temp[i].price * temp[i].sale);
    }
}
