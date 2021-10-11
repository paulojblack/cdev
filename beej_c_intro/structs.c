// Structs can be scoped, but are generally declared at global scope
#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

int main(void) {
    struct car saturn;

    saturn.name = "Saturn";
    saturn.price = 19999.99;
    saturn.speed = 100;

    //OR

    struct car honda = {"Fit", 21999.99, 110};

    // OR

    struct car ford = {.name="F150", .price=14999.99, .speed=90};

    printf("Name: %s\n", saturn.name);
    printf("Price: %f\n", saturn.price);
    printf("Speed: %d\n", saturn.speed);
}