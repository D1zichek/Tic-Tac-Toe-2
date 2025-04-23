#include "board.hpp"
#include "settings.hpp"
#include "game.hpp"
#include <iostream>

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\nCurrent state of the field:\n";
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            std::cout << "[" << board[i][j] << "]";
        }
        std::cout << std::endl;
    }
}
