#include "../include/vga.h"

volatile unsigned short *vga;

void vga_initialize(void)
{
        vga = (unsigned short*)VGA_START_ADDR;
}

void vga_print(const char *output_scr_buff, vga_color bg_color, vga_color txt_color)
{
        color_t color_attr = vga_combine_color(bg_color, txt_color);

        for (int i = 0; output_scr_buff[i]; i++)
        {
                vga[i] = (color_attr << 8) | (color_t)output_scr_buff[i];
        }
}
