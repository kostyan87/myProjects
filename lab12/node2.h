#ifndef NODE2_H_INCLUDED
#define NODE2_H_INCLUDED

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

Head *make_head();
Node *create_node2(char *new_word, int slen);
void add_first2(Head *my_head, Node *new_node);
void add_last2(Head *my_head, Node *new_node, Node *prev_node);
void insert_after2(Head *my_head, Node *new_node, Node *current_node);
void insert_before2(Head *my_head, Node *new_node, Node *current_node);
Node *node_fill(Head *p0,int num,FILE *df);
void print_node(Head *p0);
void add_node(Head *p0,Node *p);
void clean_node(Head *p0);
int number_of_structures(FILE *df);
int slens(char *s1);
void clean_node2(Head *p0,int t);
void bubble_sort(int *n,int t);
int *fill_mass(int *n,int t);
void node_fill2(Head *p0,Head *new_node,int *n,int len);
void print_node2(Head *p0,int len);
#endif
