#pragma once
#ifndef PLAYERHEADER
#define PLAYERHEADER
#endif
#include "pieces.h"
#include "operation.h"

class Player{
    public:
        Side _side;
        Player() = default;
        Player(Side side);
        Operation HandleInput();
        void print();
        std::string SideToString(Side side);
        Operation Translate(const std::string& toTranslate);
};