#include <stdio.h>

#include "UTF8Help.h"

int toLower (char* str)
{
    int size = 0;
    int UNI = UNICODE (str, &size);
    if (UNI >= UNICODE ("А") && UNI <= UNICODE ("Я"))
        SymbCodeAdd (str, UNICODE ("а") - UNICODE ("А"));
}

int main ()
{
    char str[] = "АТтвЯ";

    for (int i = 0, size; str [i] != '\0'; i += size) 
        toLower (str + i, &size);

    printf ("%s\n", str);


    return 0;
}
