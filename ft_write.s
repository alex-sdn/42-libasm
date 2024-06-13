section .text
   global ft_write    ; (fd = rdi, *buf = rsi, count = rdx)
   extern __errno_location

ft_write:
   mov   rax, 1      ; move sys_write to rax
   syscall           ; system call write()
   cmp   rax, 0
   jge   .no_error   ; if rax >= 0 skip to .no_error

   neg   rax                        ; rax *= -1
   push  rax                        ; push value in rax to stack
   call  __errno_location wrt ..plt ; will set errno address in rax (wrt ..plt -> jsp mais necessaire sinon compile pas)
   mov   rbx, rax                   ; move errno address to rbx
   pop   rax                        ; retrieve error code from stack
   mov   [rbx], rax                 ; store error code in errno address
   mov   rax, -1                    ; set return value to -1

.no_error:
   ret               ; returns value in rax
   
