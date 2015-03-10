#include <type.h>
#include <protected_mode.h>
#include <low_level.h>
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
    lidt(IDT_BASE, IDT_LIMIT);
}
