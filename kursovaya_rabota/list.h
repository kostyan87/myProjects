#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/* Структура картотеки */
struct LNode
{
	int   id;
    int number_of_titles;
    char *team;
    char *country;
    int year;
    float budget;
    float capacity;
    int *matches_goals_finals;
    struct LNode *prev;
    struct LNode *next;
};

/* Структура головы */
struct LHead {
	int cnt;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LHead Head;
typedef struct LNode Node;

Head *make_head();
void add_first(Head *my_head);
void add_first2(Head *my_head, Node *new_node);
void add_last(Head *my_head,Node *prev_node);
void add_last2(Head *my_head, Node *new_node, Node *prev_node);
void print_node2(Head *p0);
void clean_node(Head *p0);
int number_of_structures(FILE *df);
int slens(char *s1);
Node *create_node_enter();
Node *create_node2(char **str);
void node_fill2(Head *p0,FILE *df,int n);
void delete_card(Head *p0,int n);
void ClearStringArray(char **str, int n);
char **simple_split(char *str, int length, char sep);
void print_header();
void number_of_titles_edit(Node *p);
void team_edit(Node *p);
void country_edit(Node *p);
void year_edit(Node *p);
void budget_edit(Node *p);
void capacity_edit(Node *p);
void matches_edit(Node *p);
void goals_edit(Node *p);
void finals_edit(Node *p);
void Kind_edit(Node *p, void (*funcName)(Node*));
void edit_card(Head *p0,int num,int option);
void number_of_titles_search(Head *p0);
void team_search(Head *p0);
void country_search(Head *p0);
void year_search(Head *p0);
void matches_search(Head *p0);
void goals_search(Head *p0);
void finals_search(Head *p0);
void Kind_search(Head *p, void (*funcName)(Head*));
void card_search(Head *p0, int option);
void swap(Node *tmp, Node *a);
void number_of_titles_sorted(Head *p0,int sort);
void year_sorted(Head *p0,int sort);
void matches_sorted(Head *p0,int sort);
void goals_sorted(Head *p0,int sort);
void finals_sorted(Head *p0,int sort);
void team_sorted(Head *p0,int sort);
void country_sorted(Head *p0,int sort);
void Kind_sorted(Head *p,int sort, void (*funcName)(Head*,int));
void card_sorted(Head *p0,int option);
#endif
