#include <stdio.h>

int main() {
    int nPrintableChars = '~' - ' ';
    int charFreqs[nPrintableChars];
    int c, i, j, val, maxVal;

    for (i = 0; i < nPrintableChars; i++) {
        charFreqs[i] = 0;
    }

    maxVal = 0;
    while((c = getchar()) != EOF) {
        if ( c >= ' ' && c <= '~') {
            val = c - ' ';
            ++charFreqs[val];
            if (charFreqs[val] > maxVal) {
                maxVal = charFreqs[val];
            }
        }
    }

    for (i = maxVal; i > 0; i--) {
        for(j = 0; j < nPrintableChars; j++) {
            if(charFreqs[j] >= i) {
                printf("X");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < nPrintableChars; i++) {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < nPrintableChars; i++) {
        printf("%c", i + ' ');
    }
    printf("\n");
}