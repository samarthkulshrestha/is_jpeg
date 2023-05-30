#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* fn = argv[1];

    FILE *fp = fopen(fn, "rb");
    if (fp == NULL) {
        perror("fopen");
        printf("error: unable to open file (%s).\n", fn);
        return EXIT_FAILURE;
    }

    const int MAGIC_NUM_BYTES = 3;
    char magic_num[MAGIC_NUM_BYTES] = {0};
    // jpeg files begin with these bytes
    char expected_magic_num[MAGIC_NUM_BYTES] = {0xFF, 0xD8, 0xFF};

    int num_read = fread(magic_num, 1, MAGIC_NUM_BYTES, fp);
    if (num_read != MAGIC_NUM_BYTES) {
        printf("error: could'nt read the first 3 bytes of file (%s)\n", fn);
        return EXIT_FAILURE;
    }

    if (memcmp(magic_num, expected_magic_num, MAGIC_NUM_BYTES) == 0) {
        printf("yes.\n");
    } else {
        printf("no.\n");
    }

}
