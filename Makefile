.ONESHELL:all
export PATH:= toolchain/bin:$(PATH)
CC=i686-elf-gcc
AS=i686-elf-as
CFLAGS=-std=gnu99 -masm=att -ffreestanding -O2 -Wall -I./include/
OBJS=kernel.o lstdlib.o keyboard.o cursor.o strings.o

notarget: los

iso: los
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub
	cp lemonos.bin isodir/boot
	grub-mkrescue -o lemonos.iso isodir

bootloader: bootloader/boot.o

los: $(OBJS) bootloader
	$(CC) -T linker.ld -o lemonos.bin -ffreestanding -O2 -nostartfiles -nostdlib bootloader/boot.o $(OBJS) -lgcc

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
