#ifndef _STRINGS_H
#define _STRINGS_H

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

bool isdigit(char c)
{
    return (c > 47 && c < 58);
}

bool isalpha(char c)
{
    return (c > 64 && c < 91) || (c > 96 && c < 123);
}

bool islower(char c)
{
    return (c > 96 && c < 123);
}

bool isupper(char c)
{
    return (c > 64 && c < 91);
}

#endif
