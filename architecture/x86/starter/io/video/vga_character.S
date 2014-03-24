#include <io/vga.h>

.file "vga_character.S"
.text
.code32

.global get_cursor_location
.global set_cursor_location
.global get_start_location
.global set_start_location
.global write_character

get_cursor_location:
    xorl    %ecx, %ecx
    movw    $CRTCR_ADDRESS, %dx
    movb    $CURSOR_HIGH, %al
    outb    %al, %dx
    movw    $CRTCR_DATA, %dx
    inb     %dx, %al
    movb    %al, %ch
    movw    $CRTCR_ADDRESS, %dx
    movb    $CURSOR_LOW, %al
    outb    %al, %dx
    movw    $CRTCR_DATA, %dx
    inb     %dx, %al
    movb    %al, %cl
    movl    %ecx, %eax
    ret

set_cursor_location:
    movl    0x4(%esp), %ecx
    movw    $CRTCR_ADDRESS, %dx
    movb    $CURSOR_LOW, %al
    outb    %al, %dx
    movb    %cl, %al
    movw    $CRTCR_DATA, %dx
    outb    %al, %dx
    movw    $CRTCR_ADDRESS, %dx
    movb    $CURSOR_HIGH, %al
    outb    %al, %dx
    movb    %ch, %al
    movw    $CRTCR_DATA, %dx
    outb    %al, %dx
    ret

get_start_location:
    xorl    %ecx, %ecx
    movw    $CRTCR_ADDRESS, %dx
    movb    $START_LOW, %al
    outb    %al, %dx
    movw    $CRTCR_DATA, %dx
    inb     %dx, %al
    movb    %al, %cl
    movw    $CRTCR_ADDRESS, %dx
    movb    $START_HIGH, %al
    outb    %al, %dx
    movw    $CRTCR_DATA, %dx
    inb     %dx, %al
    movb    %al, %ch
    movl    %ecx, %eax
    ret

set_start_location:
    movl    0x4(%esp), %ecx
    movw    $CRTCR_ADDRESS, %dx
    movb    $START_LOW, %al
    outb    %al, %dx
    movb    %cl, %al
    movw    $CRTCR_DATA, %dx
    outb    %al, %dx
    movw    $CRTCR_ADDRESS, %dx
    movb    $START_HIGH, %al
    outb    %al, %dx
    movb    %ch, %al
    movw    $CRTCR_DATA, %dx
    outb    %al, %dx
    ret

write_character:
    movw    0x4(%esp), %ax
    movl    0x8(%esp), %edx
    shll    $0x1, %edx
    addl    $VGA_CHARACTER_BASE, %edx
    movw    %ax, (%edx)
    ret
