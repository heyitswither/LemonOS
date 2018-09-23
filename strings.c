#include <strings.h>

size_t strlen(const char* str)
{
    size_t len = 0;
    while (str[len])
        len++;
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

char tolower(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return c + 32;
    return c;
}

char toupper(char c)
{
    if ((c >= 'a') && (c <= 'z'))
        return c - 32;
    return c;
}
