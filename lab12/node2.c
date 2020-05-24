#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128

struct LNode
{
	int   id;
    char *word;
    struct LNode *prev;
    struct LNode *next;
};

struct LHead {
	int cnt;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LHead Head;
typedef struct LNode Node;

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

Node *create_node2(char *new_word, int slen)
{
   Node *new_node=NULL;
   char *someword=NULL;

    new_node = (Node*)malloc(sizeof(Node));
    someword=(char*)malloc((slen+1)*sizeof(char));
    if(new_node&&someword)
    {
        strcpy(someword,new_word);
        new_node->id = 1;
        new_node->word=someword;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

void add_first2(Head *my_head, Node *new_node)
{
    my_head->first = new_node;
    my_head->last = new_node;
    my_head->cnt++;
}

void add_last2(Head *my_head, Node *new_node, Node *prev_node)
{
    int n;

    if(my_head&&new_node&&prev_node)
    {
    	n=my_head->cnt+1;
        prev_node->next=new_node;
        new_node->prev=prev_node;
        my_head->last=new_node;
        new_node->id=n;
        my_head->cnt=n;
    }
}

void insert_after2(Head *my_head, Node *new_node, Node *current_node)
{
    int n;
    if(my_head&&new_node&&current_node)
    {
    	n=my_head->cnt+1;
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
        new_node->id=n;
        my_head->cnt=n;
    }
}

void insert_before2(Head *my_head, Node *new_node, Node *current_node)
{
    Node *q=NULL;
    int n;

    if(my_head&&new_node&&current_node)
    {
        if(my_head->first==current_node)
        {
            new_node->next=current_node;
            current_node->prev=new_node;
            my_head->first=new_node;

        }
        else
        {
            q=current_node->prev;
            new_node->next=current_node;
            new_node->prev=q;
            q->next=new_node;
            current_node->prev=new_node;
        }
        n=my_head->cnt+1;
        new_node->id=n;
        my_head->cnt=n;
    }
}

Node *node_fill(Head *p0,int num,FILE *df){
    Node *p,*p1,*my_node=NULL;
    char my_word[MAXLEN];
    int slen,t,str1,str2,str2_1;
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

void print_node(Head *p0){
	Node *p;
	p=p0->first;
    while(p!=NULL)
    {
        printf("%d)%s\n",p->id,p->word);
        p=p->next;
    }
}

void add_node(Head *p0,Node *p){
	Node *r=NULL;
	char word1[MAXLEN],word2[MAXLEN];
	int str1,str2,str2_1;
	puts("Enter value of the team field");
	fgets(word1,MAXLEN,stdin);
    str1=strlen(word1);
    puts("Enter team");
    fgets(word2,MAXLEN,stdin);
	str2=strlen(word2);
    r=create_node2(word2,str2);
    str2_1=slens(r->word);
    str2++;
    if ((strncmp(word2,word1,str2_1)==0)){
	 		p=p0->first;
		    insert_before2(p0,r,p);
    }
    else add_last2(p0,r,p);
}

void clean_node(Head *p0){
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

int number_of_structures(FILE *df){
	int n=0;
	char s1[MAXLEN];
    while((fgets(s1,MAXLEN,df))!=NULL) n++;
    rewind(df);
    return n;
}

int slens(char *s1){
	int slen;
	slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);
    return slen;
}

void clean_node2(Head *p0,int t){
	Node *p,*p1;
	int i;
	p=p0->first;
    for(i=0;i<t;i++)
    {
        p1=p->next;
        free(p);
        p=p1;
    }
    free(p0);
}

void bubble_sort(int *n,int t){
	int i,j,o;
	for (j=0;j<t-1;j++){
		for (i=0;i<t-1;i++){
			if (n[i]>n[i+1]){
				o=n[i+1];
				n[i+1]=n[i];
				n[i]=o;
			}
		}
	}
}

int *fill_mass(int *n,int t){
	int i,c,j;
 	if (t>0){
  	   puts("Enter numbers of elements(1-12):");
  	   for (i=0;i<t;i++){
	  	  printf("%d)",i+1);
	  	  scanf("%d",&c);
	  	  for (j=0;j<i;j++){
	  	  	if (n[j]==c) c=0;
			}
	  	  if ((c<1)||(c>12)){
 	  	  	 puts("invalid number, enter new:");
	 	 	 i--;
   		  }
    	  else n[i]=c;
       } 
	}
	return n;
}

void node_fill2(Head *p0,Head *new_node,int *n,int len){
    Node *p,*p1,*p2,*my_node=NULL;
    char my_word[MAXLEN];
    int i,slen,t,str1,str2,str2_1;
	t=1;
	i=0;
	p2=p0->first;
    while((t)||(i<len))
    {
		if(t){
			if (n[i]==p2->id){
				t=0;
				p1=create_node2(p2->word,slen);
    			add_first2(new_node,p1);
    			p=new_node->first;
    			i++;
			}
			p2=p2->next;
		}
		else
        {
        	if (n[i]==p2->id){
         	    my_node=create_node2(p2->word,slen);
                add_last2(new_node, my_node, p);
                p=new_node->last;
                i++;
		    }
                p2=p2->next;
        }
        if (i==len) {
        	new_node->last->next=new_node->first;
        	new_node->first->prev=new_node->last;
		}
    }
}

void print_node2(Head *p0,int len){
	Node *p;
	int i;
	p=p0->first;
    for(i=0;i<len;i++)
    {
        printf("%d)%s\n",p->id,p->word);
        p=p->next;
    }
}
