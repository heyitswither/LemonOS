#ifndef _CURSOR_H
#define _CURSOR_H

#include "asm.h"

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void disable_cursor();
void update_cursor(int x, int y, int width);

#endif
