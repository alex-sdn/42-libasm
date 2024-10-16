# Libasm
Library of libc functions recreated in 64 bits ASM. The assembly functions will have the same behavior as the C version (including error handling and setting the errno variable).
### Functions
- strlen
- strcpy
- strcmp
- write
- read
- strdup

Makefile will compile the library and the main.c will test each function and compare it with the original.
