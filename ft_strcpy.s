section .text
    global ft_strcpy ; (*dest = rdi, *src = rsi)

ft_strcpy:
    xor rcx, rcx        ; clear count register
.loop:
    mov al, [rsi + rcx] ; move char of src in al
    mov [rdi + rcx], al ; move al in dest
    cmp al, 0           ; compare char with null byte
    je  .end            ; if equal -> over
    inc rcx             ; rcx++
    jmp .loop

.end:
    mov rax, rdi    ; returns address of dest string
    ret