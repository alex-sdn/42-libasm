section .text
    global ft_strdup    ; (*src = rdi)
    extern ft_strlen
    extern ft_strcpy
    extern malloc

ft_strdup:
    call ft_strlen          ; returns len in rax

    push rdi                ; save src before malloc
    inc rax                 ; alloc len+1
    mov rdi, rax            ; malloc will alloc rdi bytes
    call malloc wrt ..plt   ; will return pointer in rax

    mov rdi, rax            ; dest in rdi
    pop rsi                 ; src in rsi

    call ft_strcpy

    ret
