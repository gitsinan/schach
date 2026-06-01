#include "board.h"
#include <iostream>
#include "IllegalMoveException.h"
#include "TranslationException.h"
void chessGame(){
    Board b;
    Player pWhite(WHITE);
    Player pBlack(BLACK);
    bool nonIllegalMovePlayed;
    while(true){
         nonIllegalMovePlayed = false;
        //TODO Checkmate check
        Operation op;
        
        do{
            try{
                b.printBoard(WHITE);
                op = pWhite.HandleInput();
                b.handleOperation(op);
                nonIllegalMovePlayed = true;
            }catch(TranslationException tex){
                nonIllegalMovePlayed = false;
                std::cout << tex.what() <<  std::endl;
            }catch(IllegalMoveException iex){
                nonIllegalMovePlayed = false;
                std::cout << iex.what() << std::endl;
            }
        }while(!nonIllegalMovePlayed);

        do{
            try{
                b.printBoard(BLACK);
                op = pBlack.HandleInput();
                b.handleOperation(op);
                nonIllegalMovePlayed = true;
            }catch(TranslationException tex){
                nonIllegalMovePlayed = false;
            }catch(IllegalMoveException iex){
                nonIllegalMovePlayed = false;
            }
        }while(!nonIllegalMovePlayed);
        
        
    }
}
int main() {
    chessGame();
    return 0;
}
