#include <stdio.h>

/*
 * Program to print a specific star pattern.
 * This pattern consists star shaped stars.
 * The pattern is hollow, with stars placed in the shape of a star.
 * The input value N should be an odd number (e.g., 7, 9, 11).
 */

int main() {
    int n;

    printf("Enter an odd value for N (e.g., 3, 5, 7, ...): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Error: N must be an odd number.\n");
        return 1;
    }

    int width = (n * 2 - 2) + (n * 2 - 2) + 1; //indicating columns
    int height = n * 3 - 2; // indicating rows
    
    // printing upper triangle of the star
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == width/2+i || j == width/2-i ) { 
                printf("* ");
            } else {
                printf("  "); 
            }
        }
        printf("\n"); 
    }
    
    // printing first line of star's hands
    for (int i =n ; i <= n; i++) {
        for (int j = 0; j < width; j++) {
           if (j<n || j>=n*3-3) { 
                printf("* ");
            } else {
                printf("  "); 
            }
        }
        printf("\n"); 
    }
    
     // printing rest of the star's hands
    for (int i =n+1; i<=height-n+1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == width-width+i-n || j == width-i+n-1 ) { 
                printf("* ");
            } else {
                printf("  "); 
            }
        }
        printf("\n"); 
    }
    
    // printing rest of the star
    for (int i=2*n; i<=height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == width-width-i+3*n-2 ||  j == width+i-3*n+1 ) { 
                printf("* "); // printing outer part
            }
			else if(j == width/2-i+2*n-1 || j == width/2+i-2*n+1 ) {
				 printf("* "); // printing inner part
			}
			else {
                printf("  "); 
            }
        }
       printf("\n"); 
    }

    
    return 0;
}
