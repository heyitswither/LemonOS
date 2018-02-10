.ONESHELL:all
export PATH:= toolchain/bin:$(PATH)
CC=i686-elf-gcc
ASM=i686-elf-as
CFLAGS=-std=gnu99 -masm=att -ffreestanding -O2 -Wall -Wextra -I./include/

notarget: kernel

iso: kernel
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub
	cp lemonos.bin isodir/boot
	grub-mkrescue -o lemonos.iso isodir

kernel: 
	$(ASM) bootloader/boot.s -o bootloader/boot.o
	$(CC) -c kernel.c -o kernel.o $(CFLAGS)
	$(CC) -T linker.ld -o lemonos.bin -ffreestanding -O2 -nostdlib bootloader/boot.o kernel.o -lgcc

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
