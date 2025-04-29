// include/gdt.h
#ifndef __GDT_H__
#define __GDT_H__

#include <stdint.h>

// GDT Entry Definition
struct gdt_entry {
        uint16_t limit_low;     // Lower 16 bits of limit
        uint16_t base_low;      // Lower 16 bits of base
        uint8_t  base_mid;      // Next 8 bits of base
        uint8_t  access;        // Access flags
        uint8_t  granularity;   // Limit high 4 bits + flags
        uint8_t  base_high;     // Last 8 bits of base
} __attribute__((packed));

// GDT Pointer Structure
struct gdt_ptr {
        uint16_t size;
        uint32_t offset;
} __attribute__((packed));

// Segment Selector Constants
#define KERNEL_CS 0x08
#define KERNEL_DS 0x10
#define USER_CS   0x18
#define USER_DS   0x20

// Access Byte Flags
#define GDT_ACCESS_PRESENT     (1 << 7)
#define GDT_ACCESS_RING0       (0 << 5)
#define GDT_ACCESS_RING3       (3 << 5)
#define GDT_ACCESS_CODE_SEG    (1 << 3)
#define GDT_ACCESS_DATA_SEG    (0 << 3)
#define GDT_ACCESS_READ_WRITE  (1 << 1)

// Granularity Flags
#define GDT_GRAN_4KB       (1 << 7)
#define GDT_GRAN_32BIT     (1 << 6)
#define GDT_GRAN_LONG_MODE (1 << 5)

void init_gdt();
extern void gdt_flush(uint32_t);

#endif // __GDT_H__
