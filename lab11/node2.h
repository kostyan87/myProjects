#ifndef NODE2_H_INCLUDED
#define NODE2_H_INCLUDED

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
#endif
