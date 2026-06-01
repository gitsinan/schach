 #pragma once 
 #include "player.h"

 class Operation {
    public:
        Player* playerToMove;
        char charOfPiece;
        bool isCapture = false;
        uint8_t toSquare;
        uint8_t fromSquare;
        int8_t disambigFile = -1;
        int8_t disambigRank = -1;

        static inline Operation Translate(std::string toTranslate, Player* player);
        
};