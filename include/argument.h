#ifndef _ARGUMENT_H_
#define _ARGUMENT_H_

typedef byte* va_list;

#define _INT_SIZE_OF(type) ((sizeof(type) + sizeof(int) - 0x1) & ~(sizeof(int) - 0x1) )

#define va_start(va_list_variable, variable) (va_list_variable = (va_list)&variable + _INT_SIZE_OF(variable))
#define va_argument(va_list_variable, type) (*(type *)((va_list_variable += _INT_SIZE_OF(type)) - _INT_SIZE_OF(type)))
#define va_end(va_list_variable) (va_list_variable = (va_list)0x0)

#endif

