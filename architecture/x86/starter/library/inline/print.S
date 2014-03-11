print:
    popw    %si
    cld
print_next:
    lodsb
    testb   %al, %al
    jz      print_done
    movb    $0xe, %ah
    movw    $0x1, %bx
    int     $0x10
    jmp     print_next
print_done:
    jmp     *%si
