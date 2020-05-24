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
	
	num=number_of_structures(df); /* Кол-во узлов в начальном списке */
	
    p0=make_head();               /* Создаем голову начального списка */
	
  	p=node_fill(p0,num,df);       /* Заполняем начальный список */
  	
  	puts("How many elements do you want to copy(<13)?");
	scanf("%d",&t);
	if ((n=(int*)malloc(t*sizeof(int)))!=NULL){
       n=fill_mass(n,t);          /* Заполняем массив с номерами копируемых элементов */
    }
    else puts("data error");
  	
  	bubble_sort(n,t);			  /* Сортируем массив по возрастанию */
	
	if (t){
		p02=make_head();		  /* Создаем голову нового списка */
	
		node_fill2(p0,p02,n,t);   /* Заполняем новый список */
		
		puts("\n");
		
		puts("New node:");
	
    	print_node2(p02,t);       /* Выводим новый список */
    
		clean_node2(p02,t);       /* Очищаем новый список */
	}
	else puts("You enter 0 elements");
	
	clean_node(p0);				  /* Очищаем старый список */
	
    }
    else puts("File not found!");
	return 0;
}
