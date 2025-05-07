set(USE_SHARED_LIB OFF CACHE BOOL "Build shared library")

if(USE_SHARED_LIB)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()

add_library(libttc ${LIB_TYPE}
    game.cpp
    board.cpp
    settings.cpp
    history.cpp
)

target_include_directories(libttc PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})