#include <constant.h>
#include <type.h>
#include <protect.h>
#include <memory.h>
#include <video_character.h>
#include <io/vga.h>
#include <io/print.h>
#include <io/bios_color.h>

PRIVATE uint _width;
PRIVATE uint _high;
PRIVATE uint _cursor_location;
PRIVATE uint _start_location;

PUBLIC void initialize_video_character()
{
    _cursor_location = get_cursor_location();
    _start_location = get_start_location();
    _width = 0x50;
    _high = 0x19;
}

PUBLIC void put_character(uchar c)
{
    u16 temp = DEFAULT_CHARACTER_COLOR;
    temp <<= 0x8;
    temp += c;
    _put_character(temp);
}

PRIVATE void _put_character(u16 data)
{
    if((data & 0xff) == '\n')
    {
        _cursor_location = (_cursor_location / _width + 0x1) * _width;
    }
    else
    {
        write_character(data, _cursor_location);
        _cursor_location++;
    }
    _refresh();
}

PRIVATE void _refresh()
{
    while(_cursor_location >= _start_location + _width * _high)
    {
        _start_location += _width;
    }
    if(_start_location + _width * _high >= SCREEN_BUFFER_SIZE - _width * _high)
    {
        _refresh_screen();
        _cursor_location -= _start_location;
        _start_location = 0x0;
    }
    set_cursor_location(_cursor_location);
    set_start_location(_start_location);
}

PRIVATE void _refresh_screen()
{
    physical_memory_copy((void*)(_start_location * 0x2 + VGA_CHARACTER_BASE), (void*)VGA_CHARACTER_BASE, _width * _high);
    physical_memory_fill((void*)(VGA_CHARACTER_BASE + _width * _high), (VGA_CHARACTER_BASE - _width * _high) * 0x2, 0x0);
}
