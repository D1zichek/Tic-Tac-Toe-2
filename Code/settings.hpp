#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>

inline int boardSize = 3;
inline std::string player1 = "User1";
inline std::string player2 = "User2" ;

void setParameters();
void saveParameters(int boardSize, const std::string& player1, const std::string& player2);
void loadParameters();

#endif
