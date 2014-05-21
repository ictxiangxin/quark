#ifndef _PROTECT_H_
#define _PROTECT_H_

/* descriptor attribute */
#define DA_CD_R           0x0000
#define DA_CD_RA          0x0001
#define DA_CD_RW          0x0002
#define DA_CD_RWA         0x0003
#define DA_CD_RE          0x0004
#define DA_CD_REA         0x0005
#define DA_CD_RWE         0x0006
#define DA_CD_RWEA        0x0007
#define DA_CD_X           0x0008
#define DA_CD_XA          0x0009
#define DA_CD_XR          0x000a
#define DA_CD_XRA         0x000b
#define DA_CD_XC          0x000c
#define DA_CD_XCA         0x000d
#define DA_CD_XRC         0x000e
#define DA_CD_XRCA        0x000f
#define DA_SG_16TSS_A     0x0001
#define DA_SG_LDT         0x0002
#define DA_SG_16TSS_B     0x0003
#define DA_SG_16CALL      0x0004
#define DA_SG_TASK        0x0005
#define DA_SG_16INTERRUPT 0x0006
#define DA_SG_16TRAP      0x0007
#define DA_SG_32TSS_A     0x0009
#define DA_SG_32TSS_B     0x000b
#define DA_SG_32CALL      0x000c
#define DA_SG_32INTERRUPT 0x000e
#define DA_SG_32TRAP      0x000f
#define DA_DPL_0          0x0000
#define DA_DPL_1          0x0020
#define DA_DPL_2          0x0040
#define DA_DPL_3          0x0060
#define DA_P              0x0080
#define DA_NP             0x0000
#define DA_CD             0x0010
#define DA_SG             0x0000
#define DA_G_1B           0x0000
#define DA_G_4KB          0x8000
#define DA_32BIT          0x4000
#define DA_16BIT          0x0000
#define DA_4GB            0x4000
#define DA_64KB           0x0000
#define DA_ESP            0x4000
#define DA_SP             0x0000

#ifndef _ASSEMBLY_
typedef struct segment_descriptor_t
{
    u16 segment_limit_15_0;
    u16 segment_base_15_0;
    u8  segment_base_23_16;
    u8  segment_attribute_low;
    u8  segment_attribute_high;
    u8  segment_base_31_24;
} SEGMENT_DESCRIPTOR;

typedef struct gate_descriptor_t
{
    u16 gate_offset_15_0;
    u16 gate_selector;
    u16 gate_attribute;
    u16 gate_offset_31_16;
} GATE_DESCRIPTOR;

typedef struct idtr_t
{
    u16 idt_limit;
    u32 idt_base;
} IDTR;

void i_lidt(IDTR* idtr);
#endif

#endif
