#include <type.h>
#include <protected_mode.h>
#include <low_level.h>
#include <io/video_character.h>
#include <starter/constant.h>
#include <i8259a.h>

PRIVATE void initialize_idt();
PRIVATE void initialize_i8259a();

PUBLIC void initialize()
{
    initialize_idt();
    initialize_i8259a();
    initialize_video_character();
}

PRIVATE void initialize_idt()
{
    lidt(IDT_BASE, IDT_LIMIT);
}

PRIVATE void initialize_i8259a()
{
    outb(MASTER_I8259A_ICW1, 0x11); /* ICW1 to master i8259a, need ICW4 */
    outb(SLAVE_I8259A_ICW1,  0x11); /* ICW1 to slave i8259a, need ICW4 */
    outb(MASTER_I8259A,      0x20); /* ICW2 to master i8259a, int 0x20 ~ 0x27 mapping IRQ0 ~ IRQ7 */
    outb(SLAVE_I8259A,       0x28); /* ICW2 to slave i8259a, int 0x28 ~ 0x2f mapping IRQ8 ~ IRQ15 */
    outb(MASTER_I8259A,      0x04); /* ICW3 to master i8259a, master i8259a IRQ2 link slave i8259a */
    outb(SLAVE_I8259A,       0x02); /* ICW3 to slave i8259a, link to master 8259a IRQ2 */
    outb(MASTER_I8259A,      0x03); /* ICW4 to master i8259a, 80x86 mode and auto EOI */
    outb(SLAVE_I8259A,       0x03); /* ICW4 to slave i8259a, 80x86 mode and auto EOI */
    outb(MASTER_I8259A,      0xff); /* Mask all interrupts of master i8259a */
    outb(SLAVE_I8259A,       0xff); /* Mask all interrupts of slave i8259a */
}
