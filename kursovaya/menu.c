#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128
#include "list.h"

/* Безопасный ввод */
int safe_scanf()
{
    int chooce = -1;
    char str[100];

    scanf("%s", str);

    while(sscanf(str, "%d", &chooce) != 1) {
        printf("Incorrect input! Try again use only numbers!\n");
        scanf("%s" , str);
    }

    return chooce;
}

/* Меню */
void menu(Head *p0){
	int c,add,num,option,p,k,del;
	c=1;
	while (c != 7){
		system("CLS");
		print_menu();
        c=safe_scanf();
        if (c==0) print_reference();
        else if (c==1) sub_menu_add(p0,c);
		else if (c==2) sub_menu_edit(p0,c);
		else if (c==3) sub_menu_delete(p0,c);
		else if (c==4) sub_menu_output(p0);
		else if (c==5) sub_menu_search(p0,c);
		else if (c==6) sub_menu_sort(p0,c);
		else if (c==7) save_file(p0);
	}
}

/* Печать меню */
void print_menu(){
    puts("Menu:\n");
    puts("0 - Reference");
    puts("1 - Adding cards");
    puts("2 - Editing cards");
    puts("3 - Deleting cards");
    puts("4 - Output of the card");
    puts("5 - Search for cards by parameter");
    puts("6 - Sorting the cards by parameter");
    puts("7 - Exit and save card \n");
}

/* Печать меню для добавления элементов */
void menu_edit(){
	printf("Which field do you want to change?:\n");
	printf("0 - number_of_titles\n");
    printf("1 - team\n");
    printf("2 - country\n");
    printf("3 - year\n");
    printf("4 - budget\n");
    printf("5 - capacity\n");
    printf("6 - matches\n");
    printf("7 - goals\n");
    printf("8 - finals\n");
	printf("9 - return to main menu\n");
}

/* Печать меню для поиска элементов */
void menu_search(){
	printf("What field do you want to search for cards in?:\n");
    printf("0 - number_of_titles\n");
    printf("1 - team\n");
    printf("2 - country\n");
    printf("3 - year\n");
    printf("4 - matches\n");
    printf("5 - goals\n");
    printf("6 - finals\n");
    printf("7 - return to main menu\n");
    printf("Enter your choice: ");
}

/* Печать меню для сортировки элементов */
void menu_sort(){
	printf("What field do you want to sort items by?:\n");
    printf("0 - number_of_titles\n");
    printf("1 - team\n");
    printf("2 - country\n");
    printf("3 - year\n");
    printf("4 - matches\n");
    printf("5 - goals\n");
    printf("6 - finals\n");
    printf("7 - return to main menu\n");
    printf("Enter your choice: ");
}

/* Печать справки */
void print_reference(){
	system("CLS");
	puts("Electronic cards");
	puts("\nDeveloper: Konstantin Ignatiev");
	puts("Student of group 9305");
    puts("\nLink:");
    puts("\nThis is an electronic card library designed to store cards with the best");
	puts("teams in the history of the Champions League.");
	puts("Possible manipulations with the card file can be viewed in the main menu.");
	puts("Each operation can be used several times.");
	puts("You can add cards, edit, sort, delete, and search for cards.");
	puts("The final cards will be written to the card.csv file.");
	puts("\nPress any key to come back to main menu");
	getchar();
	getchar();
}

/* Дополнительное меню для добавления элемента в картотеку */
void sub_menu_add(Head *p0,int c){
	int add,check;
	check=1;
    while(c>0){
	    if (check) system("CLS");
	    else puts("Incorrect input!Try again!");
	    puts("Where do you want to add the card?");
	    puts("1 - add first");
     	puts("2 - add last");
      	puts("3 - return back");
  	    add=safe_scanf();
   		if (add==1){
  			add_first(p0);
  			puts("The card was added successfully!");
  			c=-1;
  			puts("\nPress any key to come back to main menu");
			getchar();
			getchar();
        } 
 		else if (add==2){
			add_last(p0,p0->last);
			puts("The card was added successfully");
			c=-1;
			puts("\nPress any key to come back to main menu");
			getchar();
			getchar();
        }
 		else if (add==3) c=0; 
   		else check=0;
    }	
}

/* Дополнительное меню для редактирования элемента в картотеке */
void sub_menu_edit(Head *p0,int c){
	int p,k,num,option;
	system("CLS");
 	p=1;
	k=1;
	print_node2(p0);
	puts("\n");
	while (c==2){
	    if (p){
 		    puts("Enter the number of the card you want to change. Enter 0 if you want return back:");
	        num=safe_scanf();
	    }
	    if ((num>=0)&&(num<=p0->cnt)){
	    	if (num==0) c=-1;
	    	else
	    	{
		        p=0;
	        	if (k) {
	        	   menu_edit();
	               k=0;
      	        }
	        	option=safe_scanf();
            	if ((option>=0)&&(option<=8)){
	               edit_card(p0,num,option);
                   c=-1;
      	        }
            	if (option==9) c=-1;
            	else puts("Incorrect input!Try again!");    		
			}
        }
	    else puts("Incorrect input!Try again!");
	}	   
}

/* Дополнительное меню для удаления элемента из картотеки */
void sub_menu_delete(Head *p0,int c){
	int del,check,check2;
	check=1;
	check2=1;
	system("CLS");
	while (c==3)
	{
  	    if (check2){
  	    	system("CLS");
  	    	print_node2(p0);
            puts("\n");
		    printf("Enter the number of the card you want to delete. Enter 0 if you want return back:\n");
        }
		del=safe_scanf();
		if ((del>=0)&&(del<=p0->cnt)){
			
			if (del==0) c=-1;
			else delete_card(p0,del);
			check2=1;
		}
		else{
			puts("Error! There is no card with this number! Try again or enter 0 to comeback to main menu");
			check2=0;
		} 
	}
}

/* Дополнительное меню для вывода картотеки */
void sub_menu_output(Head *p0){
	system("CLS");
	print_node2(p0);
	puts("\nPress any key to come back to main menu");
	getchar();
	getchar();
}

/* Дополнительное меню для поиска элемента в картотеке */
void sub_menu_search(Head *p0,int c){
	int option,check;
	check=1;
	while (c==5){
		if (check){
			system("CLS");
			menu_search();
		}
		option=safe_scanf();
		if ((option>=0)&&(option<=7)){
			if (option!=7) card_search(p0,option);
			else c=-1;
			check=1;
		}
		else {
			check=0;
			puts("Incorrect input!Try again!");
		}
	}
}

/* Дополнительное меню для сортировки элементов в картотеке */
void sub_menu_sort(Head *p0,int c){
	int option,check;
	check=1;
	while (c==6){
		if (check){
			system("CLS");
			menu_sort();
		}
		option=safe_scanf();
		if ((option>=0)&&(option<=7)){
			if (option!=7){
				card_sorted(p0,option);
				print_node2(p0);
				puts("\nPress any key to come back to main menu");
				getchar();
				getchar();
			} 
			else c=-1;
			check=1;
		}
		else {
			check=0;
			puts("Incorrect input!Try again!");
		}
	}	
}

/* Запись картотеки в файл */
void save_file(Head *p0)
{
    Node *p;
    int i;
	FILE *df2;
    df2=fopen("card.csv","w");
    p=p0->first;
    for(i = 0; i < p0->cnt; i++){
        fprintf(df2,"%3d;%3d;%20s;%20s;%d;%5.1f;%5.3f;%7.1d;%7.1d;%7.1d\n",p->id,p->number_of_titles,p->team,p->country
        ,p->year,p->budget,p->capacity,p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
        p=p->next;
    }
    fclose(df2);
    puts("Your cards were successfully saved to the card.csv file!");
}
