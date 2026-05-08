#pragma once
#ifndef PIECESHEADER
#define PIECESHEADER
#endif
#include <array>
#include <cstdint>
enum Side : uint8_t{
    white,
    black
};
static constexpr uint8_t MAX_MOVES_QUEEN  = 27;
static constexpr uint8_t MAX_MOVES_ROOK   = 14;
static constexpr uint8_t MAX_MOVES_BISHOP = 13;
static constexpr uint8_t MAX_MOVES_KNIGHT = 8;
static constexpr uint8_t MAX_MOVES_KING   = 8;
static constexpr uint8_t MAX_MOVES_PAWN   = 4;

class Position
{
    public :
        int8_t _col;
        int8_t _row;
        Position();
        Position(int8_t col, int8_t row);
        void setCol(int8_t col);
        int8_t getCol();
        void setRow(int8_t row);
        int8_t getRow();
};
class Piece {
    public:
        Side _pieceSide;
        Position _position;

        Piece() = default;
        Piece(Side pieceSide, Position position);
        Position getPosition();
        void setPosition(Position position);
        int8_t getCol();
        int8_t getRow();
        Side getSide();
        virtual char print();
        virtual ~Piece() = default;
};
class Queen : public Piece{ 
    public:
        static constexpr int8_t _points = 9;
        static constexpr std::array<std::pair<int8_t,int8_t>, 8> _directions = {{
        {-1, 0}, {1, 0}, {0,-1}, {0, 1},
        {-1,-1}, {-1, 1}, {1,-1}, {1, 1}
        }};
        Queen(Side pieceSide, Position position);
        char print() override;
};
class Rook : public Piece{ 
    public :
        static constexpr int8_t _points = 5;
        static constexpr std::array<std::pair<int8_t,int8_t>, 8> _directions = {{
            {-1,  0}, // oben
            {1 ,  0}, // unten
            {0 , -1}, // links
            {0 ,  1}, // rechts
        }};
        Rook(Side pieceSide, Position position);
        char print() override;
};
class Bishop : public Piece{ 
    public :
        static constexpr int8_t _points = 3;
        static constexpr std::array<std::pair<int8_t,int8_t>, 8> _directions = {{
            {1 ,  1}, // unten rechts
            {1 , -1}, // unten links
            {-1,  1}, // oben  rechts 
            {-1, -1}  // oben  links 
        }};
        Bishop(Side pieceSide, Position position);
        char print() override;
};
class Knight : public Piece{ 
    public :
        static constexpr int8_t _points = 3;
        static constexpr std::array<std::pair<int8_t,int8_t>, 8> _directions = {{
            {-2,  -1}, // oben links
            {-2 ,  1}, // oben rechts
            {-1,  -2}, // links oben
            {1 ,  -2}, // links unten
            {2 ,   1}, // unten rechts
            {2 ,  -1}, // unten links
            {-1,   2}, // rechts oben
            { 1,   2}  // links oben
        }};
        Knight(Side pieceSide, Position position);
        char print() override;
};
class King : public Piece{ 
    public:
        static constexpr int8_t _points = 0;
        static constexpr std::array<std::pair<int8_t,int8_t>, 8> _directions = {{
            {-1,  0}, // oben
            {1 ,  0}, // unten
            {0 , -1}, // links
            {0 ,  1}, // rechts
            {1 ,  1}, // unten rechts
            {1 , -1}, // unten links
            {-1,  1}, // oben  rechts 
            {-1, -1}  // oben  links 
        }};
        King(Side pieceSide, Position position);
        char print() override;
};
class Pawn : public Piece{ 
    public: 
        static constexpr int8_t _points = 1;
        static constexpr std::array<std::pair<int8_t,int8_t>, 8> _directions = {{
                {-1,  0}, // oben
                {-1,  1}, // oben  rechts 
                {-1, -1}  // oben  links 
        }};
        Pawn(Side pieceSide, Position position);
        char print() override;
};