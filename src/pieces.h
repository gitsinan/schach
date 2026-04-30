#include <vector>
enum Side{
    white,
    black
};
class Position
{
    public :
        int _col;
        int _row;
        Position();
        Position(int col, int row);
        void setCol(int col);
        int getCol();
        void setRow(int row);
        int getRow();
};
class Piece {
    public:
        Side _pieceSide;
        Position _position;
        Piece(Side pieceSide, Position position);
        Position getPosition();
        void setPosition(Position position);
        bool pieceInTheWay(std::pair<int, int> direction);
        char print();
};
class Queen : public Piece{ 
    public:
        const int points;
        const std::vector<std::pair<int, int>> _directions;
        Queen(Side pieceSide, Position position);
        char print();
};
class Rook : public Piece{ 
    public :
        const int points;
        const std::vector<std::pair<int, int>> _directions;
        Rook(Side pieceSide, Position position);
        char print();
};
class Bishop : public Piece{ 
    public :
        const int points;
        const std::vector<std::pair<int, int>> _directions;
        Bishop(Side pieceSide, Position position);
        char print();
};
class Knight : public Piece{ 
    public :

        const int points;
        const std::vector<std::pair<int, int>> _directions;
        Knight(Side pieceSide, Position position);
        char print();
};
class King : public Piece{ 
    const int points;
    public:
        const std::vector<std::pair<int, int>> _directions;
        King(Side pieceSide, Position position);
        char print();

};
class Pawn : public Piece{ 
    public: 
        const int points;
        const std::vector<std::pair<int, int>> _directions;
        Pawn(Side pieceSide, Position position);
        char print();
};