#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

int _putchar(char c);
int print_char(int character);
int print_string(char *str);
int p_print(void);
int _printf(char *format, ...);
int handle_specifiers(va_list val, char ch, unsigned int *p_i);
void id_print(int n);
int int_len(int n);


#endif
