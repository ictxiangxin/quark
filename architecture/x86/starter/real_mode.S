#include <boot.h>
#include <starter.h>
#include <protect.h>

#define PRINT(string) call print; .asciz string;

.file "real.S"
.text
.code16

start:
    /* in danger */
    cli

    /* set environment */
    movw    %cs, %ax
    movw    %ax, %ss
    movw    %ax, %ds
    movw    %ax, %es
    movw    $STARTER_OFFSET, %sp

    /* safe now */
    sti

    PRINT("starter\r\n")

    pushw   %ds /* save ds */

    /* execute segment descriptor */
    load_segment_descriptor 0x1, 0x0, 0xfffff, DA_CD_X  + DA_P + DA_CD + DA_32BIT + DA_G_4KB

    /* data segment descriptor */
    load_segment_descriptor 0x2, 0x0, 0xfffff, DA_CD_RW + DA_P + DA_CD + DA_32BIT + DA_G_4KB

    popw    %ds /* restore ds */

    /*
     * lgdt depend on ds and ss.
     * set ds and ss to right value.
     */
    movw    $STARTER_OFFSET, %ax
    shrw    $0x4, %ax
    movw    %cs, %bx
    addw    %bx, %ax
    movw    %ax, %ds
    movw    %ax, %ss

    /* load GDT */
    lgdt    GDTR

    /* close interrupt and open A20 */
    cli
    inb     $0x92, %al
    orb     $0x2, %al
    outb    %al, $0x92

    /* set cpu to protected mode */
    movl    %cr0, %eax
    orl     $0x1, %eax
    movl    %eax, %cr0

    /* go into protected mode */
    DATA32 ljmp $0x8, $protect

/* use to fill gdtr */
GDTR:
    GDTR_limit: .word 0x1fff
    GDTR_base:  .long GDT_ADDRESS

/* inline function: print */
#include <print.S>

/* protected mode */
.code32
protect:
    jmp .
