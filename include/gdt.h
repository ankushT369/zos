#ifndef __GDT_H__
#define __GDT_H__

#include <stdint.h>

#define SEG_DATA_RD             0x00 /* Read-Only */
#define SEG_DATA_RDA            0x01 /* Read-Only, accessed */
#define SEG_DATA_RDWR           0x02 /* Read/Write */
#define SEG_DATA_RDWRA          0x03 /* Read/Write, accessed */
#define SEG_DATA_RDEXPD         0x04 /* Read-Only, expand-down */
#define SEG_DATA_RDEXPDA        0x05 /* Read-Only, expand-down, accessed */
#define SEG_DATA_RDWREXPD       0x06 /* Read/Write, expand-down */
#define SEG_DATA_RDWREXPDA      0x07 /* Read/Write, expand-down, accessed */
#define SEG_CODE_EX             0x08 /* Execute-Only */
#define SEG_CODE_EXA            0x09 /* Execute-Only, accessed */
#define SEG_CODE_EXRD           0x0A /* Execute/Read */
#define SEG_CODE_EXRDA          0x0B /* Execute/Read, accessed */
#define SEG_CODE_EXC            0x0C /* Execute-Only, conforming */
#define SEG_CODE_EXCA           0x0D /* Execute-Only, conforming, accessed */
#define SEG_CODE_EXRDC          0x0E /* Execute/Read, conforming */
#define SEG_CODE_EXRDCA         0x0F /* Execute/Read, conforming, accessed */

#define SEG_RING0               (0 << 5)  /* Ring 0 - Kernel */
#define SEG_RING1               (1 << 5)  /* Ring 1 */
#define SEG_RING2               (2 << 5)  /* Ring 2 */
#define SEG_RING3               (3 << 5)  /* Ring 3 - User */

#define SEG_PRESENT             (1 << 7)
#define SEG_NOT_PRESENT         (0 << 7)

#define SEG_CODE_DATA           (1 << 4)
#define SEG_SYS                 (0 << 4)

#define KERN_CODE_SEG           SEG_PRESENT | SEG_RING0 | SEG_CODE_DATA | SEG_CODE_EXRD
#define KERN_DATA_SEG           SEG_PRESENT | SEG_RING0 | SEG_CODE_DATA | SEG_DATA_RDWR
#define USER_CODE_SEG           SEG_PRESENT | SEG_RING3 | SEG_CODE_DATA | SEG_CODE_EXRD
#define USER_DATA_SEG           SEG_PRESENT | SEG_RING3 | SEG_CODE_DATA | SEG_DATA_RDWR

struct gdt_es
{
        unsigned short          limit;
        unsigned short          base_low;
        unsigned char           base_mid;
        unsigned char           access_byte;
        unsigned char           flags;
        unsigned char           base_high;
}__attribute__((packed));


struct gdt_es_ptr
{
        unsigned short          size;
        uint32_t            offset;
}__attribute__((packed));


typedef struct gdt_es gdt_es;
typedef struct gdt_es_ptr gdt_es_ptr;

void init_gdt();
void set_gdt(uint32_t, uint32_t, uint32_t, unsigned char, unsigned char);

#endif // __GDT_H__
