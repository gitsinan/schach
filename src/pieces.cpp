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