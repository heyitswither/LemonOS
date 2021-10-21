#ifndef _STRINGS_H
#define _STRINGS_H

#include <stddef.h>
#include <lstdlib.h>

size_t strlen(const char* str);
bool isdigit(char c);
bool isalpha(char c);
bool islower(char c);
bool isupper(char c);
char tolower(char c);
char toupper(char c);

#endif
