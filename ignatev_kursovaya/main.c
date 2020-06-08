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
	    n=number_of_structures(df); /* ������� ���-�� �������� � ����� */

        p0=make_head();             /* �������� ����������� ������ */
        node_fill2(p0,df,n);
        
        menu(p0);                   /* ���� */   
        
        clean_nodes(p0);             /* ������� ������ */
        
        fclose(df);
    }
    else puts("File not found!");
	return 0;
}
