#ifndef __LOW_LEVEL_H__
#define __LOW_LEVEL_H__

#include "protected_mode.h"

static inline void lidt(u32 base, u16 limit)
{
    IDTR idtr;
    idtr.idt_base = base;
    idtr.idt_limit = limit;
    __asm__ ("lidt (%0)" : : "p"(&idtr));
}

static inline u8 inb(u16 port)
{
    u8 result;
    __asm__ __volatile__ ("inb %1, %0" : "=a"(result) : "Nd"(port));
}

static inline void outb(u16 port, u8 data)
{
    __asm__ __volatile__ ("outb %0, %1" : : "a"(data), "Nd"(port));
}

#endif
