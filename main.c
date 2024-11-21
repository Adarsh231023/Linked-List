#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#define pragma pack 1
void gotoxy(int a, int b)
{
        COORD c;
        c.X = a;
        c.Y = b;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
struct node
{
        char data[10];
        struct node *next;
        struct node *prev;
};
struct node *head1 = NULL; // Singly head
struct node *head2 = NULL; // Doubly head
struct node *head3 = NULL; // Singly Circular head
struct node *head4 = NULL; // Doubly Circular head
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;

void clear() { system("cls"); }

void check_exit() // make everything NULL before exit
{
        clear();
        system("COLOR 08");
        while (head1 != NULL)
        {
                struct node *temp = head1;
                head1 = head1->next;
                free(temp);
        }
        while (head2 != NULL)
        {
                struct node *temp = head2;
                head2 = head2->next;
                free(temp);
        }
        while (head3 != NULL)
        {
                struct node *temp = head3;
                head3 = head3->next;
                free(temp);
        }
        while (head4 != NULL)
        {
                struct node *temp = head4;
                head4 = head4->next;
                free(temp);
        }
        printf("\nExit confirmed....");
        exit(0);
}

void color(int i)
{
        if (i == 0)
                system("COLOR E4");
        else if (i == 1)
                system("COLOR B9");
        else if (i == 2)
                system("COLOR 08");
        else if (i == 3)
                system("COLOR 56");
        else if (i == 4)
                system("COLOR 4B");
        else if (i == 5)
                system("COLOR E0");
        else if (i == 6)
                system("COLOR 74");
        else if (i == 7)
                system("COLOR c4");
        else if (i == 8)
                system("COLOR A0");
        else if (i == 9)
                system("COLOR D2");
}

void y_center() { printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); }
void x_center() { printf("\t\t\t\t\t\t\t\t"); }
void decorate_line() { printf("\t\t\t\t\t\t\t\t_________________________________________________________\n"); }
void decorate_star() { printf("\t\t\t\t\t\t\t\t*********************************************************\n"); }
void decorate_dash() { printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n"); }

void set_Full_Screen()
{
        HWND consoleWindow = GetConsoleWindow(); // Get the console window handle
        ShowWindow(consoleWindow, SW_MAXIMIZE);  // Maximize the console window
}

int validate_data(char *num)
{
        if (strlen(num) > 10)
                return 0;
        int i = 0;
        if (num[i] == '-')
                i++;
        for (; num[i] != '\0'; i++)
        {
                if (isdigit(num[i]) == 0)
                        return 0;
        }
        return 1;
}

void in_at_beg(char x) // Insertion at a beginning
{
        color(5);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (x == '1') // Singly Linked List Insertion at beginning
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count1++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head1 == NULL)
                {
                        head1 = newnode;
                        newnode->next = NULL;
                        newnode->prev = NULL;
                }
                else
                {
                        newnode->next = head1;
                        head1 = newnode;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else if (x == '2') // Doubly Linked List Insertion at beginning
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count2++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head2 == NULL)
                {
                        head2 = newnode;
                        newnode->next = NULL;
                        newnode->prev = NULL;
                }
                else
                {
                        newnode->next = head2;
                        head2->prev = newnode;
                        head2 = newnode;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else if (x == '3') // singly Circular Linked List Insertion at beginning
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count3++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head3 == NULL)
                {
                        head3 = newnode;
                        newnode->next = head3;
                        newnode->prev = NULL;
                }
                else
                {
                        struct node *temp = head3;
                        newnode->next = head3;
                        while (temp->next != head3)
                                temp = temp->next; // important
                        temp->next = newnode;
                        head3 = newnode;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else if (x == '4') // Doubly Circular Linked List Insertion at beginning
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count4++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head4 == NULL)
                {
                        head4 = newnode;
                        newnode->next = head4;
                        newnode->prev = head4;
                }
                else
                {
                        newnode->next = head4;
                        newnode->prev = head4->prev; // important
                        head4->prev->next = newnode; // important
                        head4->prev = newnode;
                        head4 = newnode;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else
        {
                gotoxy(5, 20);
                printf("\t\t\t\t\t\t\t\t|\tError in Insert at beginning/Press Enter to Try again : \t|\n");
                gotoxy(115, 20);
                getchar();
                fflush(stdin);
        }
}

void in_at_end(char x) // Insertion at a Ending
{
        color(5);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (x == '1') // Singly Linked List Insertion at Ending
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count1++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head1 == NULL)
                {
                        head1 = newnode;
                        newnode->next = NULL;
                        newnode->prev = NULL;
                }
                else
                {
                        struct node *temp = head1;
                        while (temp->next != NULL)
                                temp = temp->next;
                        temp->next = newnode;
                        newnode->next = NULL;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else if (x == '2') // Doubly Linked List Insertion at Ending
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count2++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head2 == NULL)
                {
                        head2 = newnode;
                        newnode->next = NULL;
                        newnode->prev = NULL;
                }
                else
                {
                        struct node *temp = head2;
                        while (temp->next != NULL)
                                temp = temp->next;
                        temp->next = newnode;
                        newnode->next = NULL;
                        newnode->prev = temp;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else if (x == '3') // singly Circular Linked List Insertion at Ending
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count3++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head3 == NULL)
                {
                        head3 = newnode;
                        newnode->next = head3;
                        newnode->prev = NULL;
                }
                else
                {
                        struct node *temp = head3;
                        while (temp->next != head3)
                                temp = temp->next;
                        temp->next = newnode;
                        newnode->next = head3;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else if (x == '4') // Doubly Circular Linked List Insertion at Ending
        {
                int i = 0;
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                count4++;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(100, 17);
                scanf("%[^\n]s", newnode->data);
                getchar();
                fflush(stdin);
                int check = validate_data(newnode->data);
                while (check == 0)
                {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(105, 18);
                        scanf("%10[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        check = validate_data(newnode->data);
                        i = 1;
                }
                if (head4 == NULL)
                {
                        head4 = newnode;
                        newnode->next = head4;
                        newnode->prev = head4;
                }
                else
                {
                        struct node *temp = head4;
                        while (temp->next != head4)
                                temp = temp->next;
                        newnode->next = head4;
                        head4->prev = newnode;
                        temp->next = newnode;
                        newnode->prev = temp;
                }
                printf("\n");
                printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(105, 20 + i);
                getchar();
                fflush(stdin);
        }
        else
        {
                gotoxy(5, 20);
                printf("\t\t\t\t\t\t\t\t|\tError in Insert at Ending/Press Enter to Try again : \t|\n");
                gotoxy(115, 20);
                getchar();
                fflush(stdin);
        }
}

void in_at_pos(char x) // Insertion at any position
{
        color(5);
        clear();
        y_center();
        if (x == '1') // Singly Linked List Insertion at any position
        {
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your position : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                if (pos == 1)
                {
                        in_at_beg(x);
                        return;
                }
                else if (pos == count1 + 1)
                {
                        in_at_end(x);
                        return;
                }
                else if (pos > count1)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Position  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                struct node *temp = head1;
                int n = pos - 1;
                while (temp->next != NULL && n != 0)
                {
                        temp = temp->next;
                        n--;
                }
                if (temp->next != NULL && n == 0)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '2') // Doubly Linked List Insertion at beginning
        {
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your position : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                if (pos == 1)
                {
                        in_at_beg(x);
                        return;
                }
                else if (pos == count2 + 1)
                {
                        in_at_end(x);
                        return;
                }
                else if (pos > count2)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Position  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                struct node *temp = head2;
                int n = pos - 1;
                while (temp->next != NULL && n != 0)
                {
                        temp = temp->next;
                        n--;
                }
                if (temp->next != NULL && n == 0)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count2++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        temp->next->prev = newnode;
                        newnode->prev = temp;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '3') // singly Circular Linked List Insertion at beginning
        {
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your position : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                if (pos == 1)
                {
                        in_at_beg(x);
                        return;
                }
                else if (pos == count3 + 1)
                {
                        in_at_end(x);
                        return;
                }
                else if (pos > count3)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Position  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                struct node *temp = head3;
                int n = pos - 1;
                while (temp->next != NULL && n != 0)
                {
                        temp = temp->next;
                        n--;
                }
                if (temp->next != NULL && n == 0)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count3++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '4') // Doubly Circular Linked List Insertion at beginning
        {
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your position : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                if (pos == 1)
                {
                        in_at_beg(x);
                        return;
                }
                else if (pos == count4 + 1)
                {
                        in_at_end(x);
                        return;
                }
                else if (pos > count4)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Position  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                struct node *temp = head4;
                int n = pos - 1;
                while (temp->next != NULL && n != 0)
                {
                        temp = temp->next;
                        n--;
                }
                if (temp->next != NULL && n == 0)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        temp->next->prev = newnode;
                        newnode->prev = temp;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else
        {
                gotoxy(5, 20);
                printf("\t\t\t\t\t\t\t\t|\tError in Insert at any position/Press Enter to Try again : \t|\n");
                gotoxy(115, 20);
                getchar();
                fflush(stdin);
        }
}

void in_after_node(char x) // Insertion after any node
{
        color(5);
        clear();
        y_center();
        if (x == '1') // Singly Linked List Insertion after any node
        {
                int pos;
                if (head1 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head1;
                int check = atoi(temp->data);
                while (temp->next != NULL && check != pos)
                {
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp->next == NULL && check == pos)
                {
                        in_at_end(x);
                        return;
                }
                if (temp->next == NULL && check != pos)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '2') // Doubly Linked List Insertion after any node
        {
                int pos;
                if (head2 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head2;
                int check = atoi(temp->data);
                while (temp->next != NULL && check != pos)
                {
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp->next == NULL && check == pos)
                {
                        in_at_end(x);
                        return;
                }
                else
                        temp = temp->next;
                if (temp == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        newnode->prev = temp;
                        temp->next->prev = newnode;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '3') // Singly Circular Linked List Insertion after any node
        {
                if (head3 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head3;
                int check = atoi(temp->data);
                while (temp->next != head3 && check != pos)
                {
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp->next == head3 && check == pos)
                {
                        in_at_end(x);
                        return;
                }
                if (temp->next == head3 && check != pos)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '4') // Doubly Circular Linked List Insertion after any node
        {
                if (head4 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head4;
                int check = atoi(temp->data);
                while (temp->next != head4 && check != pos)
                {
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp->next == head4 && check == pos)
                {
                        in_at_end(x);
                        return;
                }
                if (temp->next == head4 && check != pos)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp->next;
                        newnode->prev = temp;
                        temp->next->prev = newnode;
                        temp->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else
        {
                gotoxy(5, 20);
                printf("\t\t\t\t\t\t\t\t|\tError in Insert after Node/Press Enter to Try again : \t|\n");
                gotoxy(115, 20);
                getchar();
                fflush(stdin);
        }
}

void in_before_node(char x) // Insertion before any node
{
        color(5);
        clear();
        y_center();
        if (x == '1') // Singly Linked List Insertion before any node
        {
                int pos;
                if (head1 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head1;
                struct node *temp2 = NULL;
                int check = atoi(temp->data);
                while (temp->next != NULL && check != pos)
                {
                        temp2 = temp;
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp == head1 && temp2 == NULL && check == pos)
                {
                        in_at_beg(x);
                        return;
                }
                if (temp->next == NULL && check != pos)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp;
                        temp2->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '2') // Doubly Linked List Insertion before any node
        {
                int pos;
                if (head2 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head2;
                struct node *temp2 = NULL;
                int check = atoi(temp->data);
                while (temp->next != NULL && check != pos)
                {
                        temp2 = temp;
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp == head2 && temp2 == NULL && check == pos)
                {
                        in_at_beg(x);
                        return;
                }
                temp = temp->next;
                if (temp->next == NULL && check != pos)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp;
                        newnode->prev = temp2;
                        temp->prev = newnode;
                        temp2->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '3') // Singly Circular Linked List Insertion before any node
        {
                if (head3 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head3;
                struct node *temp2 = NULL;
                int check = atoi(temp->data);
                while (temp->next != head3 && check != pos)
                {
                        temp2 = temp;
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp == head3 && temp2 == NULL && check == pos)
                {
                        in_at_beg(x);
                        return;
                }
                if (temp->next == head3 && check != pos)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp;
                        temp2->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else if (x == '4') // Doubly Circular Linked List Insertion before any node
        {
                if (head4 == NULL)
                {
                        in_at_beg(x);
                        return;
                }
                int pos;
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your node : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                gotoxy(102, 17);
                scanf("%d", &pos);
                getchar();
                fflush(stdin);
                clear();
                y_center();
                struct node *temp = head4;
                struct node *temp2 = NULL;
                int check = atoi(temp->data);
                while (temp->next != head4 && check != pos)
                {
                        temp2 = temp;
                        temp = temp->next;
                        check = atoi(temp->data);
                }
                if (temp == head4 && temp2 == NULL && check == pos)
                {
                        in_at_beg(x);
                        return;
                }
                if (temp->next == head4 && check != pos)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t!! Invalid Node  !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                int i = 0;
                if (check == pos)
                {
                        struct node *newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
                        {
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t!! Memory is FULL !! \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tpress Enter to continue :  \t\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                                gotoxy(105, 18);
                                getchar();
                                return;
                        }
                        count1++;
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t|\t\tEnter your data : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 17);
                        scanf("%[^\n]s", newnode->data);
                        getchar();
                        fflush(stdin);
                        int check = validate_data(newnode->data);
                        while (check == 0)
                        {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                printf("\t\t\t\t\t\t\t\t|\t\t---!! Invalid data !!---\t\t|\n");
                                printf("\t\t\t\t\t\t\t\t|\t\tEnter your data again : \t\t|\n");
                                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                                gotoxy(105, 18);
                                scanf("%10[^\n]s", newnode->data);
                                getchar();
                                fflush(stdin);
                                check = validate_data(newnode->data);
                                i = 1;
                        }
                        newnode->next = temp;
                        newnode->prev = temp2;
                        temp->prev = newnode;
                        temp2->next = newnode;
                        printf("\n");
                        printf("\t\t\t\t\t\t\t\t|\t!! Data successfully added !! \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\t Press Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(105, 20 + i);
                        getchar();
                        fflush(stdin);
                }
        }
        else
        {
                gotoxy(5, 20);
                printf("\t\t\t\t\t\t\t\t|\tError in Insert before Node/Press Enter to Try again : \t|\n");
                gotoxy(115, 20);
                getchar();
                fflush(stdin);
        }
}

void del_at_beg(char x) // Deletion at Beginning
{
        color(6);
        clear();
        y_center();
        if (x == '1') // Singly Linked List Deletion at Beginning
        {
                if (head1 == NULL)
                {
                        decorate_line();
                        decorate_star();
                        x_center();printf("|\t\t!! List is empty !! \t\t\t|\n");
                        x_center();printf("|\t\tpress Enter to continue :\t\t|\n");
                        decorate_star();
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                else
                {
                        struct node* temp=head1;
                        head1=head1->next;
                        temp->next=NULL;
                        decorate_line();
                        decorate_star();
                        x_center();printf("|\t\t!! Node of %s is deleted !! \t\t|\n",temp->data);
                        x_center();printf("|\t\tpress Enter to continue :\t\t|\n");
                        decorate_star();
                        free(temp);
                        gotoxy(105, 18);
                        getchar();
                }
        }
        if (x == '2') // Doubly Linked List Deletion at Beginning
        {
                if (head2 == NULL)
                {
                        decorate_line();
                        decorate_star();
                        x_center();printf("|\t\t!! List is empty !! \t\t\t|\n");
                        x_center();printf("|\t\tpress Enter to continue :\t\t|\n");
                        decorate_star();
                        gotoxy(105, 18);
                        getchar();
                        return;
                }
                else
                {
                        struct node* temp=head2;
                        head2=head2->next;
                        head2->prev=NULL;
                        temp->next=NULL;
                        decorate_line();
                        decorate_star();
                        x_center();printf("|\t\t!! Node of %s is deleted !! \t\t|\n",temp->data);
                        x_center();printf("|\t\tpress Enter to continue :\t\t|\n");
                        decorate_star();
                        free(temp);
                        gotoxy(105, 18);
                        getchar();
                }
        }
}

void del(char x)
{
        char ch;
        do
        {
                system("cls");
                system("COLOR 4B");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t    DELETION - MENU\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t1. Delete at beg\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t2. Delete at end\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t3. Delete at position\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t4. Delete after any node\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t5. Delete before any node\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t9. Previous Menu\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t0. Exit\t\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your choice : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(100, 27);
                scanf("%[^\n]c", &ch);
                getchar();
                fflush(stdin);
                char *p;
                p = &ch;
                int len = strlen(p);
                if (len > 1)
                        ch = '\n';
                switch (ch)
                {
                case '1':
                        del_at_beg(x);
                        return;
                case '2':
                        // del_at_end(x);
                        return;
                case '3':
                        // del_at_pos(x);
                        return;
                case '4':
                        // del_after_node(x);
                        return;
                case '5':
                        // del_before_node(x);
                        return;
                case '9':
                        return;
                case '0':
                        check_exit();
                        break;
                default:
                        gotoxy(5, 27);
                        printf("\t\t\t\t\t\t\t\t|\tInvalid Choice/Press Enter to Try again : \t|\n");
                        gotoxy(115, 27);
                        getchar();
                        fflush(stdin);
                }
                ch = ' ';
        } while (1);
}

void insert(char x)
{
        char ch;
        do
        {
                system("cls");
                system("COLOR A0");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t    INSERTION - MENU\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t1. Insert at beg\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t2. Insert at end\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t3. Insert at position\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t4. Insert after any node\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t5. Insert before any node\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t9. Previous Menu\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t0. Exit\t\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your choice : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(100, 27);
                scanf("%[^\n]c", &ch);
                getchar();
                fflush(stdin);
                char *p;
                p = &ch;
                int len = strlen(p);
                if (len > 1)
                        ch = '\n';
                switch (ch)
                {
                case '1':
                        in_at_beg(x);
                        return;
                case '2':
                        in_at_end(x);
                        return;
                case '3':
                        in_at_pos(x);
                        return;
                case '4':
                        in_after_node(x);
                        return;
                case '5':
                        in_before_node(x);
                        return;
                case '9':
                        return;
                case '0':
                        check_exit();
                        break;
                default:
                        gotoxy(5, 27);
                        printf("\t\t\t\t\t\t\t\t|\tInvalid Choice/Press Enter to Try again : \t|\n");
                        gotoxy(115, 27);
                        getchar();
                        fflush(stdin);
                }
                ch = ' ';
        } while (1);
}

void display(char x)
{
        system("COLOR 56");
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (x == '1' || x == '3')
        {
                struct node *temp = NULL;
                if (x == '1')
                        temp = head1;
                else if (x == '3')
                        temp = head3;
                if (temp == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        if (x == '1')
                                printf("\t\t\t\t\t\t\t\t|\t\tSingly Linked List is Empty\t\t|\n");
                        else if (x == '3')
                                printf("\t\t\t\t\t\t\t\t|\tSingly Circular Linked List is empty\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\tInvalid Choice/Press Enter to Try again : \t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(115, 18);
                        getchar();
                        fflush(stdin);
                }
                else
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        if (x == '1')
                                printf("\t\t\t\t\t\t\t\t|\t\tYour Singly Linked List is \t\t|\n");
                        else if (x == '3')
                                printf("\t\t\t\t\t\t\t\t|\tYour Singly Circular Linked List is\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\n");
                        gotoxy(70, 19);
                        while (temp->next != NULL && temp->next != head3)
                        {
                                printf("%s ", temp->data);
                                printf("-> ");
                                temp = temp->next;
                        }
                        if (temp->next == NULL || temp->next == head3)
                                printf("%s \n", temp->data);
                        printf("\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t|\tPress Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 22);
                        getchar();
                        fflush(stdin);
                        return;
                }
        }
        else if (x == '2' || x == '4')
        {
                struct node *temp = NULL;
                if (x == '2')
                        temp = head2;
                else if (x == '4')
                        temp = head4;
                if (temp == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        if (x == '2')
                                printf("\t\t\t\t\t\t\t\t|\t\tDoubly Linked List is empty\t\t|\n");
                        else if (x == '4')
                                printf("\t\t\t\t\t\t\t\t|\tDoubly Circular Linked List is empty\t|\n");
                        printf("\t\t\t\t\t\t\t\t|\tInvalid Choice/Press Enter to Try again : \t|\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        gotoxy(115, 18);
                        getchar();
                        fflush(stdin);
                }
                else
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        if (x == '2')
                                printf("\t\t\t\t\t\t\t\t|\t\tYour Doubly Linked List is \t\t|\n");
                        else if (x == '4')
                                printf("\t\t\t\t\t\t\t\t|\tYour Doubly Circular Linked List is\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\n");
                        gotoxy(70, 19);
                        while (temp->next != NULL && temp->next != head4)
                        {
                                printf("%s ", temp->data);
                                printf("-> ");
                                temp = temp->next;
                        }
                        if (temp->next == NULL || temp->next == head4)
                                printf("%s \n", temp->data);
                        printf("\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t|\tPress Enter to continue : \t\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        gotoxy(100, 22);
                        getchar();
                        fflush(stdin);
                        return;
                }
        }
        else
        {
                gotoxy(5, 20);
                printf("\t\t\t\t\t\t\t\t|\tError in Display/Press Enter to Try again : \t|\n");
                gotoxy(115, 20);
                getchar();
                fflush(stdin);
        }
}

void sub_main(char x)
{
        char ch;
        do
        {
                system("COLOR B9");
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                if (x == '1')
                        printf("\t\t\t\t\t\t\t\t|\t\t    Singly Linked List\t\t\t|\n");
                else if (x == '2')
                        printf("\t\t\t\t\t\t\t\t|\t\t    Doubly Linked List\t\t\t|\n");
                else if (x == '3')
                        printf("\t\t\t\t\t\t\t\t|\t\tSingly Circular Linked List\t\t|\n");
                else if (x == '4')
                        printf("\t\t\t\t\t\t\t\t|\t\tDoubly Circular Linked List\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t1. Insertion\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t2. Deletion\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t3. Display\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t9. Previous Menu\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t0. Exit\t\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your choice : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(100, 25);
                scanf("%[^\n]s", &ch);
                getchar();
                fflush(stdin);
                char *p;
                p = &ch;
                int len = strlen(p);
                if (len > 1)
                        ch = '\n';
                switch (ch)
                {
                case '1':
                        insert(x);
                        break;
                case '2':
                        del(x);
                        break;
                case '3':
                        display(x);
                        break;
                case '9':
                        return;
                case '0':
                        check_exit();
                        break;
                default:
                        gotoxy(5, 25);
                        printf("\t\t\t\t\t\t\t\t|\tInvalid Choice/Press Enter to Try again : \t|\n");
                        gotoxy(115, 25);
                        getchar();
                        fflush(stdin);
                }
                ch = ' ';
        } while (ch != '9');
}
int main()
{
        set_Full_Screen();
        char ch;
        do
        {
                system("COLOR E4");
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t\tMAIN - MENU\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t1. Singly Linked List\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t2. Doubly Linked List\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t3. Singly Circular Linked List\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t4. Doubly Circular Linked List\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t0. Exit\t\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your choice : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(100, 25);
                scanf("%[^\n]c", &ch);
                getchar();
                fflush(stdin);
                char *p;
                p = &ch;
                int len = strlen(p);
                if (len > 1)
                        ch = '\n';
                switch (ch)
                {
                case '1':
                        sub_main(ch);
                        break;
                case '2':
                        sub_main(ch);
                        break;
                case '3':
                        sub_main(ch);
                        break;
                case '4':
                        sub_main(ch);
                        break;
                case '0':
                        check_exit();
                        break;
                default:
                        gotoxy(5, 25);
                        printf("\t\t\t\t\t\t\t\t|\tInvalid Choice/Press Enter to Try again :       |\n");
                        gotoxy(115, 25);
                        getchar();
                        fflush(stdin);
                }
                ch = ' ';
        } while (1);
}
