#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128

struct LNode
{
    char  *word;  /* data area */
    struct LNode *prev; /* link to previous node */
    struct LNode *next; /* link to next node */
};

struct LHead {
    struct LNode *first;
    struct LNode *last;
};

typedef struct LHead Head;
typedef struct LNode Node; /* datatype for pointer to node */

Head *make_head() /* Создание головы списка */
{
    Head *ph=NULL;

    ph=(Head*)malloc(sizeof(Head));
    if(ph)
    {
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}

Node *create_node2(char *new_word, int slen) /*Создание элемента списка */
{
   Node *new_node=NULL;
   char *someword=NULL;

    new_node = (Node*)malloc(sizeof(Node));
    someword=(char*)malloc((slen+1)*sizeof(char));
    if(new_node&&someword)
    {
        strcpy(someword,new_word);
        new_node->word=someword;
        new_node->prev = NULL;  
        new_node->next = NULL;
    }
    return new_node;  /* return of node address */
}

void add_first2(Head *my_head, Node *new_node) /* Добавление элемента в начало */
{
    my_head->first = new_node;
    my_head->last = new_node;
}

void add_last2(Head *my_head, Node *new_node, Node *prev_node) /* Добавление элемента в конец */
{
    if(my_head&&new_node&&prev_node)
    {
        prev_node->next=new_node;
        new_node->prev=prev_node;
        my_head->last=new_node;
    }
}

void insert_after2(Head *my_head, Node *new_node, Node *current_node) /* Вставка элемента после заданного */
{
    int n;
    if(my_head&&new_node&&current_node)
    {
        if(current_node->next==NULL)
        {
            current_node->next=new_node;
            new_node->prev=current_node;
            my_head->last=new_node;
        }
        else
        {
            new_node->next = current_node->next;
            current_node->next=new_node;
            new_node->prev=current_node;
        }
    }
}

Node *node_fill(Head *p0,int num,FILE *df){  /* Заполнение списка */
    Node *p,*p1,*my_node=NULL;
    char my_word[MAXLEN];
    int slen,t;
	t=1;
    while((num>0)||(t))
    {
        fgets(my_word,MAXLEN,df);
        slen=strlen(my_word);
        my_word[slen-1]='\0';
        
		if(t){
			t=0;
			p1=create_node2(my_word,slen);
    		add_first2(p0,p1);
    		p=p0->first;
		}
		else
        {
         	my_node=create_node2(my_word,slen);
            add_last2(p0, my_node, p);
            p=p0->last;
        }
        num--;
    }
    return p;
}

void print_node(Head *p0){  /* Вывод списка */
	Node *p;
	p=p0->first;
    while(p!=NULL)
    {
        printf("%s\n",p->word);
        p=p->next;
    }
}

void add_node(Head *p0,Node *p){ /*Добавление элемента списка */
	Node *r=NULL;
	char word1[MAXLEN],word2[MAXLEN];
	int str2,str2_1;
	puts("Enter value of the team field");
	fgets(word1,MAXLEN,stdin);
    puts("Enter team");
    fgets(word2,MAXLEN,stdin);
    str2=strlen(word2);
    r=create_node2(word2,str2);
    str2_1=slens(r->word);
    if ((strncmp(word2,word1,str2_1)==0)){
	 		p=p0->first;
		    insert_before2(p0,r,p);
    }
    else add_last2(p0,r,p);
}

void clean_node(Head *p0){ /* Очистка памяти списка */
	Node *p,*p1;
	p=p0->first;
    while(p!=NULL)
    {
        p1=p->next;
        free(p);
        p=p1;
    }
    free(p0);
}

