#include "spob_string.h"

int8_t tolower(int8_t s1)
{
    if (s1 >= 65 && s1 <= 90)
    {
        s1 += 32;
    }

    return s1;
}

uint16_t strlen(const int8_t* ptr)
{
    uint16_t i = 0;
    while(*ptr != 0)
    {
        i++;
        ptr += 1;
    }

    return i;
}

uint16_t strnlen(const int8_t* ptr, uint16_t max)
{
    uint16_t i = 0;
    for (i = 0; i < max; i++)
    {
        if (ptr[i] == 0)
            break;
    }

    return i;
}

uint16_t strnlen_terminator(const int8_t* str, uint16_t max, int8_t terminator)
{
    uint16_t i = 0;
    for(i = 0; i < max; i++)
    {
        if (str[i] == '\0' || str[i] == terminator)
            break;
    }

    return i;
}

int16_t istrncmp(const int8_t* s1, const int8_t* s2, int16_t n)
{
    uint8_t u1, u2;
    while(n-- > 0)
    {
        u1 = (uint8_t)*s1++;
        u2 = (uint8_t)*s2++;
        if (u1 != u2 && tolower(u1) != tolower(u2))
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}
int16_t strncmp(const int8_t* str1, const int8_t* str2, int16_t n)
{
    uint8_t u1, u2;

    while(n-- > 0)
    {
        u1 = (uint8_t)*str1++;
        u2 = (uint8_t)*str2++;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}

int8_t* strcpy(int8_t* dest, const int8_t* src)
{
    int8_t* res = dest;
    while(*src != 0)
    {
        *dest = *src;
        src += 1;
        dest += 1;
    }

    *dest = 0x00;

    return res;
}

int8_t* strncpy(int8_t* dest, const int8_t* src, int16_t count)
{
    int16_t i = 0;
    for (i = 0; i < count-1; i++)
    {
        if (src[i] == 0x00)
            break;

        dest[i] = src[i];
    }

    dest[i] = 0x00;
    return dest;
}

bool isdigit(int8_t c)
{
    return c >= 48 && c <= 57;
}

int16_t tonumericdigit(int8_t c)
{
    return c - 48;
}

int8_t* sp = 0;
int8_t* strtok(int8_t* str, const int8_t* delimiters)
{
    int16_t i = 0;
    int16_t len = strlen(delimiters);
    if (!str && !sp)
        return 0;

    if (str && !sp)
    {
        sp = str;
    }

    int8_t* p_start = sp;
    while(1)
    {
        for (i = 0; i < len; i++)
        {
            if(*p_start == delimiters[i])
            {
                p_start++;
                break;
            }
        }

        if (i == len)
        {
            sp = p_start;
            break;
        }
    }

    if (*sp == '\0')
    {
        sp = 0;
        return sp;
    }

    // Find end of substring
    while(*sp != '\0')
    {
        for (i = 0; i < len; i++)
        {
            if (*sp == delimiters[i])
            {
                *sp = '\0';
                break;
            }
        }

        sp++;
        if (i < len)
            break;
    }

    return p_start;
}

int16_t nstoh(int16_t srcport) 
{
    int16_t dstport;  
    int8_t a, b;

    a = ((srcport & 0xff00) >> 8);
    b = (srcport & 0xff);
    dstport = 0;
    dstport = (b << 8) + a;

    return dstport;
}

void zero(int8_t *str, int16_t size) 
{
    int8_t *p;
    int16_t n;

    for (n=0, p=str; n<size; n++, p++)
        *p = 0;

    return;
}

void printhex(int8_t *str, int16_t size, int8_t delim) 
{
    int8_t *p;
    int16_t n;

    for (p=str, n=size; n; n--, p++) 
    {
        printf("%.02x", *p);
        if (delim)
            printf("%c", delim);
        fflush(stdout);
    }
    printf("\n");

    return;
}

#pragma GCC diagnostic pop

