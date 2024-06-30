#include <iostream>
#include <cstdio>
#include <string>
#include "libs\board.h"



int main(){
    Board chess;

    //chess.Initialize();
    //std::cout<<chess.piece_array[0];
    

    //chess.DisplayBoard();
    std::string FEN = "";
    std::cout<<"Enter FEN : "<<'\n';
    std::cin>>FEN;


    chess.InitializeFEN(FEN);
    /*
    for(int i = 0;i < chess.piece_array.size();i++){
        std::cout<<chess.piece_array[i]<<'\n';
    }
    */

    chess.DisplayBoard();

    return 0;
}