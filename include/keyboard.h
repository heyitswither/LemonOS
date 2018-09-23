#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <asm.h>

char scancodes[256] = {0, 0, /*ESC*/ 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
                      '-', '=', /*DEL*/ 0x7f, '\t', 'Q', 'W', 'E', 'R', 'T', 'Y',
                      'U', 'I', 'O', 'P', '[', ']', /*ENTER*/ '\n', /*LCTRL*/ 0, 'A', 'S', 'D', 'F', 'G',
                      'H', 'J', 'K', 'L', ';', '\'', '`', /*LSHIFT*/ 0, '\\', 'Z',
                      'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', /*RSHIFT*/ 0,
                      '*', /*LALT*/ 0, ' ', /*CAPS*/ 0, /*F1*/ 0, 0, 0, 0, 0, 0, 0,
                      0, 0, /*F10*/ 0, /*NUM*/ 0, /*SCROLL*/ 0, '7', '8', '9', '-',
                      '4', '5', '6', '+', '1', '2', '3', '0', '.', 0, 0, 0, /*F11*/ 0,
                      /*F12*/ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char get_scancode(void);

#endif
