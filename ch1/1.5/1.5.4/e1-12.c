#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, state, isSep;

    state = OUT;

    while((c = getchar()) != EOF) {
        isSep = (c == ' ' || c == '\t' || c == '\n');

        if (isSep && state == IN) {
            state = OUT;
            putchar('\n');
        }
        else if (isSep && state == OUT) {
            ; /* leaving this here for clarity */
        }
        else if (!isSep && state == IN) {
            putchar(c);
        }
        else if (!isSep && state == OUT) {
            state = IN;
            putchar(c);
        }
    }
}