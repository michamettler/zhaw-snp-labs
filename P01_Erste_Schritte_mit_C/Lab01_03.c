#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int charCount = 0;
    int wordCount = 0;
    char ch;
    bool inWord = true;

    printf("Geben Sie eine Zeile ein:\n");

    while((ch = getchar()) != '\n') {
        charCount++;

        if (ch == ' ' || ch == '\t') {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }

    if (inWord) {
        wordCount++;
    }

    printf("Anzahl Zeichen: %d\n", charCount);
    printf("Anzahl Woerter: %d\n", wordCount);

    return EXIT_SUCCESS;
}
