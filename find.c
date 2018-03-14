#include <stdlib.h>
#include "find.h"

int
find(char c, char* charset)
{
    int i = 0;
    while (charset[i] != '\0')
    {
       if (c == charset[i])
        return 1;
       i++; 
    }
    return 0;
}