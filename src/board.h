
#include <array>
#include "pieces.h"

class Board{
    std::array<std::array<Piece*, 8>, 8> board;
    void initGame();

};