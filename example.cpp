#include <stdio.h>

#include "UTF8Help.h"

int toLower (char* str)
{
    int size = 0;
    int UNI = UNICODE (str, &size);
    if (UNI >= UNICODE ("А") && UNI <= UNICODE ("Я"))
        SymbCodeAdd (str, UNICODE ("а") - UNICODE ("А"));

    return size;
}

int main ()
{
    char str[] = "АТтвЯЁёKJHljkhLJK";

//    for (int i = 0, size; str [i] != '\0'; i += size) 
//        size = toLower (str + i);


    StrToLower (str);

    printf ("%s\n", str);

    char buff[100] = "я";
    int skip = 0;
    while (buff[0] != '\n')
    {
        scanf ("%10s", buff);
        printf ("%d\n", UNICODE (buff));
        SymbCodeAdd (buff, 1);
        printf ("%s\n", buff);
    }


    return 0;
}
