; Multiboot header constants
; MULTIBOOT_HEADER_MAGIC equ 0x1BADB002
; MULTIBOOT_HEADER_FLAGS equ 0x0
; MULTIBOOT_HEADER_CHECKSUM equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

; section .multiboot
; align 4
;    dd MULTIBOOT_HEADER_MAGIC
;    dd MULTIBOOT_HEADER_FLAGS
;    dd MULTIBOOT_HEADER_CHECKSUM

; section .text
; global _start
; _start:
    ; Call your kernel main function
;    extern kernel_main
;    call kernel_main

    ; Infinite loop to halt the CPU
;    cli
;    hlt
;    jmp $

; src/boot.asm
section .multiboot
align 4
    dd 0x1BADB002            ; Magic number
    dd 0x00000003            ; Flags (align modules + memory map)
    dd -(0x1BADB002 + 0x03)  ; Checksum

section .text
global _start
_start:
    extern kernel_main
    call kernel_main
    cli
    hlt
    jmp $
