section .text
    global ft_strlen

ft_strlen:
    xor rax, rax            ; clears rax, same as "mov rax,0" but bit faster
.loop:
    cmp byte [rdi + rax], 0 ; cmp the byte with 0
    je  .return             ; jump if cmp was equal
    inc rax                 ; rax++
    jmp .loop               ; loop

.return:
    ret