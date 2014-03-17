clean_screen:
    movw    $0x3, %ax
    int     $0x10
    movw    $0x600, %ax
    movw    $0x700, %bx
    xorw    %cx, %cx
    movw    $0x184f, %dx
    int     $0x10
    xorw    %dx, %dx
    xorb    %bh, %bh
    movb    0x2, %ah
    int     $0x1