BITS 16
ORG 0x7C00

start:
    cli           ; Clear interrupts
    mov ax, 0x7C0 ; Setup stack
    mov ss, ax
    mov sp, 0x200

    mov ax, 0x7C0
    mov ds, ax

    call kernel_main ; Call the C kernel

    jmp $ ; Infinite loop

TIMES 510 - ($ - $$) db 0
DW 0xAA55 ; Boot signature