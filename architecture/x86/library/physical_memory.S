.file "physical_memory.S"
.text
.code32

.global physical_memory_copy
.global physical_memory_fill

physical_memory_copy:
    pushl   %ebp
    movl    %esp, %ebp
    pushl   %edi
    pushl   %esi
    movl    0x8(%ebp), %esi
    movl    0xc(%ebp), %edi
    movl    0x10(%ebp), %ecx
    cld
    rep movsb
    popl    %esi
    popl    %edi
    popl    %ebp
    ret

physical_memory_fill:
    pushl   %ebp
    movl    %esp, %ebp
    pushl   %edi
    movl    0x8(%ebp), %edi
    movl    0xc(%ebp), %ecx
    movb    0x10(%ebp), %al
    cld
    rep stosb
    popl    %edi
    popl    %ebp
    ret
