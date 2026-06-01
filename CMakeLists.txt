cmake_minimum_required(VERSION 3.16)
project(Schach CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(schach
    src/main.cpp
    src/board.cpp
    src/player.cpp
    src/pieces.cpp
    src/lookups.cpp
    src/operation.cpp
    src/TranslationException.cpp
    src/IllegalMoveException.cpp
)

target_include_directories(schach PRIVATE src)