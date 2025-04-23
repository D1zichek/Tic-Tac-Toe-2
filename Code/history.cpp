#include "history.hpp"
#include <fstream>
#include <iostream>

void showHistory() {
    std::ifstream historyFile("history.txt");
    if (!historyFile) {
        std::cout << "History empty.\n";
        return;
    } else {
        std::cout << "\n=== History Game ===\n";
        std::string line;
        while (getline(historyFile, line)) {
            std::cout << line << std::endl;
        }
    }
    historyFile.close();
}

void exitProgram() {
    std::cout << "\nProgramm is complited. Bye bye!\n";
}

