#include <boot.h>

#define PRINT(string) call print; .asciz string;

.file "boot.S"
.text
.code16

start:

    /* relocate boot code */
    ljmp    $BOOT_BASE, $(BOOT_OFFSET + relocate)

    boot_device_base:   .long 0x0
    boot_device_number: .byte 0x80

relocate:

    /* in danger */
    cli

    /* set environment */
    movw    %cs, %ax
    movw    %ax, %ss
    movw    %ax, %ds
    movw    %ax, %es
    movw    $BOOT_OFFSET, %sp

    /* safe now */
    sti

    /* clean screen */
#include <clean_screen.S>

    PRINT("quark\r\n")

/* load starter */
    movw    $0x3, %di /* try 3 times */
load_starter:
    movw    $STARTER_DEVICE_OFFSET, %ax
    xorw    %bx, %bx
    xorw    %cx, %cx
    xorw    %dx, %dx
    addw    (boot_device_base), %ax
    adcw    (boot_device_base + 0x2), %bx
    adcw    $0x0, %cx
    movw    %ax, (BlockNumberLow)
    movw    %bx, (BlockNumberLow + 0x2)
    movw    %cx, (BlockNumberHigh)
    movw    %dx, (BlockNumberHigh + 0x2)
    movb    (boot_device_number), %dl
    movb    $0x42, %ah
    movw    $DAP, %si
    int     $0x13
    jnc     load_success
    cmpb    $0x80, %ah /* time out ? */
    je      load_error
    decw    %di
    jl      load_error
    xorb    %ah, %ah
    int     $0x13
    jnc     load_starter
    jmp     load_error

/* success and run starter */
load_success:
    ljmp    $STARTER_BASE, $STARTER_OFFSET

/* print the error code returned by int 0x13 */
load_error:
    mov     $(error_number + 0x3), %si
print_number:
    movb    %ah, %al
    andb    $0xf, %al
    cmpb    $0xa, %al
    jb      print_digit
    addb    $0x7, %al
print_digit:
    addb    %al, (%si)
    decw    %si
    movb    $0x4, %cl
    shrb    %cl, %ah
    jnz     print_number
    call    print
    .ascii  "Load Starter Error: "
error_number:
    .asciz  "0x00\r\n"

/* need reboot computer */
boot_fail:
    PRINT("Boot Fail! Press Any Key To Reboot...")
    xorb    %ah, %ah
    int     $0x16
    PRINT("\r\n")
    int     $0x19

/* inline function: print */
#include <print.S>

/* Disk Address Packet */
DAP:  
    PacketSize:       .byte  0x10 /* this always is 16 bytes */
    Reserved:         .byte  0x0
    BlockCount:       .word  STARTER_SIZE
    BufferOffset:     .word  STARTER_OFFSET
    BufferSegment:    .word  STARTER_BASE
    BlockNumberLow:   .long  0x0
    BlockNumberHigh:  .long  0x0

