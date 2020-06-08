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

int safe_scanf();/* Безопасный ввод */
Head *make_head();/* Создание головы */
void add_first(Head *my_head);/* Добавление элемента картотеки в начало(ручной ввод) */
void add_first2(Head *my_head, Node *new_node);/* Добавление элемента картотеки в начало(ввод из файла) */
void add_last(Head *my_head,Node *prev_node);/* Добавление элемента картотеки в конец(ручной ввод) */
void add_last2(Head *my_head, Node *new_node, Node *prev_node);/* Добавление элемента картотеки в конец(ввод из файла) */
void print_node2(Head *p0);/* Вывод картотеки на экран */
//void clean_node(Head *p0);/*Очитска картотеки */
int number_of_structures(FILE *df);/* Подсчет кол-ва строк в файле */
int slens(char *s1);/* Длина строки */
Node *create_node_enter();/* Ввод полей элемента картотеки(с клавиатуры) */
Node *create_node2(char **str);/* Ввод полей элемента картотеки(из файла) */
void node_fill2(Head *p0,FILE *df,int n);/* Заполнение картотеки из файла */
void delete_card(Head *p0,int n);/* Удаление карточки */
void ClearStringArray(char **str, int n);
char **simple_split(char *str, int length, char sep);
void print_header();/* Печать названий полей картотеки */
void number_of_titles_edit(Node *p);/* Изменение кол-ва титулов */
void team_edit(Node *p);/* Изменение названия команды */
void country_edit(Node *p);/* Изменение названия страны */
void year_edit(Node *p);/* Изменение года основания */
void budget_edit(Node *p);/* Изменение бюджета команды */
void capacity_edit(Node *p);/* Изменение вместительности стадиона */
void matches_edit(Node *p);/* Изменение кол-ва матчей */
void goals_edit(Node *p);/* Изменение кол-ва голов */
void finals_edit(Node *p);/* Изменение кол-ва финалов */
void Kind_edit(Node *p, void (*funcName)(Node*));
void edit_card(Head *p0,int num,int option);/* Меню выбора */
void number_of_titles_search(Head *p0);/* Поиск по кол-ву титулов */
void team_search(Head *p0);/* Поиск по названию команды */
void country_search(Head *p0);/* Поиск по названию страны */
void year_search(Head *p0);/* Поиск по году основания */
void matches_search(Head *p0);/* Поиск по кол-ву матчей */
void goals_search(Head *p0);/* Поиск по кол-ву голов */
void finals_search(Head *p0);/* Поиск по кол-ву финалов */
void Kind_search(Head *p, void (*funcName)(Head*));
void card_search(Head *p0, int option);/* Меню выбора */
void swap(Node *tmp, Node *a);/* Функция для обмена элементами */
void number_of_titles_sorted(Head *p0,int sort);/* Функция сортировки по кол-ву титулов */
void year_sorted(Head *p0,int sort);/* Функция сортировки по году основания */
void matches_sorted(Head *p0,int sort);/* Функция сортировки по кол-ву матчей */
void goals_sorted(Head *p0,int sort);/* Функция сортировки по кол-ву голов */
void finals_sorted(Head *p0,int sort);/* Функция сортировки по кол-ву финалов */
void team_sorted(Head *p0,int sort);/* Функция сортировки по названию команды */
void country_sorted(Head *p0,int sort);/* Функция сортировки по названию страны */
void Kind_sorted(Head *p,int sort, void (*funcName)(Head*,int));
void card_sorted(Head *p0,int option);/* Меню выбора */
void clean_node(Node *p);
void clean_head(Head *p0);
void clean_nodes(Head *p0);
#endif
