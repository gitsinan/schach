
#include <array>
#include "board.h"
#include "IllegalMoveException.h"
#include <iostream>
/*
*/

#include <cstdint>



// Setzt eine 1 an eine Position (0-63)
inline void Board::setBit(Bitboard& bb, uint8_t square) {
    bb |= (1ULL << square);
}

// Setzt eine 0 an eine Position (Löschen)
inline void Board::clearBit(Bitboard& bb, uint8_t square) {
    bb &= ~(1ULL << square);
}

// Prüft, ob an einer Position eine 1 steht
inline bool Board::testBit(Bitboard& bb, uint8_t square) const {
    return (bb >> square) & 1ULL;
}



void Board::printBoard(Side side) {
    
    std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;

    for (int8_t r = 0; r < 8; r++) {
        // Wir berechnen die Reihe basierend auf der Perspektive
        int8_t rank = side == WHITE ? (7 - r) : r;
        
        std::cout << static_cast<int>(rank + 1) << " | ";

        for (int8_t f = 0; f < 8; f++) {
            // Wir berechnen die Spalte basierend auf der Perspektive
            int8_t file = side == WHITE ? f : (7 - f);
            int8_t sq = rank * 8 + file;
            U64 bit = 1ULL << sq;

            // Zeichen bestimmen
            char piece = ' ';
            if      (pieces[WHITE][PAWN] & bit) piece = 'P';
            else if (pieces[WHITE][ROOK] & bit) piece = 'R';
            else if (pieces[WHITE][KNIGHT] & bit) piece = 'N';
            else if (pieces[WHITE][BISHOP] & bit) piece = 'B';
            else if (pieces[WHITE][QUEEN] & bit) piece = 'Q';
            else if (pieces[WHITE][KING] & bit) piece = 'K';
            else if (pieces[BLACK][PAWN] & bit) piece = 'p';
            else if (pieces[BLACK][ROOK] & bit) piece = 'r';
            else if (pieces[BLACK][KNIGHT] & bit) piece = 'n';
            else if (pieces[BLACK][BISHOP] & bit) piece = 'b';
            else if (pieces[BLACK][QUEEN] & bit) piece = 'q';
            else if (pieces[BLACK][KING] & bit) piece = 'k';
            std::cout << piece << " | ";
        }
        std::cout << std::endl;
        std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
    }
        

    if (side == WHITE)
        std::cout <<("    a   b   c   d   e   f   g   h") << std::endl;
    else
        std::cout <<("    h   g   f   e   d   c   b   a") << std::endl;
}
 


Bitboard Board::getOccupancy(Side side) const {
    if(side == WHITE){
        return pieces[WHITE][PAWN] | pieces[WHITE][KNIGHT] | 
                pieces[WHITE][BISHOP] | pieces[WHITE][ROOK] | 
                pieces[WHITE][QUEEN] | pieces[WHITE][KING];
    }else{
        return pieces[BLACK][PAWN] | pieces[BLACK][KNIGHT] | 
                pieces[BLACK][BISHOP] | pieces[BLACK][ROOK] | 
                pieces[BLACK][QUEEN] | pieces[BLACK][KING];
    }

}
Bitboard Board::getAllOccupancy() const {
return getOccupancy(WHITE) | getOccupancy(BLACK);
}
inline void Board::movePiece(Operation op, uint8_t piece) {
    // 1. Die eigene Figur auf ihrem Board bewegen
    clearBit(pieces[op.playerToMove->_side][piece], op.fromSquare);
    setBit(pieces[op.playerToMove->_side][piece], op.toSquare);


    Side opponent = (op.playerToMove->_side == WHITE) ? BLACK : WHITE;
    
    // Wir loopen über alle 6 Figurentypen des Gegners
    if(op.isCapture){
        for (int p = 0; p < 6; p++) {
        if (testBit(pieces[opponent][p], op.toSquare)) {
            clearBit(pieces[opponent][p], op.toSquare);
            break; // Nur eine Figur kann auf einem Feld stehen
        }
    }
    }

}
void clearEnPassant(Operation op){
    op.playerToMove->flags = op.playerToMove->flags & ~EN_PASSANT_AVAIL & ~A & ~B & ~C & ~D & ~E & ~F & ~G & ~H;
}
void Board::handleOperation(Operation op){

        //TODO PROMOTION
        //EN PASSANT

    
    switch (op.charOfPiece)
    {
        case 'P':
        {
            Bitboard occupied = getAllOccupancy();
            Bitboard oponnent = occupied & ~getOccupancy(op.playerToMove->_side);
            Bitboard candidates = pieces[op.playerToMove->_side][PAWN];

                while (candidates) {
                    // Niedrigstes gesetztes Bit = nächste Figur
                    uint8_t sq = __builtin_ctzll(candidates);   // ESP32-kompatibel
                    candidates &= candidates - 1;               
                    int8_t offset;
                    // Kann diese Figur op.toSquare erreichen?
                    Bitboard moves = 0;
                    for (uint8_t i = 0; i < MAX_MOVES_PAWN; i++) {

                        offset = PAWN_MOVEMENT[op.playerToMove->_side][i];

                        int8_t target = sq + offset;
                        if (target < 0 || target >= 64) continue;
                        if (target != op.toSquare) continue;
                        if ((abs(offset) == 8 || abs(offset) == 16) && !op.isCapture) {
                            if(abs(offset) == 16){
                                bool isWhiteStart = (sq / 8 == 1);
                                bool isBlackStart = (sq / 8 == 6);
                                if(op.playerToMove->_side == WHITE){
                                    if(!isWhiteStart) continue;
                                }else{
                                    if(!isBlackStart) continue;
                                }
                                if((occupied & (1ULL << (sq + (offset / 2)))) != 0) continue;
                                op.playerToMove->flags = op.playerToMove->flags | EN_PASSANT_AVAIL;
                                if((1ULL << (sq % 8)) == 0){ op.playerToMove->flags = op.playerToMove->flags | A;}
                                else if((1ULL << (sq % 8)) == 1){op.playerToMove->flags = op.playerToMove->flags | B;}
                                else if((1ULL << (sq % 8)) == 2){op.playerToMove->flags = op.playerToMove->flags | C;}
                                else if((1ULL << (sq % 8)) == 3){op.playerToMove->flags = op.playerToMove->flags | D;}
                                else if((1ULL << (sq % 8)) == 4){op.playerToMove->flags = op.playerToMove->flags | E;}
                                else if((1ULL << (sq % 8)) == 5){op.playerToMove->flags = op.playerToMove->flags | F;}
                                else if((1ULL << (sq % 8)) == 6){op.playerToMove->flags = op.playerToMove->flags | G;}
                                else if((1ULL << (sq % 8)) == 7){op.playerToMove->flags = op.playerToMove->flags | H;}

                            }
                            if(occupied & (1ULL << target)) continue;
                            moves = (1ULL << target);
                        } else {
                            if(!(oponnent & (1ULL << target))) continue;
                            moves = (1ULL << target);
                        }
                    }

                    if (!(moves & (1ULL << op.toSquare)) ) continue;  // nein

                    // Disambiguierung prüfen
                    if (op.disambigFile != -1 && (sq % 8) != op.disambigFile) continue;
                    if (op.disambigRank != -1 && (sq / 8) != op.disambigRank) continue;

                    // Gefunden!
                    op.fromSquare = sq;
                    movePiece(op, PAWN);
                    return;
                }
                throw IllegalMoveException("No piece can reach that square");
   
            break; 
        }
        case 'R':
        {
            if( op.charOfPiece != 'R'&&  op.charOfPiece !=  'r'){break;}
                // Alle Felder dieser Figur iterieren (via Bitboard!)
                Bitboard candidates = pieces[op.playerToMove->_side][ROOK];

                while (candidates) {
                    // Niedrigstes gesetztes Bit = nächste Figur
                    uint8_t sq = __builtin_ctzll(candidates);   // ESP32-kompatibel
                    candidates &= candidates - 1;               // Bit löschen

                    // Kann diese Figur op.toSquare erreichen?
                    Bitboard moves = get_rook_attacks(sq, getAllOccupancy())
                                & ~getOccupancy(op.playerToMove->_side);

                    if (!(moves & (1ULL << op.toSquare))) continue;  // nein

                    // Disambiguierung prüfen
                    if (op.disambigFile != -1 && (sq % 8) != op.disambigFile) continue;
                    if (op.disambigRank != -1 && (sq / 8) != op.disambigRank) continue;

                    // Gefunden
                    op.fromSquare = sq;
                    movePiece(op, ROOK);
                    return;
                }
                throw IllegalMoveException("No piece can reach that square");
            break;
        }
            
        case 'B':
        {
            if( op.charOfPiece != 'B'&&  op.charOfPiece !=  'b'){break;}
                // Alle Felder dieser Figur iterieren (via Bitboard!)
                Bitboard candidates = pieces[op.playerToMove->_side][BISHOP];

                while (candidates) {
                    // Niedrigstes gesetztes Bit = nächste Figur
                    uint8_t sq = __builtin_ctzll(candidates);   // ESP32-kompatibel
                    candidates &= candidates - 1;               // Bit löschen

                    // Kann diese Figur op.toSquare erreichen?
                    Bitboard moves = get_bishop_attacks(sq, getAllOccupancy())
                                & ~getOccupancy(op.playerToMove->_side);

                    if (!(moves & (1ULL << op.toSquare))) continue;  // nein

                    // Disambiguierung prüfen
                    if (op.disambigFile != -1 && (sq % 8) != op.disambigFile) continue;
                    if (op.disambigRank != -1 && (sq / 8) != op.disambigRank) continue;

                    // Gefunden!
                    op.fromSquare = sq;
                    movePiece(op, BISHOP);
                    return;
                }
                throw IllegalMoveException("No piece can reach that square");
            break;
        }
            
        case 'N':
        {
            if( op.charOfPiece != 'N'&&  op.charOfPiece !=  'n'){break;}
                Bitboard candidates = pieces[op.playerToMove->_side][KNIGHT];

                while (candidates) {
                    // Niedrigstes gesetztes Bit = nächste Figur
                    uint8_t sq = __builtin_ctzll(candidates);   // ESP32-kompatibel
                    candidates &= candidates - 1;               // Bit löschen

                    // Kann diese Figur op.toSquare erreichen?
                    Bitboard moves = KNIGHT_MOVEMENT[sq] & ~getOccupancy(op.playerToMove->_side);

                    if (!(moves & (1ULL << op.toSquare))) continue;  // nein

                    // Disambiguierung prüfen
                    if (op.disambigFile != -1 && (sq % 8) != op.disambigFile) continue;
                    if (op.disambigRank != -1 && (sq / 8) != op.disambigRank) continue;

                    // Gefunden!
                    op.fromSquare = sq;
                    movePiece(op, KNIGHT);
                    return;
                }
                throw IllegalMoveException("No piece can reach that square");
        
            break;
        }
        case 'K':
        {
            if( op.charOfPiece != 'K'&&  op.charOfPiece !=  'k'){break;}
                Bitboard candidates = pieces[op.playerToMove->_side][KING];

                while (candidates) {
                    // Niedrigstes gesetztes Bit = nächste Figur
                    uint8_t sq = __builtin_ctzll(candidates);   // ESP32-kompatibel
                    candidates &= candidates - 1;               // Bit löschen

                    // Kann diese Figur op.toSquare erreichen?
                    Bitboard moves = KING_MOVEMENT[sq] & ~getOccupancy(op.playerToMove->_side);

                    if (!(moves & (1ULL << op.toSquare))) continue;  // nein

                    // Disambiguierung prüfen
                    if (op.disambigFile != -1 && (sq % 8) != op.disambigFile) continue;
                    if (op.disambigRank != -1 && (sq / 8) != op.disambigRank) continue;

                    // Gefunden!
                    op.fromSquare = sq;
                    movePiece(op, KING);
                    return;
                }
                throw IllegalMoveException("No piece can reach that square");
            break;
        }
        case 'Q':
        {
             if( op.charOfPiece != 'Q'&&  op.charOfPiece !=  'q'){break;}
                // Alle Felder dieser Figur iterieren (via Bitboard!)
                Bitboard candidates = pieces[op.playerToMove->_side][QUEEN];

                while (candidates) {
                    // Niedrigstes gesetztes Bit = nächste Figur
                    uint8_t sq = __builtin_ctzll(candidates);   // ESP32-kompatibel
                    candidates &= candidates - 1;               // Bit löschen

                    // Kann diese Figur op.toSquare erreichen?
                    Bitboard moves = (get_rook_attacks(sq, getAllOccupancy()) | get_bishop_attacks(sq, getAllOccupancy()))
                                & ~getOccupancy(op.playerToMove->_side);

                    if (!(moves & (1ULL << op.toSquare))) continue;  // nein

                    // Disambiguierung prüfen
                    if (op.disambigFile != -1 && (sq % 8) != op.disambigFile) continue;
                    if (op.disambigRank != -1 && (sq / 8) != op.disambigRank) continue;

                    // Gefunden!
                    op.fromSquare = sq;
                    movePiece(op, QUEEN);
                    return;
                }
                throw IllegalMoveException("No piece can reach that square");
        }

        default:
            std::cout << "THIS SHOULDNT HAPPEN " << std::endl;
            break;

        throw IllegalMoveException("Illegal move: No piece found that can reach ");
    }    
}
        
        
        

    

