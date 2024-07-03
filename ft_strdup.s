section .text
    global ft_strdup        ; (*src = rdi)
    extern ft_strlen
    extern ft_strcpy
    extern malloc
    extern __errno_location

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
    pop rdi                          ; clear the stack
    call  __errno_location wrt ..plt ; will set errno address in rax
    mov rbx, 12
    mov [rax], rbx                   ; malloc fail is ERRNO=12
    xor rax, rax                     ; return 0
    ret
