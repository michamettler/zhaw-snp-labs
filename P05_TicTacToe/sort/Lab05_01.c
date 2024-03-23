#include <ctype.h>
#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][21], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[0] != '\0' && strcmp(arr[i], arr[i + 1]) > 0) {
            char temp[10];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[i + 1]);
            strcpy(arr[i + 1], temp);
        }
    }
}

int main(void) {
    char words[10][21] = {""}; // Frage, wieso liegen da sonst random Symbole rum?

    printf("Enter words, end with 'ZZZ'.\n");

    for (int i = 0; i < 10; i++) {
        char word[22];
        if (fgets(word, sizeof(word), stdin) != NULL) {
            const size_t len = strlen(word);
            if (word[len - 1] == '\n') {
                word[len - 1] = '\0';
            } else {
                printf("Input was too long. Exiting.\n");
                return -1;
            }
        }

        if (strcmp(word, "ZZZ") == 0) {
            break;
        }

        for (int j = 0; j < strlen(word); j++) {
            word[j] = toupper(word[j]);
        }

        for (int j = -1; j < i; j++) {
            if (j > -1 && strcmp(words[j], word) != 0) {
                break;
            }
            strcpy(words[i], word);
        }
    }

    bubbleSort(words, 10);

    for (int i = 0; i < 10; i++) {
        if (words[i][0] != '\0') {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}
