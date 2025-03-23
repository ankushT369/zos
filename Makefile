# Cross-compiler prefix
CC = i686-elf-gcc
ASM = nasm
LD = i686-elf-ld

# Compiler and linker flags
CFLAGS = -m32 -ffreestanding -nostdlib -Wall -Wextra -Iinclude
ASMFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T linker.ld -nostdlib

# Directories
SRC_DIR = src
OBJ_DIR = obj
ISO_DIR = iso

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.asm)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) \
            $(patsubst $(SRC_DIR)/%.asm, $(OBJ_DIR)/%.o, $(ASM_FILES))

# Output files
KERNEL_BIN = kernel.bin
ISO = unicore.iso

# Build the kernel
all: $(KERNEL_BIN)

$(KERNEL_BIN): $(OBJ_FILES)
	$(LD) $(LDFLAGS) -o $@ $^

# Compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Assemble .asm files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(OBJ_DIR)
	$(ASM) $(ASMFLAGS) -o $@ $<

# Create a bootable ISO
iso: $(KERNEL_BIN)
	@mkdir -p $(ISO_DIR)/boot/grub
	cp $(KERNEL_BIN) $(ISO_DIR)/boot/
	cp boot/grub/grub.cfg $(ISO_DIR)/boot/grub/
	grub-mkrescue -o $(ISO) $(ISO_DIR)

# Run the OS in QEMU
run: iso
	qemu-system-x86_64 -cdrom $(ISO)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(KERNEL_BIN) $(ISO) $(ISO_DIR)
