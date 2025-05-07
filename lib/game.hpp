#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include "settings.hpp"
#include "history.hpp"
#include "board.hpp"

void startGame();
bool checkWin(const std::vector<std::vector<char>>& board, char symbol);
bool checkDraw(const std::vector<std::vector<char>>& board);

#endif
