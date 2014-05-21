#include <type.h>
#include <argument.h>
#include <print.h>

PRIVATE void _print_signed_number(uint number, uint base);

PUBLIC void print(char *format, ...)
{
    va_list argument_pointer;
    va_start(argument_pointer, format);
    uint index = 0;
    for(;format[index] != '\0'; index++)
    {
        if(format[index] == '%')
        {
            index++;

            if(format[index] == 's')
            {
                uint _index = 0;
                char *string = va_argument(argument_pointer, char *);
                while(string[_index] != '\0')
                {
                    put_character(string[_index]);
                    _index++;
                }
                continue;
            }

            if(format[index] == 'c')
            {
                char character = va_argument(argument_pointer, char);
                put_character(character);
                continue;
            }

            if(format[index] == 'd')
            {
                int number = va_argument(argument_pointer, int);
                if(number < 0x0)
                {
                    put_character('-');
                    number = -number;
                }
                _print_signed_number(number, 0xa);
                continue;
            }

            if(format[index] == 'x')
            {
                int number = va_argument(argument_pointer, int);
                _print_signed_number(number, 0x10);
                continue;
            }

            if(format[index] == 'o')
            {
                int number = va_argument(argument_pointer, int);
                _print_signed_number(number, 0x8);
                continue;
            }
        }
        put_character(format[index]);
    }
}

PRIVATE void _print_signed_number(uint number, uint base)
{
    uint lower_number;
    if((lower_number = number / base) != 0x0)
    {
        _print_signed_number(lower_number, base);
    }
    if((number % base) > 9)
    {
        put_character('a' - 0xa + (number % base));
    }
    else
    {
        put_character('0' + (number % base));
    }
}

