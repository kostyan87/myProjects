#include <stdio.h>
#include <stdlib.h>
#include "node2.h"
#define MAXLEN 128

int main() {
	Head *p0,*p02;
    Node *p,*p2;
    int i,t,num,*n,c;
    FILE *df;
    
    df=fopen("team.csv","r");
    if(df!=NULL){
	
	num=number_of_structures(df); /* ���-�� ����� � ��������� ������ */
	
    p0=make_head();               /* ������� ������ ���������� ������ */
	
  	p=node_fill(p0,num,df);       /* ��������� ��������� ������ */
  	
  	puts("How many elements do you want to copy(<13)?");
	scanf("%d",&t);
	if ((n=(int*)malloc(t*sizeof(int)))!=NULL){
       n=fill_mass(n,t);          /* ��������� ������ � �������� ���������� ��������� */
    }
    else puts("data error");
  	
  	bubble_sort(n,t);			  /* ��������� ������ �� ����������� */
	
	if (t){
		p02=make_head();		  /* ������� ������ ������ ������ */
	
		node_fill2(p0,p02,n,t);   /* ��������� ����� ������ */
		
		puts("\n");
		
		puts("New node:");
	
    	print_node2(p02,t);       /* ������� ����� ������ */
    
		clean_node2(p02,t);       /* ������� ����� ������ */
	}
	else puts("You enter 0 elements");
	
	clean_node(p0);				  /* ������� ������ ������ */
	
    }
    else puts("File not found!");
	return 0;
}
