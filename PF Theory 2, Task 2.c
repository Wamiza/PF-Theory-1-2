#include <stdio.h>

int main() {
  
    int MAX_SLOGANS = 3, MAX_LENGTH = 100;
    char slogans[3][100] = {
        "buy now",
        "save big",
        "limited offer"
    };
    for (int s = 0; s < MAX_SLOGANS; s++) {
        int freq[256] = {0}; 
        for (int i = 0; slogans[s][i] != '\0'; i++) {
            if (slogans[s][i] != ' ') {
                freq[(int)slogans[s][i]]++;
            }
        }
        printf("For \"%s\": {", slogans[s]);
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                printf("'%c': %d, ", i, freq[i]);
            }
        }
        printf("\b\b}\n");
    }

    return 0;
}
