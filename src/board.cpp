#include <vector>
#include <array>

enum Side{
    white,
    black
};


class Player{
 Side _side;
 

};
class Position
{
    public :

    int _col;
    int _row;
    Position() : _row(0), _col(0) {}

    Position(int col, int row){
        _col = col;
        _row = row;
    }
    void setCol(int col){
        _col = col;
    }
    int getCol(){
        return _col;
    }
    void setRow(int row){
        _row = row;
    }
    int getRow(){
        return _row;
    }

};
class Piece {
    public:
        Side _pieceSide;
        Position _position;

        Piece(Side pieceSide, Position position) : _pieceSide(pieceSide), _position(position){}

        Position getPosition(){
            return _position;
        }
        void setPosition(Position position){
            _position = position;
        }
        bool pieceInTheWay(std::pair<int, int> direction){
            int max_y = direction.first;
            int max_x = direction.second;
            int current_x = 0;
            int current_y = 0;
            for(int i = 0; i > max_y && max_x; i++){
                

                if(current_x != max_x){current_x++;}
                if(current_y != max_y){current_y++;}
            
            }
        }

        char print(){
            return 'X';
        };

};
class Queen : public Piece{ 
    public:

    const int points = 9;

    const std::vector<std::pair<int, int>> _directions = {
            {-7,  0}, // oben
            {7 ,  0}, // unten
            {0 , -7}, // links
            {0 ,  7}, // rechts
            {7 ,  7}, // unten rechts
            {7 , -7}, // unten links
            {-7,  7}, // oben  rechts 
            {-7, -7}  // oben  links 
    };
    Queen(Side pieceSide, Position position) : Piece(pieceSide, position) {}  
    char print(){
        return 'Q';
    }
};
class Rook : public Piece{ 
    public :
    const int points = 5;
    const std::vector<std::pair<int, int>> _directions = {
            {-7,  0}, // oben
            {7 ,  0}, // unten
            {0 , -7}, // links
            {0 ,  7}, // rechts
    };
    Rook(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
    char print(){
        return 'R';
    }
};
class Bishop : public Piece{ 
    public :
    const int points = 3;
    const std::vector<std::pair<int, int>> _directions = {
            {7 ,  7}, // unten rechts
            {7 , -7}, // unten links
            {-7,  7}, // oben  rechts 
            {-7, -7}  // oben  links 
    };
    Bishop(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
    char print(){
        return 'B';
    }
};
class Knight : public Piece{ 
    public :

    const int points = 3;
    const std::vector<std::pair<int, int>> _directions = {
            {-3,  -1}, // oben links
            {-3 ,  1}, // oben rechts
            {-1,  -3}, // links oben
            {1 ,  -3}, // links unten
            {3 ,   1}, // unten rechts
            {3 ,  -1}, // unten links
            {-1,   3}, // rechts oben
            { 1,   3}  // links oben
    };
    Knight(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
    char print(){
        return 'N';
    }
};
class King : public Piece{ 
    const int points = 0;
    public :
    const std::vector<std::pair<int, int>> _directions = {
            {-1,  0}, // oben
            {1 ,  0}, // unten
            {0 , -1}, // links
            {0 ,  1}, // rechts
            {1 ,  1}, // unten rechts
            {1 , -1}, // unten links
            {-1,  1}, // oben  rechts 
            {-1, -1}  // oben  links 
    };
    King(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
    char print(){
        return 'K';
    }
};
class Pawn : public Piece{ 
    public: 
    const int points = 1;
    const std::vector<std::pair<int, int>> _directions = {
            {-1,  0}, // oben
            {-1,  1}, // oben  rechts 
            {-1, -1}  // oben  links 
    };
    Pawn(Side pieceSide, Position position) : Piece(pieceSide, position) {} 
    char print(){
        return 'P';
    }
};
class Board{
    std::array<std::array<Piece*, 8>, 8> board;

    void initGame(){
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