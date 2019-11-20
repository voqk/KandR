#include <stdio.h>

/* To verify that getchar() != EOF is 0 or 1 we print the result of the
 expression for all inputs and expect 1s until the EOF is reached and 
 should see a single 0 */

int main() {
    int c;
    do {
        c = getchar();
        printf("%d", c != EOF);
    } while (c != EOF);
}