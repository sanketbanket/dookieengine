#include <iostream>
#include <cstdio>
#include <string>
#include "libs\board.h"

using std::string;
using std::vector;
using std::cout;


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
    chess.UpdateBoard();
    chess.DisplayBoard();
    vector<string> moves = getKnightMoves("h2");
    
    //cout<<moves.size();
    for(int i = 0; i < moves.size(); i++){
        std::cout<<moves[i]<<' ';
    }


    return 0;
}