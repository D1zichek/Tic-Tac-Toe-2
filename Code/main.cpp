#include <iostream>
#include "game.hpp"
#include "settings.hpp"
#include "history.hpp"
#include "board.hpp"

int main() {
    int choice;
    loadParameters();

    while (true) {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Settings\n";
        std::cout << "3. History Games\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        // Перевірка на помилки вводу
        if (std::cin.fail()) {
            std::cin.clear(); // Скидання стану помилки
            std::cin.ignore(1000, '\n'); // Пропустити некоректне введення
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                setParameters();
                break;
            case 3:
                showHistory();
                break;
            case 4:
                exitProgram();
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}