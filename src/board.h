#pragma once
#include <array>
#include <memory>
#include "pieces.h"
#include "player.h"

#define MAGENTA "\033[35m"      
#define RESET   "\033[0m"
typedef uint64_t Bitboard;
class Board{
    public:
        // 2 Farben * 6 Figuren = 12 Bitboards
        Bitboard pieces[2][6];

        // Konstruktor: Alles auf Null
        Board() {
            pieces[WHITE][PAWN]  = 0x000000000000FF00ULL;
            pieces[WHITE][ROOK]   = 0x0000000000000081ULL;  // a1 + h1
            pieces[WHITE][KNIGHT] = 0x0000000000000042ULL;  // b1 + g1
            pieces[WHITE][BISHOP] = 0x0000000000000024ULL;  // c1 + f1  
            pieces[WHITE][QUEEN]  = 0x0000000000000008ULL;
            pieces[WHITE][KING]   = 0x0000000000000010ULL;
            
            pieces[BLACK][PAWN]  = 0x00FF000000000000ULL;
            pieces[BLACK][ROOK]     =  0x8100000000000000ULL;
            pieces[BLACK][BISHOP] =  0x2400000000000000ULL;
            pieces[BLACK][KNIGHT]   = 0x4200000000000000ULL;
            pieces[BLACK][QUEEN]  = 0x0800000000000000ULL;
            pieces[BLACK][KING]   = 0x1000000000000000ULL;
        }
        void handleOperation(Operation op);
        void printBoard(Side side);
        Bitboard getOccupancy(Side side) const ;
        Bitboard getAllOccupancy() const ; 
        inline void setBit(Bitboard& bb, uint8_t square);
        inline void clearBit(Bitboard& bb, uint8_t square);
        inline bool testBit(Bitboard& bb, uint8_t square) const ;
        inline void movePiece(Operation op, uint8_t piece);
};