; src/gdt_flush.asm
global gdt_flush

gdt_flush:
    mov eax, [esp+4]  ; Get pointer to GDT structure
    lgdt [eax]        ; Load the GDT
    
    ; Reload data segment registers
    mov ax, 0x10      ; Kernel data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    ; Far jump to reload CS
    jmp 0x08:.flush
.flush:
    ret
