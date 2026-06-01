#include "pieces.h"
#include "player.h"
#include "operation.h"
#include "TranslationException.h"
#include <iostream>

Player::Player(Side side){
    _side = side;
}
Operation Player::HandleInput(){
    std::string input;
    std::cout << "\nPlayer " << SideToString(_side)  << " has to play!\n";
    std::cin >> input;
    return Operation::Translate(input, this);
}
std::string Player::SideToString(Side side) {
    return (side == Side::WHITE) ? "White" : "Black";
}

