
#include <array>
#include "pieces.cpp"
#include "board.h"
#include "translation.h"

class Board{
    std::array<std::array<Piece*, 8>, 8> board;
    
    void initGame(){
        translate("Sinan");
        board[0][0] = new Rook(Side::white, Position(0, 0));
        board[0][1] = new Knight(Side::white, Position(0, 1));
        board[0][2] = new Bishop(Side::white, Position(0, 2));
        board[0][3] = new Queen(Side::white, Position(0, 3));
        board[0][4] = new King(Side::white, Position(0, 4));
        board[0][5] = new Bishop(Side::white, Position(0, 5));
        board[0][6] = new Knight(Side::white, Position(0, 6));
        board[0][7] = new Rook(Side::white, Position(0, 7));

        board[1][0] = new Pawn(Side::white, Position(1, 0));
        board[1][1] = new Pawn(Side::white, Position(1, 1));
        board[1][2] = new Pawn(Side::white, Position(1, 2));
        board[1][3] = new Pawn(Side::white, Position(1, 3));
        board[1][4] = new Pawn(Side::white, Position(1, 4));
        board[1][5] = new Pawn(Side::white, Position(1, 5));
        board[1][6] = new Pawn(Side::white, Position(1, 6));
        board[1][7] = new Pawn(Side::white, Position(1, 7));

        board[7][0] = new Rook(Side::black, Position(7, 0));
        board[7][1] = new Knight(Side::black, Position(7, 1));
        board[7][2] = new Bishop(Side::black, Position(7, 2));
        board[7][3] = new Queen(Side::black, Position(7, 3));
        board[7][4] = new King(Side::black, Position(7, 4));
        board[7][5] = new Bishop(Side::black, Position(7, 5));
        board[7][6] = new Knight(Side::black, Position(7, 6));
        board[7][7] = new Rook(Side::black, Position(7, 7));

        board[6][0] = new Pawn(Side::black, Position(6, 0));
        board[6][1] = new Pawn(Side::black, Position(6, 1));
        board[6][2] = new Pawn(Side::black, Position(6, 2));
        board[6][3] = new Pawn(Side::black, Position(6, 3));
        board[6][4] = new Pawn(Side::black, Position(6, 4));
        board[6][5] = new Pawn(Side::black, Position(6, 5));
        board[6][6] = new Pawn(Side::black, Position(6, 6));
        board[6][7] = new Pawn(Side::black, Position(6, 7));
    }

};