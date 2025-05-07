#include "settings.hpp"
#include "game.hpp"
#include "board.hpp"
#include "history.hpp"
#include <fstream>
#include <iostream>
#include <vector>



void setParameters() {
    std::cout << "\n=== Setting Parameters ===\n";
    std::cout << "Enter boardsize (min 3x3): ";
    std::cin >> boardSize;

    if (boardSize < 3) {
        std::cout << "Invalid boardsize. Installed size 3x3.\n";
        boardSize = 3;
    }

    std::cout << "Enter name player 1: ";
    std::cin >> player1;
    std::cout << "Enter name player 2: ";
    std::cin >> player2;
    
    saveParameters(boardSize, player1, player2);
}

void saveParameters(int boardSize, const std::string& player1, const std::string& player2) {
    std::ofstream paramFile("parameters.txt");
    paramFile << boardSize << std::endl;
    paramFile << player1 << std::endl;
    paramFile << player2 << std::endl;
    paramFile.close();
}

void loadParameters() {
    std::ifstream paramFile("parameters.txt");
    if(paramFile) {
        paramFile >> boardSize;
        paramFile >> player1;
        paramFile >> player2;
    }
    paramFile.close();
}
