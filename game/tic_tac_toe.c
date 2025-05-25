#include <stdio.h>
#include <stdlib.h> // for system("clear")

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    system("clear"); // Clear the terminal screen
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;
    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    system("clear"); // Clear the terminal screen
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 is X and Player 2 is O.\n");
    printf("Enter your moves as row and column (1-3 1-3).\n\n");

    char board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';

    int row, col, player = 0;
    char symbols[2] = {'X', 'O'};

    while (1) {
        printBoard(board);
        printf("Player %d (%c), enter your move (row and column: 1-3 1-3): ", player + 1, symbols[player]);
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        row--;
        col--;
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[row][col] = symbols[player];
        if (checkWin(board)) {
            printBoard(board);
            printf("Player %d (%c) wins!\n", player + 1, symbols[player]);
            break;
        }
        if (checkDraw(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }
        player = 1 - player;
    }
    return 0;
} 