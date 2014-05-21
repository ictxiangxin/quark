#include <type.h>
#include <protect.h>
#include <video_character.h>
#include <starter/constant.h>

PRIVATE void initialize_idt();

PUBLIC void initialize()
{
    initialize_idt();
    initialize_video_character();
}

PRIVATE void initialize_idt()
{
    IDTR idtr;
    idtr.idt_limit = IDT_LIMIT;
    idtr.idt_base  = IDT_BASE;
    i_lidt(&idtr);
}
