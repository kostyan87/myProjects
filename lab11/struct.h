#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct LNode
{
	int   id;
    char *word;
    struct LNode *prev; /* link to previous node */
    struct LNode *next; /* link to next node */
};

struct LHead {
	int cnt;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LHead Head;
typedef struct LNode Node; /* datatype for pointer to node */

struct champions{
        int number_of_titles;
        Node *team;
        char *country;
        int year;
        float budget;
        float capacity;
        float *average;
};

typedef struct champions champions;

char **simple_split(char *str, int length, char sep); /*Формирование массива строк*/
void ClearStringArray(char **str, int n); /*Очистка память строк массива*/
int slens(char *s1);
int number_of_structures(FILE *df);
void print_header();
void struct_out(champions *ch);
champions *struct_fill(char **str,Node *p);
void print_struct(champions **ch,int lim);
champions **fill(int n,FILE *df,Head *p0);
#endif
