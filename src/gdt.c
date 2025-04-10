#include "../include/gdt.h"

extern void gdt_flush(uint32_t);

gdt_es gdt_ents[5];
gdt_es_ptr gdt_ptr;

void init_gdt()
{
        gdt_ptr.size = (sizeof(gdt_es) * 5) - 1;
        gdt_ptr.offset = &gdt_ents;

        set_gdt(0, 0, 0, 0, 0);
        set_gdt(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
        set_gdt(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
        set_gdt(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
        set_gdt(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

        gdt_flush(&gdt_ptr);
}

/*
void set_gdt(unsigned long int index, unsigned long int base, unsigned long int limit, 
        unsigned char access, unsigned char gran)
        */
void set_gdt(uint32_t index, uint32_t base, uint32_t limit, 
        unsigned char access, unsigned char gran)
{
        gdt_ents[index].base_low = (base & 0xFFFF);
        gdt_ents[index].base_mid = (base >> 16) & 0xFF;
        gdt_ents[index].base_high = (base >> 24) & 0xFF;

        gdt_ents[index].limit = (limit & 0xFFFF);
        gdt_ents[index].flags = (limit >> 16) & 0x0F;
        gdt_ents[index].flags |= (gran & 0x0F);

        gdt_ents[index].access_byte = access;
}
