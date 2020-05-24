#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#define MAXLEN 128

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

void print_header()
{
    printf("|%3s |%20s|%20s|%4s|%6s|%4s|     %7s     |\n","Cup","Team",
	"Country","Year","Budget","Capacity","average");
    printf("_______________________________________________________________________________________\n");
}

void struct_out(champions *ch)
{
    printf("|%3d |%20s|%20s|%d|%5.1f |%5.3f  |%5.2f|%5.2f|%5.2f|\n",
        ch->number_of_titles,ch->team,ch->country,ch->year,ch->budget,ch->capacity,
		ch->average[0],ch->average[1],ch->average[2]);
}

champions *struct_fill(char **str,Node *p)
{
    champions *str0=NULL;

    str0=(champions*)malloc(sizeof(champions));
    if(str0!=NULL)
    {
    	str0->number_of_titles=atoi(str[0]);
    	str0->team=p->word;
        str0->country=str[2];
        str0->year=atoi(str[3]);
        str0->budget=atof(str[4]);
        str0->capacity=atof(str[5]);
        str0->average=(float*)malloc(3*sizeof(float));
        str0->average[0]=atof(str[6]);
        str0->average[1]=atof(str[7]);
        str0->average[2]=atof(str[8]);
    }
    return str0;
}

void print_struct(champions **ch,int lim){
	int i;
	print_header();
	for (i=0;i<lim;i++) {
		if (ch[i]!=NULL) struct_out(ch[i]);
	}	
}

champions **fill(int n,FILE *df,Head *p0){
	int i,count,slen;
	char **s2=NULL,sep;
    char s1[MAXLEN];
    Node *p;
	champions **ch;
	p=p0->first;
	sep=';';
    ch=(champions**)malloc(n*sizeof(champions*));
    if(ch!=NULL)
    {
    for(i=0,count=0;i<n;i++,count++)
    {
        fgets(s1,MAXLEN,df);
        slen=slens(s1);
        s2=simple_split(s1,slen,sep);
        if(s2!=NULL)
        {
            ch[i]=struct_fill(s2,p);
            p=p->next;
	    }
    }
	}
    else puts("No memory allocation!");
	return ch;	
}
