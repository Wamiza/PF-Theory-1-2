#include <stdio.h>

#define MAX_LENGTH 100
void inputValues(int values[], int *count) {
    printf("Enter the number of values: ");
    scanf("%d", count);

    printf("Enter %d values:\n", *count);
    for (int i = 0; i < *count; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
    }
}
void displayHorizontalHistogram(int values[], int count) {
    printf("Horizontal Histogram:\n");
    for (int i = 0; i < count; i++) {  
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) {  
            printf("*");
        }
        printf("\n");
    }
}
void displayVerticalHistogram(int values[], int count) {
    printf("Vertical Histogram:\n");

    int max = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    for (int i = max; i > 0; i--) { 
        for (int j = 0; j < count; j++) {  
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    int values[MAX_LENGTH];
    int count;
    inputValues(values, &count);
    displayHorizontalHistogram(values, count);
    displayVerticalHistogram(values, count);

    return 0;
}
     
