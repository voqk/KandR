#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#define LOWERBOUND 80

/* I figure for this exercise I would use the getline() function available to POSIX systems */

int main(int argc, char *argv[]) {
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    stream = fopen(argv[1], "r");
    if (stream == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((nread = getline(&line, &len, stream)) != -1) {
        if (nread > 80) {
            fwrite(line, nread, 1, stdout);
        }
    }

    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}