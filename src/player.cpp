#include "pieces.h"
#include "player.h"
#include "TranslationException.h"
#include <iostream>

Player::Player(Side side){
    _side = side;
}
Operation Player::HandleInput(){
    std::string input;
    std::cout << "\nPlayer " << SideToString(_side)  << " has to play!\n";
    std::cin >> input;
    return Translate(input);
}
std::string Player::SideToString(Side side) {
    return (side == Side::white) ? "White" : "Black";
}

Operation Player::Translate(const std::string& toTranslate){
    Operation op;
    op.charOfPiece = toTranslate.at(0);
    const std::string validPieces = "RNBKQ";
    if (toTranslate.at(0) == 'O'){
        if(toTranslate == "O-O-O"){

            //TODO
        }else if(toTranslate == "O-O"){
            //TODO

        }else{throw TranslationException("Illegal move. Did you mean to Castle?");}
    }
    if (op.charOfPiece >= 'a' && op.charOfPiece <= 'h') {
    op.charOfPiece = 'P';
    }
    else if(validPieces.find(op.charOfPiece) == std::string::npos) 
    {
        throw TranslationException("Illegal move. Please choose a real piece!");
    }
    if (toTranslate.find('x') != std::string::npos) {
        op.isCapture = true;
        if(op.charOfPiece == 'P'){
            op.charOfPiece = toTranslate.at(0) - 'a';
            op.toCol = toTranslate.at(2) - 'a';
            op.toRow = toTranslate.at(3) - '1';
        } else{
            op.toCol = toTranslate.at(1) - 'a';
            op.toRow = toTranslate.at(2) - '1';
        }
    }
    else{
        op.toCol = toTranslate.at(0) - 'a';
        op.toRow = toTranslate.at(1) - '1';
    }
    return op;
}
