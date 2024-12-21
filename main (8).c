#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: prog.exe <filename> -<mode> [args...]\n");
        return 1;
    }

    const char *filename = argv[1];
    const char *mode = argv[2];

    if (strcmp(mode, "-r") == 0 && argc == 5) {
        const char *old_text = argv[3];
        const char *new_text = argv[4];
        replace_text(filename, old_text, new_text);
    } else if (strcmp(mode, "-d") == 0 && argc == 4) {
        const char *text_to_delete = argv[3];
        delete_lines(filename, text_to_delete);
    } else if (strcmp(mode, "-i") == 0 && argc == 5) {
        const char *text_to_insert = argv[4];
        if (strcmp(argv[3], "-f") == 0) {
            insert_text(filename, text_to_insert, 1);
        } else if (strcmp(argv[3], "-b") == 0) {
            insert_text(filename, text_to_insert, 0);
        } else {
            fprintf(stderr, "Invalid option for -i. Use -f or -b.\n");
            return 1;
        }
    } else {
        fprintf(stderr, "Invalid arguments.\n");
        return 1;
    }

    return 0;
}