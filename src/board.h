#pragma once
#ifndef BOARDHEADER
#define BOARDHEADER
#include <array>
#include <memory>
#include "pieces.h"
#include "player.h"
#endif
#define MAGENTA "\033[35m"      /* Magenta */
#define RESET   "\033[0m"

class Board{
    public:
        Player p_white;
        Player p_black;
        std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board;
        Board() = default;
        void initGame();
        void printBoardWhite();
        void printBoardBlack();
        void setPiece(Operation op);
};