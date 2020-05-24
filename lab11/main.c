#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#define MAXLEN 128

int main() {
    champions **ch=NULL;
    Head *p0;
    Node *p;
    int slen,i,n;
    char **s2=NULL;
    char s1[MAXLEN];
    FILE *df,*df2;

    df=fopen("champions_cup_winners.csv","r");
	df2=fopen("team.csv","r");
    if((df!=NULL)&&(df2!=NULL))
    {
	    n=number_of_structures(df); /* ������� ���-�� ����� � ����� */
	    
        p0=make_head();             /* �������� ����������� ������ */
        p=node_fill(p0,n,df2);
        
        puts("Initial array:");
        ch=fill(n,df,p0);           /* ���������� ������� ��������(� ��� ����� ���������� ����������� ������) */
        
        print_struct(ch,n);         /* ����� ������� �������� */
        
        puts("---------------------------------------------------------------------------------------");
        add_node(p0,p);             /* ���������� �������� � ���������� ������ */
        puts("---------------------------------------------------------------------------------------");
        puts("New Node:");
        print_node(p0);             /* ����� ������ ����������� ������ */
        
        fclose(df);
        fclose(df2);
        
        ClearStringArray(ch,12); /* ������� ������� �������� */
        clean_node(p0);             /* ������� ������ */
    }
    else puts("File not found!");
	return 0;
}
