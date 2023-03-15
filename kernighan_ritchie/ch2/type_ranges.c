#include <stdio.h>

int main() {
    unsigned char max_uchar;
    signed char min_schar, max_schar;
    unsigned short max_ushort;
    signed short min_sshort, max_sshort;
    unsigned int max_uint;
    signed int min_sint, max_sint;
    unsigned long max_ulong;
    signed long min_slong, max_slong;

    max_uchar = ~0;
    max_schar = (signed char)(max_uchar >> 1);
    min_schar = ~max_schar;

    max_ushort = ~0;
    max_sshort = (signed short)(max_ushort >> 1);
    min_sshort = ~max_sshort;

    max_uint = ~0;
    max_sint = (signed int)(max_uint >> 1);
    min_sint = ~max_sint;

    max_ulong = ~0;
    max_slong = (signed long)(max_ulong >> 1);
    min_slong = ~max_slong;

    printf("Ranges of char:\n");
    printf("  Unsigned char: 0 to %u\n", max_uchar);
    printf("  Signed char: %d to %d\n", min_schar, max_schar);

    printf("Ranges of short:\n");
    printf("  Unsigned short: 0 to %u\n", max_ushort);
    printf("  Signed short: %d to %d\n", min_sshort, max_sshort);

    printf("Ranges of int:\n");
    printf("  Unsigned int: 0 to %u\n", max_uint);

}