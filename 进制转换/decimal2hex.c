#include <stdlib.h>
#include <stdio.h>

char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );

	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}

char * Decimal2Hex(int Decimal)
{
	char *result = calloc(33, sizeof(int));
	return itoa(Decimal, result, 16);
}

int main(int argc, char * argv[])
{
    if (argc >= 2)
    {
        printf("0x%s\n", Decimal2Hex(atoi(argv[1])));
    }

    return 0;
}
