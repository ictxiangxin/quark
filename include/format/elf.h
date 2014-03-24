#ifndef _ELF_H_
#define _ELF_H_

#define ELF_MAGIC 0x464c457f

/* ELF 32bit */
#define ELF32_IDENTIFY_MAGIC      0x00
#define ELF32_IDENTIFY_CLASS      0x04
#define ELF32_IDENTIFY_DATA       0x05
#define ELF32_IDENTIFY_VERSION    0x06
#define ELF32_IDENTIFY_OSABI      0x07
#define ELF32_IDENTIFY_ABIVERSION 0x08
#define ELF32_IDENTIFY_PAD        0x09
#define ELF32_TYPE                0x10
#define ELF32_MACHINE             0x12
#define ELF32_VERSION             0x14
#define ELF32_ENTRY               0x18
#define ELF32_PROGRAM_TABLE       0x1c
#define ELF32_SECTION_TABLE       0x20
#define ELF32_FLAGS               0x24
#define ELF32_HEADER_SIZE         0x28
#define ELF32_PROGRAM_SIZE        0x2a
#define ELF32_PROGRAM_NUMBER      0x2c
#define ELF32_SECTION_SIZE        0x2e
#define ELF32_SECTION_NUMBER      0x30
#define ELF32_SECTION_INDEX       0x32

/* ELF 64bit */
#define ELF64_IDENTIFY_MAGIC      0x00
#define ELF64_IDENTIFY_CLASS      0x04
#define ELF64_IDENTIFY_DATA       0x05
#define ELF64_IDENTIFY_VERSION    0x06
#define ELF64_IDENTIFY_OSABI      0x07
#define ELF64_IDENTIFY_ABIVERSION 0x08
#define ELF64_IDENTIFY_PAD        0x09
#define ELF64_TYPE                0x10
#define ELF64_MACHINE             0x12
#define ELF64_VERSION             0x14
#define ELF64_ENTRY               0x18
#define ELF64_PROGRAM_TABLE       0x20
#define ELF64_SECTION_TABLE       0x28
#define ELF64_FLAGS               0x30
#define ELF64_HEADER_SIZE         0x34
#define ELF64_PROGRAM_SIZE        0x36
#define ELF64_PROGRAM_NUMBER      0x38
#define ELF64_SECTION_SIZE        0x3a
#define ELF64_SECTION_NUMBER      0x3c
#define ELF64_SECTION_INDEX       0x3e

/* ELF 32bit program header */
#define ELF32_PROGRAM_HEADER_TYPE             0x00
#define ELF32_PROGRAM_HEADER_OFFSET           0x04
#define ELF32_PROGRAM_HEADER_VIRTUAL_ADDRESS  0x08
#define ELF32_PROGRAM_HEADER_PHYSICAL_ADDRESS 0x0c
#define ELF32_PROGRAM_HEADER_FILE_SIZE        0x10
#define ELF32_PROGRAM_HEADER_MEMORY_SIZE      0x14
#define ELF32_PROGRAM_HEADER_FLAGS            0x18
#define ELF32_PROGRAM_HEADER_ALIGN            0x1c

/* ELF 64bit program header */
#define ELF64_PROGRAM_HEADER_TYPE             0x00
#define ELF64_PROGRAM_HEADER_FLAGS            0x04
#define ELF64_PROGRAM_HEADER_OFFSET           0x0c
#define ELF64_PROGRAM_HEADER_VIRTUAL_ADDRESS  0x14
#define ELF64_PROGRAM_HEADER_PHYSICAL_ADDRESS 0x1c
#define ELF64_PROGRAM_HEADER_FILE_SIZE        0x24
#define ELF64_PROGRAM_HEADER_MEMORY_SIZE      0x2c
#define ELF64_PROGRAM_HEADER_ALIGN            0x34

#endif