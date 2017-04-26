#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header_file.h"


int main()
{
    //CALL FOR WELCOME SCREEN
    WELCOME_MONITOR();

    //CALL FOR PASSWORD MATCHING CASE
    bool MATCH=PASSWD_MATCHING_CASE();

    if(MATCH==true)
    {
        //CLEAR SCREEN
        CLEAR_SCREEN(MATCH);

         //SELECT OPERATION
        SELECT_OPERATION();


    }
    else
    {
          printf("%45s","OPERATION ABORT!!\n");
    }


    return 0;
}
