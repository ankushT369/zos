#ifndef __VGA_H__
#define __VGA_H__

#include "types.h"

#define VGA_START_ADDR 0xB8000

extern volatile unsigned short *vga;

/* enumerator for all possible terminal color */
typedef enum vga_color 
{
        VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
} vga_color;

void vga_initialize(void);
void vga_print(const char*, vga_color, vga_color);

static inline color_t vga_combine_color(vga_color bgc, vga_color txtc)
{
    return (bgc << 4) | txtc;
}

#endif // __VGA_H__
