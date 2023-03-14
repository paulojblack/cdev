#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "not enough args\n");
        exit(1);
    }

    FILE *fp = fopen("./wcat.c", "r");
    if (fp == NULL) {
        fprintf(stderr, "Invalid file");
    }

    

    exit(0);
}