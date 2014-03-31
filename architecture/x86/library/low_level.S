.file "low_level.S"
.text
.code32

.global i_lidt

i_lidt:
    movl    0x4(%esp), %eax
    movw    (%eax), %dx
    movw    %dx, (idtr)
    movl    0x2(%eax), %edx
    movl    %edx, (idtr + 0x2)
    lidt    idtr
    ret
idtr:
    .word 0x0
    .long 0x0
