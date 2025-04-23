cmake_minimum_required(VERSION 3.10) 

project(TTC) 

set(CMAKE_CXX_STANDARD 17) 

set(SOURCES
    "Code/main.cpp"
    "Code/game.cpp"
    "Code/board.cpp"
    "Code/history.cpp"
    "Code/settings.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
