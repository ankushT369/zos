#include "../include/vga.h"
#include "../include/gdt.h"

#if defined(__linux__)
#error "Cross-Compiler not found"
#endif

void kernel_main() {
    vga_initialize();
    //init_gdt();  // Initialize GDT first
    
    const char *msg = "New GDT loaded successfully!";
    vga_print(msg, VGA_COLOR_GREEN, VGA_COLOR_BLACK);
    
    // Rest of your kernel code...
}
