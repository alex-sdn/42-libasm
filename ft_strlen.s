section .text
    global ft_strlen

ft_strlen:
    xor rax, rax            ; clears rax
loop:
    cmp byte [rdi + rax], 0 ; cmp the byte with 0
    je  end                 ; jump if cmp was equal
    inc rax                 ; rax++
    jmp loop                ; loop

end:
    ret                     ; returns rax