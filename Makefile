.ONESHELL:all
export PATH:= toolchain/bin:$(PATH)
CC=i686-elf-gcc
ASM=i686-elf-as

notarget: iso

iso: kernel
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub
	cp lemonos.bin isodir/boot
	grub-mkrescue -o lemonos.iso isodir

kernel: 
	$(ASM) boot.s -o boot.o
	$(CC) -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	$(CC) -T linker.ld -o lemonos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

test:
	qemu-system-i386 -curses -kernel lemonos.bin

test-iso:
	qemu-system-i386 -curses -cdrom lemonos.iso

tools:
	$(MAKE) -C toolchain

clean:
	$(RM) -r isodir lemonos.bin lemonos.iso kernel.o boot.o
