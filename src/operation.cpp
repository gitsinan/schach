#include "operation.h"
#include "TranslationException.h"

Operation Operation::Translate(std::string s, Player* player){
    try{
          s.erase(s.find_last_not_of(" \n\r\t") + 1);
    Operation op;
    op.playerToMove = player;
    op.toSquare = (s.at(s.length()-1) - '1') * 8
                + (s.at(s.length()-2) - 'a');
    
    // Pawn oder Figur?
    if (s.at(0) >= 'a' && s.at(0) <= 'h') {
        op.charOfPiece = 'P';
    } else {
        op.charOfPiece = s.at(0);
    }
    // std::cout << "DEBUG: Versuche Zug nach Feld: " << (int)op.toSquare << " Piece: " << op.charOfPiece << std::endl;
    // Disambiguierung parsen (optional)
    op.disambigFile = -1;
    op.disambigRank = -1;
    for (int i = 1; i < s.length() - 2; ++i) {
        char c = s.at(i);
        if (c == 'x') continue; // 'x' ignorieren
        if (c >= 'a' && c <= 'h') op.disambigFile = c - 'a';
        if (c >= '1' && c <= '8') op.disambigRank = c - '1';
    }

    op.isCapture = (s.find('x') != std::string::npos);
    return op;

    }
    catch(std::exception ex){
        throw TranslationException("Something  went wrong, try again");
    }
  
}
