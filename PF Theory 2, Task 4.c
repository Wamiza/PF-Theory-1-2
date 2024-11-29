#include <stdio.h>

#define MAX_TRANSACTIONS 6
#define MAX_LENGTH 100

void countCharacters(char str[], int count[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++; 
    }
}

int areCountsEqual(int count1[], int count2[]) {
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }
    return 1; 
}

void groupAnagrams(char transactions[MAX_TRANSACTIONS][MAX_LENGTH]) {
    int grouped[MAX_TRANSACTIONS] = {0};
    int count[26];

    printf("Grouped Anagrams:\n");
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (!grouped[i]) { 
            printf("[");
            int isFirst = 1;

            for (int k = 0; k < 26; k++) {
                count[k] = 0;
            }
            countCharacters(transactions[i], count);

            for (int j = 0; j < MAX_TRANSACTIONS; j++) {
                int tempCount[26] = {0}; 

                countCharacters(transactions[j], tempCount); 
                if (areCountsEqual(count, tempCount)) {
                    if (!isFirst) {
                        printf(", ");
                    }
                    printf("\"%s\"", transactions[j]);
                    grouped[j] = 1; 
                    isFirst = 0;
                }
            }
            printf("]\n");
        }
    }
}

int main() {
    char transactions[MAX_TRANSACTIONS][MAX_LENGTH];
    printf("Enter %d transaction strings (one per line):\n", MAX_TRANSACTIONS);
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        printf("Transaction %d: ", i + 1);
        scanf("%s", transactions[i]); 
    }

    groupAnagrams(transactions);

    return 0;
}
