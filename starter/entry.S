.file "entry.S"
.text
.code32

.global _start
.extern main

_start:
    call    main
    jmp     .
