
#include <array>
#include "board.h"
#include <iostream>

void Board::initGame(){
    p_white = Player(Side::white);
    p_black = Player(Side::black);
    board[0][0] = std::make_unique<Rook>(Side::white, Position(0, 0));
    board[0][1] = std::make_unique<Knight>(Side::white, Position(0, 1));
    board[0][2] = std::make_unique<Bishop>(Side::white, Position(0, 2));
    board[0][3] = std::make_unique<Queen>(Side::white, Position(0, 3));
    board[0][4] = std::make_unique<King>(Side::white, Position(0, 4));
    board[0][5] = std::make_unique<Bishop>(Side::white, Position(0, 5));
    board[0][6] = std::make_unique<Knight>(Side::white, Position(0, 6));
    board[0][7] = std::make_unique<Rook>(Side::white, Position(0, 7));

    board[1][0] = std::make_unique<Pawn>(Side::white, Position(1, 0));
    board[1][1] = std::make_unique<Pawn>(Side::white, Position(1, 1));
    board[1][2] = std::make_unique<Pawn>(Side::white, Position(1, 2));
    board[1][3] = std::make_unique<Pawn>(Side::white, Position(1, 3));
    board[1][4] = std::make_unique<Pawn>(Side::white, Position(1, 4));
    board[1][5] = std::make_unique<Pawn>(Side::white, Position(1, 5));
    board[1][6] = std::make_unique<Pawn>(Side::white, Position(1, 6));
    board[1][7] = std::make_unique<Pawn>(Side::white, Position(1, 7));

    board[7][0] = std::make_unique<Rook>(Side::black, Position(7, 0));
    board[7][1] = std::make_unique<Knight>(Side::black, Position(7, 1));
    board[7][2] = std::make_unique<Bishop>(Side::black, Position(7, 2));
    board[7][3] = std::make_unique<Queen>(Side::black, Position(7, 3));
    board[7][4] = std::make_unique<King>(Side::black, Position(7, 4));
    board[7][5] = std::make_unique<Bishop>(Side::black, Position(7, 5));
    board[7][6] = std::make_unique<Knight>(Side::black, Position(7, 6));
    board[7][7] = std::make_unique<Rook>(Side::black, Position(7, 7));

    board[6][0] = std::make_unique<Pawn>(Side::black, Position(6, 0));
    board[6][1] = std::make_unique<Pawn>(Side::black, Position(6, 1));
    board[6][2] = std::make_unique<Pawn>(Side::black, Position(6, 2));
    board[6][3] = std::make_unique<Pawn>(Side::black, Position(6, 3));
    board[6][4] = std::make_unique<Pawn>(Side::black, Position(6, 4));
    board[6][5] = std::make_unique<Pawn>(Side::black, Position(6, 5));
    board[6][6] = std::make_unique<Pawn>(Side::black, Position(6, 6));
    board[6][7] = std::make_unique<Pawn>(Side::black, Position(6, 7));
}
    void Board::printBoardWhite() {
        std::cout << "\n";
        for (int8_t row = 7; row >= 0; row--) {
            std::cout << row + 1 << "  ";
            for (int8_t col = 0; col < 8; col++) {
                if (board[row][col] != nullptr) {
                    if (board[row][col]->getSide() == Side::black){
                        std::cout << MAGENTA << board[row][col]->print() << RESET << " ";
                    } else{
                        std::cout << board[row][col]->print() << " ";
                    }
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n   a b c d e f g h\n\n";
    }
    void Board::printBoardBlack() {
        std::cout << "\n";
        for (int8_t row = 0; row < 8; row++) {
            std::cout << row + 1 << "  ";
            for (int8_t col = 7; col >= 0; col--) {
                if (board[row][col] != nullptr) {
                    if (board[row][col]->getSide() == Side::black){
                        std::cout << MAGENTA << board[row][col]->print() << RESET << " ";
                    } else{
                        std::cout << board[row][col]->print() << " ";
                    }
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n   h g f e d c b a\n\n";
    }
    void Board::setPiece(Operation op){
        for (int8_t row = 0; row < 8; row++) {
            for (int8_t col = 0; col < 8; col++) {
        
            }
        }


        board[op.toRow][op.toCol] = std::move(board[op.pieceToMove->getRow()][op.pieceToMove->getCol()]);
        op.setPosition();
    }
    