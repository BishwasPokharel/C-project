#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
#define MAX_NAME_LEN 30

/*FUNCTION FOR WELCOME SCREEN*/
void WELCOME_MONITOR()
{
    //ASK FOR NAME
    char name[MAX_NAME_LEN];
    printf("\n\n");
    printf("%50s","YOUR NAME PLEASE\n\n\n\n");

     //ASK FOR PASSWORD FOR SECURITY REASON
    scanf("%[A-Z]s",name);
    printf("\n\n\t\t\t %s PLEASE ENTER YOUR PASSWORD\n",name);
}

/*FUNCTION TO MATCH STORED PASSWORD WITH INPUT PASSWORD*/
bool PASSWD_MATCHING_CASE()
{
    /*READ PASSWORD STORED IN FILE */
    char password[10];
    FILE *pswdptr;
    pswdptr=fopen("password.txt","r");

    if (pswdptr == NULL)
    {
        printf("CANNOT OPEN FILE \n");
        exit(0);
    }

    while( fgets ( password, 10, pswdptr ) != NULL );

    /*READ PASSWPRD FROM KEYBOARD IN PASSWORD FORM, WHICH HIDES INPUT AS * FORM IN SCREEN*/
    char enter_pass[10];
    int i=0;
    for(i=0;i<=4;i++)
    {
        if(i==4)
        {
            enter_pass[4]='\0';
        }
        else
        {
            enter_pass[i]=getch();
            printf("*");
        }
    }
    printf("\n\n");

    /*COMPARING PASSWORD STORED IN FILE AND TAKEN FROM INPUT*/
    if(strcmp(password,enter_pass)==0)
    {
        printf("\n\n%55s"," PASSWORD MATCH SUCESSFULLY");
        return true;
    }
    else
    {
        return false;
    }
    fclose(pswdptr);
}

/*FUNCTION TO CLEARING SCREEN AND LOADING NEW SCREEN*/
void CLEAR_SCREEN(bool MATCH)
{

    if(MATCH==true)
    {
        _sleep(2000);
        printf("\n\n\n\n%40s","LOADING");
        int i=0;
        for(i=0;i<5;i++)
        {   _sleep(20);
            printf(".");
        }
        system("cls");
    }
}

/*TO ADD ITEMS AND IT'S PRICES IN LIST*/
void ADD_LIST()
{
    struct ITEMS
    {
        int key;
        char item_name[50];
        float price;
    };

    struct ITEMS item[1000];
    LOOKUP_DATABASE();
}


/*FUNCTION TO CHANGE PASSWORD*/
void CHANGE_PSWD()
{

    FILE *ptr_file;
    int x;

    ptr_file =fopen("password.txt", "w+");

    if (!ptr_file)
    return 1;

    char new_pswd[10];
    printf("\n\n\nENTER NEW PASSWORD:");

    int j=0;
    for(j=0;j<=4;j++)
    {
        if(j==4)
            {
                new_pswd[4]='\0';
            }
            else
            {
                new_pswd[j]=getch();
                printf("*");
            }
    }

    fprintf(ptr_file,"%s",new_pswd);
    printf("\n\n%40S","PASSWORD SUCESSFULLY CHANGED\n\n");
    fclose(ptr_file);

    printf("\n%55s","WANT TO PROCESS FURTHER?\n");
    printf("\%55s","\n\n Y-> 0");
    printf("\%55s","\n N-> 1 :");


    int check;
    scanf("%d",&check);
    if(check<0 || check >1){return 0;}
    if(check==0)
    {
        system("cls");
        SELECT_OPERATION();
    }
    else
    {
        exit(0);
    }
}

/*FUNCTION TO EXIT THE PROGRAM*/
void EXIT()
{
    printf("\n\n\n");
    printf("%48s","EXIT SUCESSFULLY");
    printf("\n\n\n");
    int i=0;
    for(i=0;i<80;i++)
        {
            printf(".");
        }
    exit(0);
}

/*FUNCTION TO SELECT ONE PROCESS AMONG GIVEN PROCESSES*/
void SELECT_OPERATION()
{
    void (*SELECT_OPERATION_ARR[])()={ADD_LIST,CHANGE_PSWD,EXIT};
    printf("\n\n\n\tADD_LIST[0] \t\t CHANGE_PSWD[1] \t \tEXIT[2]\n");
    int num_option;


    printf("\n\n%43s","PRESS:");
    scanf("%d",&num_option);
    if(num_option<0 && num_option>2){printf("\n\n%47s"," NUMBER INVALID");}

    //CALLING FUNCTION W.R.T IT'S OPTION NUMBER
    (*SELECT_OPERATION_ARR[num_option])();
}





