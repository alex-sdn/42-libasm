section .text
    global ft_strcmp ; (*s1 = rdi, *s2 = rsi)

ft_strcmp:
    xor rcx, rcx        ; set count register at 0
.loop:
    mov al, [rdi + rcx] ; set current char in al
    mov bl, [rsi + rcx] ; _
    cmp al, bl          ; compare chars
    jne .not_equal      ; jump if not equal
    cmp al, 0           ; if equal and null byte -> over
    je  .equal
    inc rcx             ; rcx++
    jmp .loop

.not_equal:
    sub     al, bl      ; sub chars
    movsx   rax, al     ; mov sign extended (bc into larger register)
    ret                 ; returning diff, real function just +1 or -1 i think ?

.equal:
    xor rax, rax        ; if equal return 0
    ret