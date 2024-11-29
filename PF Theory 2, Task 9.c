#include <stdio.h>

#define GRID_SIZE 5

void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}
void findPlayer(char grid[GRID_SIZE][GRID_SIZE], int *playerRow, int *playerCol) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'P') {
                *playerRow = i;
                *playerCol = j;
                return;
            }
        }
    }
}

int main() {
   
    char grid[GRID_SIZE][GRID_SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    
    int playerRow, playerCol;
    findPlayer(grid, &playerRow, &playerCol);
    
    char move;
    int itemsCollected = 0;

    while (1) {
        printf("\nCurrent Grid:\n");
        displayGrid(grid);
        printf("Items collected: %d\n", itemsCollected);
        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        int newRow = playerRow;
        int newCol = playerCol;

        if (move == 'W' || move == 'w') newRow--;
        else if (move == 'S' || move == 's') newRow++;
        else if (move == 'A' || move == 'a') newCol--;
        else if (move == 'D' || move == 'd') newCol++;
        else if (move == 'Q' || move == 'q') {
            printf("Exiting game.\n");
            break;
        } else {
            printf("Invalid move.\n");
            continue;
        }

        if (newRow < 0 || newRow >= GRID_SIZE || newCol < 0 || newCol >= GRID_SIZE) {
            printf("You can't move outside the grid!\n");
            continue;
        }

        if (grid[newRow][newCol] == 'X') {
            printf("There's an obstacle!\n");
            continue;
        }

        if (grid[newRow][newCol] == 'I') {
            printf("You found an item!\n");
            itemsCollected++;
        }

        grid[playerRow][playerCol] = ' ';  
        grid[newRow][newCol] = 'P'; 
        playerRow = newRow;                
        playerCol = newCol;           
    }

    printf("Game over! You collected %d items.\n", itemsCollected);
    return 0;
}
