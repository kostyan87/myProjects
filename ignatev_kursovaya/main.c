#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128
#include "list.h"
#include "menu.h"
#include "list.c"
#include "menu.c"

int main() {
    Head *p0;
    int n;
    FILE *df;

    df=fopen("champions_cup_winners.csv","r");
    if(df!=NULL)
    {
	    n=number_of_structures(df); /* Подсчет кол-ва структур в файле */

        p0=make_head();             /* Создание двусвязного списка */
        node_fill2(p0,df,n);
        
        menu(p0);                   /* Меню */   
        
        clean_nodes(p0);             /* Очистка списка */
        
        fclose(df);
    }
    else puts("File not found!");
	return 0;
}
