#include <stdio.h>

int MAX_WORDS = 3;
int MAX_LENGTH = 100;

int compressWord(char *word, char *compressed) {
    int k = 0, removedCount = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressed[k++] = word[i];
        } else {
            removedCount++;
        }
    }
    compressed[k] = '\0'; 
    return removedCount;
}

int main() {
    char words[3][100];
    char compressedWords[MAX_WORDS][MAX_LENGTH];
    int totalRemoved = 0;

    printf("Enter up to %d words to compress:\n", MAX_WORDS);
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], MAX_LENGTH, stdin);

        for (int j = 0; words[i][j] != '\0'; j++) {
            if (words[i][j] == '\n') {
                words[i][j] = '\0';
                break;
            }
        }
    }
    for (int i = 0; i < MAX_WORDS; i++) {
        int removed = compressWord(words[i], compressedWords[i]);
        totalRemoved += removed;
        printf("Compressed \"%s\" to \"%s\" (Removed: %d characters)\n", words[i], compressedWords[i], removed);
    }

    printf("Total characters removed: %d\n", totalRemoved);
    return 0;
}
