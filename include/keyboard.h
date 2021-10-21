#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <asm.h>

char scancodes[256];

char get_scancode(void);

#endif
