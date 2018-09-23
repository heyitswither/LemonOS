.ONESHELL:all
export PATH:= toolchain/bin:$(PATH)
CC=i686-elf-gcc
ASM=i686-elf-as
CFLAGS=-std=gnu99 -masm=att -ffreestanding -O2 -Wall -Wextra -Werror -Wpedantic -I./include/
OBJS=kernel.o lstdlib.o keyboard.o asm.o cursor.o strings.o

notarget: kernel

iso: kernel
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub
	cp lemonos.bin isodir/boot
	grub-mkrescue -o lemonos.iso isodir

kernel: $(OBJS)

bootloader:
	$(ASM) bootloader/boot.s -o bootloader/boot.o

los: kernel bootloader
	$(CC) -T linker.ld -o lemonos.bin -ffreestanding -O2 -nostdlib bootloader/boot.o $(OBJS) -lgcc

test:
	qemu-system-i386 -curses -kernel lemonos.bin

test-iso:
	qemu-system-i386 -curses -cdrom lemonos.iso

test-gui:
	qemu-system-i386 -kernel lemonos.bin

test-iso-gui:
	qemu-system-i386 -cdrom lemonos.iso

tools:
	$(MAKE) -C toolchain

clean:
	$(RM) -r isodir lemonos.bin lemonos.iso kernel.o bootloader/boot.o
