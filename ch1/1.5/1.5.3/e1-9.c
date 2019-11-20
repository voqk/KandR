#include <stdio.h>

int main() {
    int c, inBlankArea;
    inBlankArea = 0;
    while((c = getchar()) != EOF) {
        if (c == ' ') {
            inBlankArea = 1;
        }
        else {
            if (inBlankArea == 1) {
                inBlankArea = 0;
                putchar(' ');
                putchar(c);
            }
            else {
                putchar(c);
            }
        }
    }
}