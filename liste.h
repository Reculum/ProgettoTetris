
#ifndef CONSTANTI_LISTE
#define CONSTANTI_LISTE

struct lista_int {int val; lista_int* next;};
typedef lista_int* p_lista_int;

struct lista_char {char ch; lista_char* next; lista_char* previous;};
typedef lista_char* p_lista_char;

#endif