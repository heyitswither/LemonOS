#include <keyboard.h>

char get_scancode()
{
    char flag = inb(0x64);
    while(!(flag & 1)) {
        flag = inb(0x64);
    }
    return inb(0x60);
}
