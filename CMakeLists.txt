cmake_minimum_required(VERSION 4.0)
project(prova_progetto)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/ncurses")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(prova_progetto main.cpp
        GameStatus.cpp
        GameStatus.hpp
        Tempo.cpp
        Tempo.hpp
        GameStatus.cpp
        GameStatus.hpp
        Bomba.cpp
        Bomba.hpp
        Premio.cpp
        Premio.hpp
        griglia.cpp
        tuttoUnitoMioValeAndrea.cpp
)
target_link_libraries(prova_progetto ncurses)
target_link_libraries(prova_progetto ${CURSES_LIBRARIES})

