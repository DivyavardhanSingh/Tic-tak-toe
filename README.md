# Tic-tak-toe
Initialization:

The board array represents the 3x3 Tic Tac Toe grid, initialized with numbers 1 to 9.
turn is used to keep track of whose turn it is (0 for player X, 1 for player O).
gameStatus keeps track of the state of the game (0 means the game continues, 1 means a win, -1 means a draw).
Main Loop:

The game runs in a loop until gameStatus changes.
The board is printed after each turn.
Players take turns to move by calling playerMove().
After each move, the game checks for a win with checkWin().
If no one has won and all cells are filled, it's a draw.
Functions:

printBoard(): Displays the current state of the board.
checkWin(): Checks all rows, columns, and diagonals for a win condition.
isDraw(): Checks if all cells are filled without a winner.
playerMove(): Takes player input and updates the board if the move is valid.
