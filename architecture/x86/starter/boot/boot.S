#include <boot.h>

.file "boot.S"
.text
.code16
.globl _start

_start:

    /* flat memory mode */
    ljmp    $0, $relocate + BOOT_BASE

relocate:

    /* in danger */
    cli

    xorw    %ax, %ax
    movw    %ax, %ss
    movw    %ax, %ds
    movw    %ax, %es
    movw    BOOT_BASE, %sp

    /* safe now */
    sti
