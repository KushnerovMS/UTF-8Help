#include <stdio.h>

#include "UTF8Help.h"

int SymbSize (const char* str)
{
    if ( ( *str >> 7 ) == 0)
        return 1;

    if ( ( (*str >> 6) & 1 ) == 0)
    {
        int i = 1;
        for (; ( str[i] >> 6 ) == 2; i ++)
            ;

        return - i;
    }

    for (int i = 2; ; i ++)
        if ( ( (*str >> (7 - i) ) & 1 ) == 0)
            return i;

    return 0;
}

int UNICODE (const char* str, int* skip)
{
    if ( ( *str >> 7 ) == 0)
    {
        if (skip) *skip = 1;

        return str[0] & 0x7F;
    }

    if ( ( (*str >> 6) & 1 ) == 0)
    {
        if (skip) *skip = SymbSize (str);

        return 0;
    }

    if ( ( (*str >> 5) & 1 ) == 0)
    {
        if (skip) *skip = 2;

        return ((str[0] & 0xF) << 6) + (str[1] & 0x3F);
    }

    if ( ( (*str >> 4) & 1 ) == 0)
    {
        if (skip) *skip = 3;

        return ((str[0] & 0x7) << 12) + ((str[1] & 0x3F) << 6) + (str[2] & 0x3F);
    }

    if ( ( (*str >> 3) & 1 ) == 0)
    {
        if (skip) *skip = 4;

        return ((str[0] & 0x5) << 18) + ((str[1] & 0x3F) << 12) + ((str[1] & 0x3F) << 6) + (str[2] & 0x3F);
    }

    return 0;
}

int SymbCodeAdd (char* str, int addition)
{
    int size = SymbSize (str);

    if (size <= 0)
        return size;

    if (size == 1)
    {
        if (*str + addition < 0)
            *str = 0;

        else if (*str + addition >= 0x7F)
            *str = 0x7F;

        else
            *str += addition;
    }
    else
    {
        for (int i = size - 1; i > 0 && ( addition >> ((size - 1 - i) * 6) ) != 0; i --)
        {
            str[i] += ( addition >> ((size - 1 - i) * 6) ) & 0x3F;
            if ( ( str[i] & 0x40 ) != 0)
            {
                str[i] &= ~0x40;
                addition += 1 << ((size - i) * 6);
            }
        }

        *str += ( addition >> ((size - 1) * 6) ) & ( (1 << (7 - size)) - 1 );
        
        if ( ( (*str & 0xFE) >> (7 - size) ) != (1 << (size + 1)) - 2 )
            *str = ~ (1 << (7 - size));
            
            
    }

    return size;
}

