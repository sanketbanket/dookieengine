#include <iostream>
#include <cstdio>
#include <string>
#include "libs\board.h"
#include "libs\movesearch.h"

using std::string;
using std::vector;
using std::cout;


int main(){
    Board chess;

    //chess.Initialize();
    //std::cout<<chess.piece_array[0];
    

    //chess.DisplayBoard();
    std::string FEN = "rnbqkbnr/ppp1p1pp/8/5p2/3p4/4P3/PPPP1PPP/RNBQKBNR";
    //std::cout<<"Enter FEN : "<<'\n';
    //std::cin>>FEN;

    chess.Initialize();
    chess.UpdateBoard();
    chess.DisplayBoard();

    
    
    std::cout<<"move_count "<<get_number_of_moves(chess);
    std::cout<<'\n';

    
    return 0;
}