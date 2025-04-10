; [bits 32]
global gdt_flush

; The function now takes the GDT pointer as a parameter
gdt_flush:
    mov eax, [esp+4]  ; Get the pointer to the GDT from stack
    lgdt [eax]        ; Load the new GDT pointer

    mov ax, 0x10      ; Offset to kernel data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush   ; Far jump to kernel code segment
.flush:
    ret
