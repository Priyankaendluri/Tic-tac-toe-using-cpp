#include <iostream>
using namespace std;

char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

char checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' '; // no winner yet
}

int main() {
    initBoard();
    int currentPlayer = 1; // 1 = X, 2 = O
    char winner = ' ';

    cout << "===== Tic-Tac-Toe =====\n";
    cout << "Players take turns entering row and column (1-3).\n";

    while (true) {
        printBoard();

        int row, col;
        char symbol = (currentPlayer == 1) ? 'X' : 'O';

        cout << "Player " << currentPlayer << " (" << symbol << ") - enter row and column: ";
        cin >> row >> col;
        row--; col--; // convert to 0-based index

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = symbol;

        winner = checkWinner();
        if (winner != ' ') {
            printBoard();
            cout << "Player " << currentPlayer << " (" << winner << ") wins!\n";
            break;
        }

        if (isBoardFull()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}