#ifndef _PRINT_H_
#define _PRINT_H_

#define DEFAULT_CHARACTER_COLOR COLOR_LIGHTGRAY
#define SCREEN_BUFFER_SIZE 0x2000

PRIVATE void _put_character(u16 data);
PRIVATE void _refresh();
PRIVATE void _refresh_screen();

#endif
