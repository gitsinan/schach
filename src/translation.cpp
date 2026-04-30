#include <string>
#include "TranslationException.h"
struct Operation{
    public:
        char figureToMove ;
        bool isCapture = false;
        int toRow;
        int toCol;
        int fromCol;
};
class  Translation{

    public:
        static Operation translate(const std::string& toTranslate){
            Operation op;
            op.figureToMove = toTranslate.at(0);

            if (op.figureToMove == 'O'){
                if(toTranslate == "O-O-O"){
                }else if(toTranslate == "O-O"){
                }else{throw TranslationException("Illegal move. Did you mean to Castle?");}
            }
            if (op.figureToMove >= 'a' && op.figureToMove <= 'h') {
            op.figureToMove = 'P';
            } else if (op.figureToMove != 'R' ||op.figureToMove != 'N' ||
                op.figureToMove != 'B'||op.figureToMove != 'K' ||op.figureToMove != 'Q'){
                throw TranslationException("Illegal move. Please choose a real piece!");
            }
            if (toTranslate.find('x') != std::string::npos) {
                op.isCapture = true;
                if(op.figureToMove == 'P'){
                    op.fromCol = toTranslate.at(0) - 'a';
                    op.toCol = toTranslate.at(2) - 'a';
                    op.toRow = toTranslate.at(3) - '1';
                } else{
                    op.toCol = toTranslate.at(2) - 'a';
                    op.toRow = toTranslate.at(3) - '1';
                }
            }
            else{
                op.toCol = toTranslate.at(1) - 'a';
                op.toRow = toTranslate.at(2) - '1';
            }
            return op;
        }
};