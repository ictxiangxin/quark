#include "type.h"
#include "protect.h"

PUBLIC void set_segment_descriptor(SEGMENT_DESCRIPTOR *segment_descriptor, u32 base, u32 limit, u16 attribute)
{
    segment_descriptor->segment_limit_15_0     = (u16)(limit & 0xffff);
    segment_descriptor->segment_base_15_0      = (u16)(base & 0xffff);
    segment_descriptor->segment_base_23_16     = (u8)((base >> 0x10) & 0xff);
    segment_descriptor->segment_attribute_low  = (u8)(attribute);
    segment_descriptor->segment_attribute_high = (u8)((attribute >> 0x8) | (limit >> 0x10) & 0xf);
    segment_descriptor->segment_base_31_24     = (u8)((base >> 0x18) & 0xff);
}
