#include "../include/vga.h"

#if defined(__linux__)
#error "Cross-Compiler not found"
#endif

void kernel_main()
{
    vga_initialize();

    const char *output_scr_buff = "fuck you kernel";

    vga_print(output_scr_buff, VGA_COLOR_RED, VGA_COLOR_WHITE);
}
