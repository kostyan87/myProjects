#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128
#include "list.h"
#include "menu.h"


/*--------------------------------------------------------------------------------------*/

/* Стандартные функции */                     

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

/* Ввод полей элемента картотеки(с клавиатуры) */
Node *create_node_enter()
{
    Node *new_node=NULL;

    new_node = (Node*)malloc(sizeof(Node));
    if(new_node)
    {
    	new_node->team=(char*)malloc(MAXLEN*sizeof(char));
   		new_node->country=(char*)malloc(MAXLEN*sizeof(char));
   		new_node->matches_goals_finals=(int*)malloc(3*sizeof(int));
   		printf("Enter number_of_titles:");
   		(*new_node).number_of_titles=safe_scanf();
   		printf("Enter team:");
   		getchar();
    	fgets((*new_node).team,MAXLEN,stdin);
    	printf("Enter country:");
    	fgets((*new_node).country,MAXLEN,stdin);
    	printf("Enter year:");
    	(*new_node).year=safe_scanf();
    	printf("Enter budget:");
    	(*new_node).budget=safe_scanf();
    	printf("Enter capacity:");
    	(*new_node).capacity=safe_scanf();
    	printf("Enter matches:");
    	(*new_node).matches_goals_finals[0]=safe_scanf();
    	printf("Enter goals:");
    	(*new_node).matches_goals_finals[1]=safe_scanf();
    	printf("Enter finals:");
    	(*new_node).matches_goals_finals[2]=safe_scanf();
        new_node->country[strlen(new_node->country)-1]='\0';
    	new_node->team[strlen(new_node->team)-1]='\0';
    	new_node->prev = NULL;
    	new_node->next = NULL;
    	
    }
    return new_node;
	/*free(new_node->team);
 	free(new_node->country);
 	free(new_node->matches_goals_finals);
 	free(new_node);*/
}

/* Создание головы */
Head *make_head()
{
    Head *ph=NULL;

    ph=(Head*)malloc(sizeof(Head));
    if(ph)
    {
    	ph->cnt=0;
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}

/* Добавление элемента картотеки в начало(ручной ввод) */
void add_first(Head *my_head)
{
	Node *str0=NULL,*str1=NULL,*p=NULL;
	int i;

    str0=create_node_enter();
    str1=my_head->first;
    my_head->first = str0;
    str0->next=str1;
	my_head->last->next = str0;
	str0->prev=my_head->last;
    my_head->cnt++;
    str0->id=1;
    p=my_head->first->next;
    for (i=0;i<my_head->cnt-1;i++){
    	p->id++;
    	p=p->next;
	} 
}

/* Добавление элемента картотеки в начало(ввод из файла) */
void add_first2(Head *my_head, Node *new_node)
{
    my_head->first = new_node;
    my_head->first->id=1;
    my_head->last = new_node;
    my_head->cnt++;
}

/* Добавление элемента картотеки в конец(ручной ввод) */
void add_last(Head *my_head,Node *prev_node)
{
    int n;
	Node *str0=NULL;

    str0=create_node_enter();
    if(my_head&&str0&&prev_node)
    {
    	n=my_head->cnt+1;
        prev_node->next=str0;
        str0->prev=prev_node;
        my_head->last=str0;
        str0->next=my_head->first;
        str0->id=n;
        my_head->cnt=n;
    }
}

/* Добавление элемента картотеки в конец(ввод из файла) */
void add_last2(Head *my_head, Node *new_node, Node *prev_node)
{
    int n;

    if(my_head&&new_node&&prev_node)
    {
    	n=my_head->cnt+1;
        prev_node->next=new_node;
        new_node->prev=prev_node;
        my_head->last=new_node;
        new_node->next=my_head->first;
        my_head->first->prev=new_node;
        new_node->id=n;
        my_head->cnt=n;
    }
}

/* Печать названий полей картотеки */
void print_header()
{
	printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| %3s | %3s | %20s | %20s | %4s | %6s | %4s | %7s | %6s | %6s |\n","ID","Titles","Team",
	"Country","Year","Budget","Capacity","Matches","Goals","Finals");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
}

/* Вывод картотеки на экран */
void print_node2(Head *p0){
	Node *p;
	int i;
	p=p0->first;
	print_header();
    for(i=0;i<p0->cnt;i++)
    {
        printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
		p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
        p=p->next;
    }
}

void clean_node(Node *p){
	if((p -> next) != NULL) p -> next = NULL;
    if((p -> prev) != NULL) p -> prev = NULL;
	free(p->country);
	free(p->team);
	free(p->matches_goals_finals);
	free(p);
}

void clean_head(Head *p0){
	p0->first=NULL;
	p0->last=NULL;
	free(p0);
}

void clean_nodes(Head *p0){
	Node *p=NULL,*tmp=NULL;
	int i;
	p=p0->first;
	
	for(i=0;i<p0->cnt;i++){
		tmp=p->next;
		clean_node(p);
		p=tmp;
	}
	clean_head(p0);
}

/* Подсчет кол-ва строк в файле */
int number_of_structures(FILE *df){
	int n=0;
	char s1[MAXLEN];
    while((fgets(s1,MAXLEN,df))!=NULL) n++;
    rewind(df);
    return n;
}

/* Длина строки */
int slens(char *s1){
	int slen;
	slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);
    return slen;
}

/* Ввод полей элемента картотеки(из файла) */
Node *create_node2(char **str)
{
    Node *new_node=NULL;

    new_node = (Node*)malloc(sizeof(Node));
    if(new_node)
    {
        new_node->id = 1;
        new_node->number_of_titles=atoi(str[0]);
        new_node->team=(char*)malloc(MAXLEN*sizeof(char));
   		new_node->country=(char*)malloc(MAXLEN*sizeof(char));
        /*new_node->team=str[1];
        new_node->country=str[2];*/
        strcpy(new_node->team,str[1]);
        strcpy(new_node->country,str[2]);
        new_node->year=atoi(str[3]);
        new_node->budget=atof(str[4]);
        new_node->capacity=atof(str[5]);
        new_node->matches_goals_finals=(int*)malloc(3*sizeof(int));
        new_node->matches_goals_finals[0]=atoi(str[6]);
        new_node->matches_goals_finals[1]=atoi(str[7]);
        new_node->matches_goals_finals[2]=atoi(str[8]);
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    ClearStringArray(str,8);
    return new_node;
}

void ClearStringArray(char **str, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        free(str[i]);
        str[i]=NULL;
    }
    free(str);
    str=NULL;
}

char **simple_split(char *str, int length, char sep)
{
    char **str_array = NULL;
    int i,j,k,m;
    int key,count;
    for(j=0,m=0;j<length;j++)
    {
        if(str[j]==sep) m++;
    }
    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL) key=1;
            else
            {
                key=0;
                i=m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<length;j++)
            {
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else
                {
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
        }
        else
        {
            ClearStringArray(str_array,count);
        }
     }
     return str_array;
}

/* Заполнение картотеки из файла */
void node_fill2(Head *p0,FILE *df,int n){
    Node *p,*p1,*my_node=NULL;
    char my_word[MAXLEN];
    char **s2=NULL,sep;
    char s1[MAXLEN];
    int i,slen,t,j;
	t=1;
	sep=';';
    for (i=0;i<n;i++)
    {
    	fgets(s1,MAXLEN,df);
    	slen=slens(s1);
    	s2=simple_split(s1,slen,sep);
		if(t){
			  t=0;
		      p1=create_node2(s2);
  			  add_first2(p0,p1);
		      p=p0->first;
		}
		else
        {
              my_node=create_node2(s2);
              add_last2(p0, my_node, p);
              p=p0->last;
        }
        if (i==n-1) {
        	p0->last->next=p0->first;
        	p0->first->prev=p0->last;
		}
	}
}

/* Удаление карточки */
void delete_card(Head *p0,int n){
	Node *card,*delete_card,*next,*prev;
	int i,y;
	card=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (card->id==n){
			delete_card=card;
			i=p0->cnt;
		}
		card=card->next;
	}
	next=delete_card->next;
	prev=delete_card->prev;
	delete_card->prev->next=next;
	delete_card->next->prev=prev;
	if (delete_card->id==1) p0->first=next;
	if (delete_card->id==p0->cnt) p0->last=prev;
	p0->cnt--;
	y=(p0->cnt+1)-delete_card->id;
	card=delete_card->next;
	clean_node(delete_card);
	for (i=0;i<y;i++){
		card->id--;
		card=card->next;
	}
}

/*--------------------------------------------------------------------------------------*/

/* Функции для изменения элемента в картотеке */

/* Изменение кол-ва титулов */
void number_of_titles_edit(Node *p)
{
	printf("Enter a new number of titles:");
	p->number_of_titles=safe_scanf();
}

/* Изменение названия команды */
void team_edit(Node *p)
{
	printf("Enter a new team name:");
	getchar();
	fgets(p->team,MAXLEN,stdin);
	p->team[strlen(p->team)-1]='\0';
}

/* Изменение названия страны */
void country_edit(Node *p)
{
	printf("Enter a new country name:");
	getchar();
	fgets(p->country,MAXLEN,stdin);
	p->country[strlen(p->country)-1]='\0';
}

/* Изменение года основания */
void year_edit(Node *p)
{
	printf("Enter a new year:");
	p->year=safe_scanf();
}

/* Изменение бюджета команды */
void budget_edit(Node *p)
{
	printf("Enter a new budget:");
	p->budget=safe_scanf();
}

/* Изменение вместительности стадиона */
void capacity_edit(Node *p)
{
	printf("Enter a new number of capacity:");
	p->capacity=safe_scanf();
}

/* Изменение кол-ва матчей */
void matches_edit(Node *p)
{
	printf("Enter a new number of matches:");
	p->matches_goals_finals[0]=safe_scanf();
}

/* Изменение кол-ва голов */
void goals_edit(Node *p)
{
	printf("Enter a new number of goals:");
	p->matches_goals_finals[1]=safe_scanf();
}

/* Изменение кол-ва финалов */
void finals_edit(Node *p)
{
	printf("Enter a new number of finals:");
	p->matches_goals_finals[2]=safe_scanf();
}

void Kind_edit(Node *p, void (*funcName)(Node*))
{
   funcName(p);
}

/* Меню выбора */
void edit_card(Head *p0,int num,int option)
{
    Node *p;
	int i;
	void (*kind[9])(Node*);
	kind[0] = number_of_titles_edit;
	kind[1] = team_edit;
	kind[2] = country_edit;
	kind[3] = year_edit;
	kind[4] = budget_edit;
	kind[5] = capacity_edit;
	kind[6] = matches_edit;
	kind[7] = goals_edit;
	kind[8] = finals_edit;
	p=p0->first;
	if ((option>=0)&&(option<=p0->cnt)){
	for(i=0;i<p0->cnt;i++)
    {
 	    if (p->id==num){
      	    Kind_edit(p,kind[option]);
	    }
		    p=p->next;
	}
  }
}

/*--------------------------------------------------------------------------------------*/

/* Функции для поиска элемента в картотеке */

/* Поиск по кол-ву титулов */
void number_of_titles_search(Head *p0){
	int i,min,max,d,len,count,check;
	Node *p;
	char s[MAXLEN];
	count=0;
	check=1;
	puts("Do you want to enter additional search field(country)?");
	puts("1-Yes");
	puts("2-No");
	while (check){
		d=safe_scanf();
		if ((d==1)||(d==2)) check=0;
		else puts("Incorrect input!Try again!");
	}
	if (d==1){
		puts("Enter field value:");
		getchar();
		fgets(s,MAXLEN,stdin);
		len=slens(s);
	}
	puts("Enter the range of values to search for");
	printf("Min:");
	min=safe_scanf();
	printf("Max:");
	max=safe_scanf();
	p=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (d==1){
			if ((p->number_of_titles>=min)&&(p->number_of_titles<=max)&&(strncmp(s,p->country,len)==0)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;	
		}
		else{
			if ((p->number_of_titles>=min)&&(p->number_of_titles<=max)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}
	}
	if (count==0) puts("There are no such cards!");
	puts("\nPress any key to come back to menu");
	getchar();
	getchar();
}

/* Поиск по названию команды */
void team_search(Head *p0){
	int i,min,max,len,count;
	Node *p;
	char s[MAXLEN];
	count=0;
	puts("Enter team:");
	getchar();
	fgets(s,MAXLEN,stdin);
	len=slens(s);
	p=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (strncmp(s,p->team,len)==0){
		print_header();	
		printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
		p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
		count++;
		}
		p=p->next;
	}
	if (count==0) puts("There are no such cards!");
	puts("\nPress any key to come back to menu");
	getchar();
}

/* Поиск по названию страны */
void country_search(Head *p0){
	int i,min,max,len,count,check;
	Node *p;
	char s[MAXLEN];
	count=0;
	check=1;
	puts("Enter country:");
	getchar();
	fgets(s,MAXLEN,stdin);
	len=slens(s);
	p=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (strncmp(s,p->country,len)==0){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
		}
		p=p->next;
	}
	if (count==0) puts("There are no such cards!");
	puts("\nPress any key to come back to menu");
	getchar();
}

/* Поиск по году основания */
void year_search(Head *p0){
	int i,min,max,d,len,count,check;
	Node *p;
	char s[MAXLEN];
	count=0;
	check=1;
	puts("Do you want to enter additional search field(country)?");
	puts("1-Yes");
	puts("2-No");
	while (check){
		d=safe_scanf();
		if ((d==1)||(d==2)) check=0;
		else puts("Incorrect input!Try again!");
	}
	if (d==1){
		puts("Enter field value:");
		getchar();
		fgets(s,MAXLEN,stdin);
		len=slens(s);
	}
	puts("Enter the range of values to search for");
	printf("Min:");
	min=safe_scanf();
	printf("Max:");
	max=safe_scanf();
	p=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (d==1){
			if ((p->year>=min)&&(p->year<=max)&&(strncmp(s,p->country,len)==0)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}
		else{
			if ((p->year>=min)&&(p->year<=max)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}
	}
	if (count==0) puts("There are no such cards!");
	puts("\nPress any key to come back to menu");
	getchar();
	getchar();
}

/* Поиск по кол-ву матчей */
void matches_search(Head *p0){
	int i,min,max,d,len,count,check;
	Node *p;
	char s[MAXLEN]; 
	count=0;
	check=1;
	puts("Do you want to enter additional search field(country)?");
	puts("1-Yes");
	puts("2-No");
	while (check){
		d=safe_scanf();
		if ((d==1)||(d==2)) check=0;
		else puts("Incorrect input!Try again!");
	}
	if (d==1){
		puts("Enter field value:");
		getchar();
		fgets(s,MAXLEN,stdin);
		len=slens(s);
	}
	puts("Enter the range of values to search for");
	printf("Min:");
	min=safe_scanf();
	printf("Max:");
	max=safe_scanf();
	p=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (d==1){
			if ((p->matches_goals_finals[0]>=min)&&(p->matches_goals_finals[0]<=max)&&(strncmp(s,p->country,len)==0)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}
		else{
			if ((p->matches_goals_finals[0]>=min)&&(p->matches_goals_finals[0]<=max)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;		
		}
	}
	if (count==0) puts("There are no such cards!");
	puts("\nPress any key to come back to menu");
	getchar();
	getchar();
}

/* Поиск по кол-ву голов */
void goals_search(Head *p0){
	int i,min,max,d,len,count,check;
	Node *p;
	char s[MAXLEN];
	count=0;
	check=1;
	puts("Do you want to enter additional search field(country)?");
	puts("1-Yes");
	puts("2-No");
	while (check){
		d=safe_scanf();
		if ((d==1)||(d==2)) check=0;
		else puts("Incorrect input!Try again!");
	}
	if (d==1){
		puts("Enter field value:");
		getchar();
		fgets(s,MAXLEN,stdin);
		len=slens(s);
	}
	puts("Enter the range of values to search for");
	printf("Min:");
	min=safe_scanf();
	printf("Max:");
	max=safe_scanf();
	p=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (d==1){
			if ((p->matches_goals_finals[1]>=min)&&(p->matches_goals_finals[1]<=max)&&(strncmp(s,p->country,len)==0)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}
		else{
			if ((p->matches_goals_finals[1]>=min)&&(p->matches_goals_finals[1]<=max)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}	
	}
	if (count==0) puts("There are no such cards!");
	puts("\nPress any key to come back to menu");
	getchar();
	getchar();
}

/* Поиск по кол-ву финалов */
void finals_search(Head *p0){
	int i,min,max,d,len,count,check;
	Node *p;
	char s[MAXLEN];
	count=0;
	check=1;
	puts("Do you want to enter additional search field(country)?");
	puts("1-Yes");
	puts("2-No");
	while (check){
		d=safe_scanf();
		if ((d==1)||(d==2)) check=0;
		else puts("Incorrect input!Try again!");
	}
	if (d==1){
		puts("Enter field value:");
		getchar();
		fgets(s,MAXLEN,stdin);
		len=slens(s);
	}
	puts("Enter the range of values to search for");
	printf("Min:");
	min=safe_scanf();
	printf("Max:");
	max=safe_scanf();
	p=p0->first;
	for (i=0;i<p0->cnt;i++){
		if (d==1){
			if ((p->matches_goals_finals[2]>=min)&&(p->matches_goals_finals[2]<=max)&&(strncmp(s,p->country,len)==0)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}
		else{
			if ((p->matches_goals_finals[2]>=min)&&(p->matches_goals_finals[2]<=max)){
			print_header();
			printf("| %3d | %6d | %20s | %20s | %4d | %6.1f | %8.3f | %7.1d | %6.1d | %6.1d |\n",p->id,
        	p->number_of_titles,p->team,p->country,p->year,p->budget,p->capacity,
			p->matches_goals_finals[0],p->matches_goals_finals[1],p->matches_goals_finals[2]);
			count++;
			}
			p=p->next;
		}	
	}
	if (count==0) puts("There are no such cards!");
	puts("\nPress any key to come back to menu");
	getchar();
	getchar();
}

void Kind_search(Head *p, void (*funcName)(Head*))
{
    funcName(p);
}

/* Меню выбора */
void card_search(Head *p0,int option){
	void (*kind[7])(Head*);
	kind[0] = number_of_titles_search;
	kind[1] = team_search;
	kind[2] = country_search;
	kind[3] = year_search;
	kind[4] = matches_search;
	kind[5] = goals_search;
	kind[6] = finals_search;
   	Kind_search(p0,kind[option]);
}

/*--------------------------------------------------------------------------------------*/

/* Функции для сортировки элементов в картотеке */

/* Функция для обмена элементами */
void swap(Node *tmp, Node *a)
{
    char *team, *country;
    int year, number_of_titles,id;
    int matches,goals,finals;

    year=tmp->year;
    tmp->year=a->year;
    a->year=year;

    number_of_titles=tmp->number_of_titles;
    tmp->number_of_titles=a->number_of_titles;
    a->number_of_titles=number_of_titles;

    team=tmp->team;
    tmp->team=a->team;
    a->team=team;

    country=tmp->country;
    tmp->country=a->country;
    a->country=country;

    matches=tmp->matches_goals_finals[0];
    tmp->matches_goals_finals[0]=a->matches_goals_finals[0];
    a->matches_goals_finals[0]=matches;

    goals=tmp->matches_goals_finals[1];
    tmp->matches_goals_finals[1]=a->matches_goals_finals[1];
    a->matches_goals_finals[1]=goals;
    
    finals=tmp->matches_goals_finals[2];
    tmp->matches_goals_finals[2]=a->matches_goals_finals[2];
    a->matches_goals_finals[2]=finals;
}

/* Функция сортировки по кол-ву титулов */
void number_of_titles_sorted(Head *p0,int sort)
{
	Node *p,*o,*tmp;
	int i,j;
	
	for (j=0;j<p0->cnt-1;j++){
		p=p0->first;
		tmp=p->next;
    	for(i=0;i<p0->cnt-1;i++)
    	{
          if (sort){
            if ((p->number_of_titles)<(tmp->number_of_titles)){
          		swap(p,tmp);
		  }
		  }
          else{
          	if ((p->number_of_titles)>(tmp->number_of_titles)){
          	 	swap(p,tmp);
		  	 }
		  }
          p=p->next;
          tmp=tmp->next;
	    }
	}
}

/* Функция сортировки по году основания */
void year_sorted(Head *p0,int sort)
{
	Node *p,*o,*tmp;
	int i,j;
	
	for (j=0;j<p0->cnt-1;j++){
		p=p0->first;
		tmp=p->next;
    	for(i=0;i<p0->cnt-1;i++)
    	{
          if (sort){
            if ((p->year)<(tmp->year)){
          		swap(p,tmp);
	  	    }
		  }
          else{
          	if ((p->year)>(tmp->year)){
          	 	swap(p,tmp);
		  	 }
		  }
          p=p->next;
          tmp=tmp->next;
	    }
	}
}

/* Функция сортировки по кол-ву матчей */
void matches_sorted(Head *p0,int sort)
{
	Node *p,*o,*tmp;
	int i,j;
	
	for (j=0;j<p0->cnt-1;j++){
		p=p0->first;
		tmp=p->next;
    	for(i=0;i<p0->cnt-1;i++)
    	{
          if (sort){
            if ((p->matches_goals_finals[0])<(tmp->matches_goals_finals[0])){
          		swap(p,tmp);
	  	    }
		  }
          else{
          	if ((p->matches_goals_finals[0])>(tmp->matches_goals_finals[0])){
          	 	swap(p,tmp);
		  	 }
		  }
          p=p->next;
          tmp=tmp->next;
	    }
	}
}

/* Функция сортировки по кол-ву голов */
void goals_sorted(Head *p0,int sort)
{
	Node *p,*o,*tmp;
	int i,j;
	
	for (j=0;j<p0->cnt-1;j++){
		p=p0->first;
		tmp=p->next;
    	for(i=0;i<p0->cnt-1;i++)
    	{
          if (sort){
            if ((p->matches_goals_finals[1])<(tmp->matches_goals_finals[1])){
          		swap(p,tmp);
	  	    }
		  }
          else{
          	if ((p->matches_goals_finals[1])>(tmp->matches_goals_finals[1])){
          	 	swap(p,tmp);
		  	 }
		  }
          p=p->next;
          tmp=tmp->next;
	    }
	}
}

/* Функция сортировки по кол-ву финалов */
void finals_sorted(Head *p0,int sort)
{
	Node *p,*o,*tmp;
	int i,j;
	
	for (j=0;j<p0->cnt-1;j++){
		p=p0->first;
		tmp=p->next;
    	for(i=0;i<p0->cnt-1;i++)
    	{
          if (sort){
            if ((p->matches_goals_finals[2])<(tmp->matches_goals_finals[2])){
          		swap(p,tmp);
	  	    }
		  }
          else{
          	if ((p->matches_goals_finals[2])>(tmp->matches_goals_finals[2])){
          	 	swap(p,tmp);
		  	 }
		  }
          p=p->next;
          tmp=tmp->next;
	    }
	}
}

/* Функция сортировки по названию команды */
void team_sorted(Head *p0,int sort)
{
	Node *p,*o,*tmp;
	int i,j;
	
	for (j=0;j<p0->cnt-1;j++){
		p=p0->first;
		tmp=p->next;
    	for(i=0;i<p0->cnt-1;i++)
    	{
          if (sort){
            if (strcmp(p->team,tmp->team)>0){
          		swap(p,tmp);
	  	    }
		  }
          else{
          	if (strcmp(p->team,tmp->team)<0){
          	 	swap(p,tmp);
		  	 }
		  }
          p=p->next;
          tmp=tmp->next;
	    }
	}
}

/* Функция сортировки по названию страны */
void country_sorted(Head *p0,int sort)
{
	Node *p,*o,*tmp;
	int i,j;
	
	for (j=0;j<p0->cnt-1;j++){
		p=p0->first;
		tmp=p->next;
    	for(i=0;i<p0->cnt-1;i++)
    	{
          if (sort){
            if (strcmp(p->country,tmp->country)>0){
          		swap(p,tmp);
	  	    }
		  }
          else{
          	if (strcmp(p->country,tmp->country)<0){
          	 	swap(p,tmp);
		  	 }
		  }
          p=p->next;
          tmp=tmp->next;
	    }
	}
}

void Kind_sorted(Head *p,int sort, void (*funcName)(Head*,int))
{
    funcName(p,sort);
}

/* Меню выбора */
void card_sorted(Head *p0,int option){
	int sort,check;
	void (*kind[7])(Head*,int);
	check=1;
	kind[0] = number_of_titles_sorted;
	kind[1] = team_sorted;
	kind[2] = country_sorted;
	kind[3] = year_sorted;
	kind[4] = matches_sorted;
	kind[5] = goals_sorted;
	kind[6] = finals_sorted;
    printf("Enter '0' if you want to sort in ascending order, '1' if you want to sort in descending order: ");
    while (check){
        sort=safe_scanf();
    	if ((sort==0)||(sort==1)){
    		check=0;
		}
		else puts("Incorrect input!Try again!");
	}
   	Kind_sorted(p0,sort,kind[option]);
}
