#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void drawBoard() {
        std::cout << "\n";
        for (int i = 0; i < 3; i++) {
            std::cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << std::endl;
            if (i < 2) std::cout << "---+---+---" << std::endl;
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && 
                board[i][0] == board[i][1] && 
                board[i][1] == board[i][2]) {
                return true;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == currentPlayer && 
                board[0][j] == board[1][j] && 
                board[1][j] == board[2][j]) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && 
            board[0][0] == board[1][1] && 
            board[1][1] == board[2][2]) {
            return true;
        }

        if (board[0][2] == currentPlayer && 
            board[0][2] == board[1][1] && 
            board[1][1] == board[2][0]) {
            return true;
        }

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }

    void play() {
        int row, col;
        bool gameOver = false;

        std::cout << "Welcome to Tic Tac Toe!\n";
        std::cout << "Player 1 is X, Player 2 is O\n";

        while (!gameOver) {
            drawBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (row[0-2] column[0-2]): ";
            std::cin >> row >> col;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    drawBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    drawBoard();
                    std::cout << "It's a draw!\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}