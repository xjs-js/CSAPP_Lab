#include <stdio.h>
#include <stdlib.h>

int Hex2Decimal(char * Hex)
{
    int d;
    sscanf(Hex, "%x", &d);
    return d;
}

int main(int argc, char * argv[])
{
    if (argc >= 2)
    {
        printf("%d\n", Hex2Decimal(argv[1]));
    }
    return 0;
}