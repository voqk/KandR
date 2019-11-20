#include <stdio.h>

/* count lines in input */
int main() {
    int c, bl, t, nl;
    bl = t = nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++bl;
        }
        if (c == '\t') {
            ++t;
        }
        if (c == '\n') {
            ++nl;
        }
    }
    printf("blanks: %d, tabs: %d, newlines: %d\n", bl, t, nl);
}
