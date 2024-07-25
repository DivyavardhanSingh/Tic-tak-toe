#include <stdio.h>

#define SIZE 3

// Function declarations
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int isDraw(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char player);

int main() {
    char board[SIZE][SIZE] = {{'1', '2', '3'},
                              {'4', '5', '6'},
                              {'7', '8', '9'}};
    int turn = 0;  // 0 for player X, 1 for player O
    int gameStatus = 0;  // 0 means continue, 1 means win, -1 means draw

    printf("Welcome to Tic Tac Toe!\n");

    while (gameStatus == 0) {
        printBoard(board);
        if (turn == 0) {
            printf("Player X's turn\n");
            playerMove(board, 'X');
            turn = 1;
        } else {
            printf("Player O's turn\n");
            playerMove(board, 'O');
            turn = 0;
        }
        gameStatus = checkWin(board);
        if (gameStatus == 0 && isDraw(board)) {
            gameStatus = -1;
        }
    }

    printBoard(board);
    if (gameStatus == 1) {
        if (turn == 1) {
            printf("Player X wins!\n");
        } else {
            printf("Player O wins!\n");
        }
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("Current board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int isDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove(char board[SIZE][SIZE], char player) {
    int move;
    int validMove = 0;
    while (!validMove) {
        printf("Enter the number of the cell where you want to place your %c: ", player);
        scanf("%d", &move);
        if (move >= 1 && move <= 9) {
            int row = (move - 1) / SIZE;
            int col = (move - 1) % SIZE;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = player;
                validMove = 1;
            } else {
                printf("Cell already occupied, try again.\n");
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}
