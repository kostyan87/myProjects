#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

void menu(Head p0);/* Меню */
void print_menu();/* Печать меню */
void menu_edit();/* Печать меню для добавления элементов */
void menu_search();/* Печать меню для поиска элементов */
void menu_sort();/* Печать меню для сортировки элементов */
void sub_menu_add(Head *p0,int c);/* Дополнительное меню для добавления элемента в картотеку */
void sub_menu_edit(Head *p0,int c);/* Дополнительное меню для редактирования элемента в картотеке */
void sub_menu_delete(Head *p0,int c);/* Дополнительное меню для удаления элемента из картотеки */
void sub_menu_output(Head *p0);/* Дополнительное меню для вывода картотеки */
void sub_menu_search(Head *p0,int c);/* Дополнительное меню для поиска элемента в картотеке */
void sub_menu_sort(Head *p0,int c);/* Дополнительное меню для сортировки элементов в картотеке */
void print_reference();/* Печать справки */
void save_file(Head *p0);/* Запись картотеки в файл */
#endif
