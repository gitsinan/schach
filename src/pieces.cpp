
#include "pieces.h"

Position::Position() : _row(0), _col(0) {}
Position::Position(int8_t col, int8_t row){
    _col = col;
    _row = row;
}
void Position::setCol(int8_t col){
    _col = col;
}
int8_t Position::getCol(){
    return _col;
}
void Position::setRow(int8_t row){
    _row = row;
}
int8_t Position::getRow(){
    return _row;
}

Piece::Piece(Side pieceSide, Position position) : _pieceSide(pieceSide), _position(position){}

Position Piece::getPosition(){
    return _position;
}
void Piece::setPosition(Position position){
    _position = position;
}
int8_t Piece::getCol(){
    return  _position.getCol();
}
int8_t Piece::getRow(){
    return _position.getRow();
}
Side Piece::getSide(){
    return _pieceSide;
}

char Piece::Piece::print(){
    if(_pieceSide == Side::white){return 'X';}
    else {return 'x';}
};

Queen::Queen(Side pieceSide, Position position) : Piece(pieceSide, position) {}
char Queen::print(){
    if(_pieceSide == Side::white){return 'Q';}
    else {return 'q';}
}

Rook::Rook(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
char Rook::print(){
    if(_pieceSide == Side::white){return 'R';}
    else {return 'r';}
}

Bishop::Bishop(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
char Bishop::print(){
    if(_pieceSide == Side::white){return 'B';}
    else {return 'b';}
}
Knight::Knight(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
char Knight::print(){
    if(_pieceSide == Side::white){return 'N';}
    else {return 'n';}
}
King::King(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
char King::print(){
    if(_pieceSide == Side::white){return 'K';}
    else {return 'k';}
}
Pawn::Pawn(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
char Pawn::print(){
    if(_pieceSide == Side::white){return 'P';}
    else {return 'p';}
}