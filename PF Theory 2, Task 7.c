#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 6
#define COLS 5

void generateRandomArray(char arr[ROWS][COLS], int studentIDLast4) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = 'A' + (rand() % 26);  
        }
    }

    char studentIDStr[5];
    sprintf(studentIDStr, "%04d", studentIDLast4);

    for (int i = 0; i < 4; i++) {
        arr[ROWS - 1][i] = studentIDStr[i];
    }

    arr[ROWS - 1][4] = 'A' + (rand() % 26);
}

void printArray(char arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int searchStringInArray(char arr[ROWS][COLS], char str[]) {
    int len = strlen(str);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (arr[i][j + k] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; 
            }
        }
    }

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j <= ROWS - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (arr[j + k][i] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; 
            }
        }
    }

    return 0; 
}

int main() {
    char arr[ROWS][COLS];
    char searchStr[COLS + 1]; 
    int score = 0;
    int studentIDLast4 = 0010;  

    srand(time(NULL));

    while (1) {
        generateRandomArray(arr, studentIDLast4);
        printf("Generated Array:\n");
        printArray(arr);

        printf("Enter a string to search (or 'END' to quit): ");
        scanf("%s", searchStr);

        if (strcmp(searchStr, "END") == 0) {
            break;
        }

        int found = searchStringInArray(arr, searchStr);
        if (found) {
            score++;
            printf("%s is present. Score: %d\n", searchStr, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", searchStr, score);
        }
    }

    printf("Program ended. Final Score: %d\n", score);
    return 0;
}
