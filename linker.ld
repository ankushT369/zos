/*ENTRY(_start) /* Entry point is now _start (from boot.asm) */

/*
SECTIONS {
    . = 0x100000; /* Kernel loaded at 1MB */

    /*
    .multiboot : { *(.multiboot) } /* Multiboot header section */
    /*
    .text : { *(.text) } /* Code section */
    /*
    .rodata : { *(.rodata) } /* Read-only data */
    /*
    .data : { *(.data) } /* Initialized data */
    /*
    .bss : { *(.bss) } /* Uninitialized data */
/*}*/

ENTRY(_start)

SECTIONS {
    . = 1M;
    .multiboot : {
        *(.multiboot)
    }
    .text : ALIGN(4K) {
        *(.text)
    }
    .data : ALIGN(4K) {
        *(.data)
    }
    .bss : ALIGN(4K) {
        *(COMMON)
        *(.bss)
    }
}

