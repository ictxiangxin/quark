#include "boot.h"

.file "boot.S"
.text
.code16
.global _start

_start:

start:

    /* flat memory mode */
    ljmp    $0x0, $BOOT_BASE + relocate

relocate:

    /* in danger */
    cli

    xorw    %ax, %ax
    movw    %ax, %ss
    movw    %ax, %ds
    movw    %ax, %es
    movw    $BOOT_BASE, %sp

    /* safe now */
    sti

    /* clean screen */
    movw    $0x3, %ax
    int     $0x10
    movw    $0x600, %ax
    movw    $0x700, %bx
    xorw    %cx, %cx
    movw    $0x184f, %dx
    int     $0x10
    xorw    %dx, %dx
    xorb    %bh, %bh
    movb    0x2, %ah
    int     $0x1

    call    print
    .asciz  "quark"
    jmp     .

/* inline function: print */
#include <print.S>
