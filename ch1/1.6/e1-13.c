#include <stdio.h>

#define MAXWORDSIZE 50
#define IN 1
#define OUT 0

int main() {
    int wordLengths[MAXWORDSIZE];
    int state, i, j, c, isWhitespace, currentLength, maxLength;

    // initialize array to 0s
    for (i = 0; i < MAXWORDSIZE; i++)
    {
        wordLengths[i] = 0;
    }
    maxLength = 0;
    

    state = OUT;
    currentLength = 0;
    while ((c = getchar()) != EOF) {
        isWhitespace = (c == ' ' || c == '\t' || c == '\n');
        if (state == IN) {
            if (isWhitespace) {
                // exiting a word
                if(currentLength > MAXWORDSIZE - 1)
                {
                    printf("Found a word %d characters long. This word won't be displayed in the histogram.\n", currentLength);
                }
                ++wordLengths[currentLength];
                currentLength = 0;
                state == OUT;
            }
            else {
                // moving through a word
                ++currentLength;
                if(currentLength > maxLength) {
                    maxLength = currentLength;
                }
            }
        }
        else {
            if (isWhitespace) {
                ; // moving through whitespace
            }
            else {
                // entering a word;
                currentLength = 1;
                state = IN;
            }
        }
    }

    // maxLength will be the height of the histogram
    for (i = maxLength; i > 0; i--) {
        // MAXWORDSIZE the width of the histogram
        for(j = 0; j < MAXWORDSIZE; j++) {
            if (wordLengths[j] >= i) {
                printf("  X");
            }
        }
        putchar('\n');
    }

    for (i = 1; i <= MAXWORDSIZE; i++) {
        printf("%3d", i);
    }
    putchar('\n');
}