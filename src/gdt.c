// src/gdt.c
#include "../include/gdt.h"

// Our GDT and GDT pointer
struct gdt_entry gdt[5];
struct gdt_ptr gp;

void set_gdt_entry(int index, uint32_t base, uint32_t limit, 
                   uint8_t access, uint8_t gran) {
    gdt[index].base_low = (base & 0xFFFF);
    gdt[index].base_mid = (base >> 16) & 0xFF;
    gdt[index].base_high = (base >> 24) & 0xFF;

    gdt[index].limit_low = (limit & 0xFFFF);
    gdt[index].granularity = ((limit >> 16) & 0x0F) | (gran & 0xF0);

    gdt[index].access = access;
}

void init_gdt() {
    // Null descriptor
    set_gdt_entry(0, 0, 0, 0, 0);
    
    // Kernel Code Segment
    set_gdt_entry(1, 0, 0xFFFFFFFF,
                  GDT_ACCESS_PRESENT | GDT_ACCESS_RING0 | GDT_ACCESS_CODE_SEG | GDT_ACCESS_READ_WRITE,
                  GDT_GRAN_4KB | GDT_GRAN_32BIT);
    
    // Kernel Data Segment
    set_gdt_entry(2, 0, 0xFFFFFFFF,
                  GDT_ACCESS_PRESENT | GDT_ACCESS_RING0 | GDT_ACCESS_DATA_SEG | GDT_ACCESS_READ_WRITE,
                  GDT_GRAN_4KB | GDT_GRAN_32BIT);
    
    // User Code Segment
    set_gdt_entry(3, 0, 0xFFFFFFFF,
                  GDT_ACCESS_PRESENT | GDT_ACCESS_RING3 | GDT_ACCESS_CODE_SEG | GDT_ACCESS_READ_WRITE,
                  GDT_GRAN_4KB | GDT_GRAN_32BIT);
    
    // User Data Segment
    set_gdt_entry(4, 0, 0xFFFFFFFF,
                  GDT_ACCESS_PRESENT | GDT_ACCESS_RING3 | GDT_ACCESS_DATA_SEG | GDT_ACCESS_READ_WRITE,
                  GDT_GRAN_4KB | GDT_GRAN_32BIT);

    // Set up GDT pointer
    gp.size = sizeof(gdt) - 1;
    gp.offset = (uint32_t)&gdt;

    // Load new GDT
    gdt_flush((uint32_t)&gp);
}
