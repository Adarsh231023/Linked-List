#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
int gotoxy(int a, int b)
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

void clear(){system("cls");}

void color(int i)
{
        if(i==0)system("COLOR E4");
        else if(i==1)system("COLOR B9");
        else if(i==2)system("COLOR 08");
        else if(i==3)system("COLOR 56");
        else if(i==4)system("COLOR 4B");
        else if(i==5)system("COLOR E0");
        else if(i==6)system("COLOR 74");
        else if(i==7)system("COLOR c4");
        else if(i==8)system("COLOR A0");
        else if(i==9)system("COLOR D2");

}

void y_center(){printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");}
void x_center(){printf("\t\t\t\t\t\t\t\t");}
void decorate_line(){printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");}
void decorate_star(){printf("\t\t\t\t\t\t\t\t*********************************************************\n");}

void set_Full_Screen(){
        HWND consoleWindow = GetConsoleWindow(); // Get the console window handle
        ShowWindow(consoleWindow, SW_MAXIMIZE);  // Maximize the console window
}

int validate_data(char *num)
{
        if(strlen(num)>10)return 0;
        int i=0;
        if(num[i]=='-')i++;
        for(;num[i]!='\0';i++)
        {
                if(isdigit(num[i])==0)return 0;
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
                int i=0;
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
                        i=1;
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
                gotoxy(105, 20+i);
                getchar();
                fflush(stdin);
        }
        else if (x == '2') // Doubly Linked List Insertion at beginning
        {
                int i=0;
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
                        i=1;
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
                gotoxy(105, 20+i);
                getchar();
                fflush(stdin);
        }
        else if (x == '3') // singly Circular Linked List Insertion at beginning
        {
                int i=0;
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
                        i=1;
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
                gotoxy(105, 20+i);
                getchar();
                fflush(stdin);
        }
        else if (x == '4') // Doubly Circular Linked List Insertion at beginning
        {
                int i=0;
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
                        i=1;
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
                gotoxy(105, 20+i);
                getchar();
                fflush(stdin);
        }
        else{
                gotoxy(5, 20);
                printf("\t\t\t\t\t\t\t\t|\tError in Insert at beginning/Press Enter to Try again : \t|\n");
                gotoxy(115, 20);
                getchar();
                fflush(stdin);
        }
}
void insert(char x)
{
        char ch;
        do
        {
                system("cls");
                system("COLOR 4B");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t    INSERTION - MENU\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\t1. Insert at beg\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t2. Insert at end\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t3. Insert at position\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t4. Insert after/before any node\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t9. Previous Menu\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t|\t\t0. Exit\t\t\t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t|\t\tEnter your choice : \t\t\t|\n");
                printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                gotoxy(100, 26);
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
                        // dll(ch);
                        return;
                case '3':
                        // scl(ch);
                        return;
                case '4':
                        // dcl(ch);
                        return;
                case '9':
                        return;
                case '0':
                        system("cls");
                        system("COLOR 08");
                        exit(1);
                        break;
                default:
                        gotoxy(5, 26);
                        printf("\t\t\t\t\t\t\t\t|\tInvalid Choice/Press Enter to Try again : \t|\n");
                        gotoxy(115, 26);
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
        if (x == '1'||x=='3')
        {
                struct node *temp = head1;
                if (temp == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        if(x=='1')printf("\t\t\t\t\t\t\t\t|\t\tSingly Linked List is Empty\t\t|\n");
                        else if (x == '3')printf("\t\t\t\t\t\t\t\t|\tSingly Circular Linked List is empty\t|\n");
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
                        if(x=='1')printf("\t\t\t\t\t\t\t\t|\t\tYour Singly Linked List is \t\t|\n");
                        else if (x == '3')printf("\t\t\t\t\t\t\t\t|\tYour Singly Circular Linked List is\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\n");
                        gotoxy(70, 19);
                        while (temp->next != NULL)
                        {
                                printf("%s ", temp->data);
                                printf("-> ", temp->data);
                                temp = temp->next;
                        }
                        if (temp->next == NULL)
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
        else if (x == '2'||x=='4')
        {
                struct node *temp = head1;
                if (temp == NULL)
                {
                        printf("\t\t\t\t\t\t\t\t_________________________________________________________\n");
                        printf("\t\t\t\t\t\t\t\t*********************************************************\n");
                        if (x == '2')printf("\t\t\t\t\t\t\t\t|\t\tDoubly Linked List is empty\t\t|\n");
                        else if (x == '4')printf("\t\t\t\t\t\t\t\t|\tDoubly Circular Linked List is empty\t|\n");
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
                        if (x == '2')printf("\t\t\t\t\t\t\t\t|\t\tYour Doubly Linked List is \t\t|\n");
                        else if (x == '4')printf("\t\t\t\t\t\t\t\t|\tYour Doubly Circular Linked List is\t\t|\n");
                        printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\n");
                        gotoxy(70, 19);
                        while (temp->next != NULL)
                        {
                                printf("%s ", temp->data);
                                printf("-> ", temp->data);
                                temp = temp->next;
                        }
                        if (temp->next == NULL)
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
        else{
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
                        // delete(x);
                        break;
                case '3':
                        display(x);
                        break;
                case '9':
                        return;
                case '0':
                        system("cls");
                        system("COLOR 08");
                        exit(1);
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
                        clear();
                        system("COLOR 08");
                        exit(1);
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
