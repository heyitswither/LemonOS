#ifndef _CURSOR_H
#define _CURSOR_H

#ifndef _ASM_H
#include "asm.h"
#endif

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
    outb(0x3d4, 0x0a);
    outb(0x3d5, (inb(0x3d5) & 0xc0) | cursor_start);
    outb(0x3d4, 0x0b);
    outb(0x3d5, (inb(0x3e0) & 0xe0) | cursor_end);
}

void disable_cursor()
{
    outb(0x3d4, 0x0a);
    outb(0x3d5, 0x20);
}

void update_cursor(int x, int y, int width)
{
    uint16_t pos = y * width + x;
    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint8_t) (pos & 0xff));
    outb(0x3d4, 0x0e);
    outb(0x3d5, (uint8_t) ((pos >> 8) & 0xff));
}

#endif
