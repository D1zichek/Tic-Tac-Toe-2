#include "game.hpp"
#include "board.hpp"
#include "settings.hpp"
#include <iostream>

void startGame() {
    std::cout << "\n=== Start Game ===\n";
    
    int firstPlayer;
    std::cout << "Who move first? (1 - " << player1 << ", 2 - " << player2 << "): ";
    std::cin >> firstPlayer;

    int currentPlayer = firstPlayer;
    char currentSymbol = 'X';

    std::vector<std::vector<char>> board(boardSize, std::vector<char>(boardSize, ' '));

    bool gameOver = false;
    while (!gameOver) {
        displayBoard(board);
        
        std::cout << "\nMove " << (currentPlayer == 1 ? player1 : player2) << " (" << currentSymbol << ")\n";
        std::cout << "Enter number row (1-" << boardSize << ", 0 - exit): ";
        int row;
        std::cin >> row;

        if (row == 0) {
            std::cout << "Exiting a match...\n";
            return;
        }

        std::cout << "Enter number column (1-" << boardSize << ", 0 - exit): ";
        int col;
        std::cin >> col;

        if (col == 0) {
            std::cout << "Exiting a match...\n";
            return;
        }

        if (row < 1 || row > boardSize || col < 1 || col > boardSize) {
            std::cout << "Invalid coordinates. Try again.\n";
            continue;
        }

        if (board[row - 1][col - 1] != ' ') {
            std::cout << "This cell is occupied. Try again.\n";
            continue;
        }

        board[row - 1][col - 1] = currentSymbol;
        displayBoard(board);

        if (checkWin(board, currentSymbol)) {
            std::cout << "\nWin " << (currentPlayer == 1 ? player1 : player2) << "!\n";
            std::cout << "Do you wanna play again? (1 - yes, 2 - exit to the main): ";
            int choice;
            std::cin >> choice;
            if (choice == 1) {
                startGame();
            }
            return;
        }

        if (checkDraw(board)) {
            std::cout << "\nGame over! Draw!\n";
            std::cout << "Do you wanna play again? (1 - yes, 2 - exit to the main menu): ";
            int choice;
            std::cin >> choice;
            if (choice == 1) {
                startGame();
            }
            return;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char symbol) {
    int size = board.size();

    for (int i = 0; i < size; i++) {
        bool rowWin = true;
        for (int j = 0; j < size; j++) {
            if (board[i][j] != symbol) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) return true;
    }

    for (int j = 0; j < size; j++) {
        bool colWin = true;
        for (int i = 0; i < size; i++) {
            if (board[i][j] != symbol) {
                colWin = false;
                break;
            }
        }
        if (colWin) return true;
    }

    bool mainDiagWin = true;
    for (int i = 0; i < size; i++) {
        if (board[i][i] != symbol) {
            mainDiagWin = false;
            break;
        }
    }
    if (mainDiagWin) return true;

    bool secDiagWin = true;
    for (int i = 0; i < size; i++) {
        if (board[i][size - 1 - i] != symbol) {
            secDiagWin = false;
            break;
        }
    }
    if (secDiagWin) return true;

    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}
