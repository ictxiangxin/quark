#include <boot.h>

.file "real.S"
.text
.code16

start:
    /* in danger */
    cli

    movw    %cs, %ax
    movw    %ax, %ss
    movw    %ax, %ds
    movw    %ax, %es
    movw    $STARTER_OFFSET, %sp

    /* safe now */
    sti

    call    print
    .asciz  "starter\r\n"
    jmp     .

#include <print.S>
