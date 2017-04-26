#include<stdio.h>
#include <mysql.h>
#include<string.h>

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void ADD_LIST1(MYSQL *con)
{
    if(con)
    {
        char Item[25];
        int price1;
        char buffer[1024];

        printf("\nENTER LIST:");
        scanf("%s",&Item);

        printf("\nENTER PRICE:");
        scanf("%d",&price1);

        printf("%d", price1);
        sprintf(buffer, "insert into lists(\`Name\`,\`Price\`) values (\'%s\',%d)ON DUPLICATE KEY UPDATE Price = (Price + %d)",Item,price1, price1);
        printf("\n");

        if(mysql_query(con,buffer)==0)
        fprintf(stdout,"data insert successfully\n");
    }
}

VOID LOOKUP_DATABASE()
{
    MYSQL *con = mysql_init(NULL);
    MYSQL_RES *res;
    MYSQL_ROW row;

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root","projectdb", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

       if (mysql_query(con, "DROP TABLE IF EXISTS Lists")) {
      finish_with_error(con);
    }

  if (mysql_query(con, "CREATE TABLE Lists(Id INT NOT NULL AUTO_INCREMENT , Name TEXT, Price INT,PRIMARY KEY (Id),UNIQUE KEY Name(Name(50)))")) {
      finish_with_error(con);
  }

    int x=0;
    while(!x)
    {
        ADD_LIST1(con);
        printf("\n\n\n");
        printf("%45s","WANT TO ADD AGAIN?");
        printf("\n\n");
        printf("%40s","Y->0:\t N->1:");
        scanf("%d",&x);
    }

    mysql_query(con,"SELECT * FROM lists");
    res=mysql_store_result(con);
    printf("\n\n\n");

    while(row=mysql_fetch_row(res))
    {
      printf("%s\t\t%s\t\t\t%s\n",row[0],row[1],row[2]);
    }

  mysql_free_result(res);
  mysql_close(con);
  exit(0);

}
