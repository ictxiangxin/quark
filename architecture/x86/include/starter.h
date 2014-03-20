#ifndef _STARTER_H_
#define _STARTER_H_

.equ GDT_LIMIT, 0x1fff

.equ GDT_ADDRESS, 0x1000
.equ CORE_ADDRESS, 0x10000

.equ CODE_SELECTOR, 0x8
.equ DATA_SELECTOR, 0x10

/*
 * This macro will create a new segment descriptor in GDT.
 *
 * When use this macro, must protect ds register.
 * If use a group of this macros, just save ds at the first and restore it at the end.
 *
 * Here is the structure of segment descriptor:
 *
 * |---------------------------------------------------------------|
 * | Byte7 | Byte6 | Byte5 | Byte4 | Byte3 | Byte2 | Byte1 | Byte0 |
 * | 31..24|               |         23..0         |     15..0     |
 * | Base  |  Attribution  |         Base          |     Limit     |
 * |-------|---------------|---------------------------------------|
 *        /                 \
 * |-------------Byte6-------------|-------------Byte5-------------|
 * | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 * | G |D/B| 0 |AVL| Limit  19..16 | P |  DPL  | S |     TYPE      |
 * |---------------------------------------------------------------|
 */
.macro load_segment_descriptor number, base, limit, attribute
    /* go into flat address mode */
    xorw    %ax, %ax
    movw    %ax, %ds

    /* flat address mode */
    movw    $(\number), %di
    shlw    $0x3, %di
    add     $GDT_ADDRESS, %di

    /* temp space from stack */
    movw    %sp, %bp
    subw    $0x4, %bp

    /* load base */
    movl    $(\base), (%bp)
    movw    (%bp), %ax
    movw    %ax, 0x2(%di)
    movb    0x2(%bp), %al
    movb    %al, 0x4(%di)
    movb    0x3(%bp), %al
    movb    %al, 0x7(%di)

    /* load limit and attribute */
    movl    $(\limit), (%bp)
    movw    (%bp), %ax
    movw    %ax, (%di)
    xorw    %ax, %ax
    movb    0x2(%bp), %ah
    andb    $0xf, %ah
    orw     $(\attribute), %ax
    movw    %ax, 0x5(%di)
.endm

#endif
