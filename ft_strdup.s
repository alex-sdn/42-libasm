section .text
    global ft_strdup        ; (*src = rdi)
    extern ft_strlen
    extern ft_strcpy
    extern malloc

ft_strdup:
    call ft_strlen          ; returns len in rax

    push rdi                ; save src before malloc
    inc rax                 ; alloc len+1
    mov rdi, rax            ; malloc will alloc rdi bytes
    call malloc wrt ..plt   ; returns pointer in rax

    ; error mgmt
    test rax, rax           ; bitwise AND on rax
    jz  ret_error           ; if zero flag is set == null pointer

    mov rdi, rax            ; dest in rdi
    pop rsi                 ; src in rsi

    call ft_strcpy

    ret

ret_error:
    xor rax, rax
    ret
