#include "board.h"
#include <iostream>
void chessGame(){
    Board b;
    b.initGame();
    while(true){
        //TODO Checkmate check
        Operation op;
        b.printBoardWhite();
        op = b.p_white.HandleInput();
        b.setPiece(std::move(op));
        b.printBoardWhite();
        op = b.p_black.HandleInput();
        b.setPiece(std::move(op));
    }
}
int8_t main() {
    chessGame();
    return 0;
}
