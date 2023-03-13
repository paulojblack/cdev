#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void celTable() {
    float fahr, cel;

    printf("%3s %6s\n", "Cel", "Far");
    for(cel = LOWER; cel <= UPPER; cel = cel + STEP)
    {
        fahr = cel * (9.0/5.0) + 32.0;
        printf("%3.0f %6.1f\n", cel, fahr);
    }
}

void farTable() {
    float fahr, cel;

    fahr = LOWER;

    printf("%3s %6s\n", "Cel", "Far");
    while (fahr <= UPPER)
    {
        cel = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, cel);
        fahr += STEP;
    }
}
int main() {
    farTable();
    printf("\n");
    celTable();
}
