#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

int safe_scanf();
void menu(Head p0);
void print_menu();
void menu_edit();
void menu_search();
void menu_sort();
void sub_menu_add(Head *p0,int c);
void sub_menu_edit(Head *p0,int c);
void sub_menu_delete(Head *p0,int c);
void sub_menu_output(Head *p0);
void sub_menu_search(Head *p0,int c);
void sub_menu_sort(Head *p0,int c);
void print_reference();
void save_file(Head *p0);
#endif
