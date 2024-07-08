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
    std::string FEN = "rnbqkbnr/ppp1p1pp/8/5p2/3p4/4P3/PPPP1PPP/RNBQKBNR";
    //std::cout<<"Enter FEN : "<<'\n';
    //std::cin>>FEN;

    chess.InitializeFEN(FEN);
    /*
    for(int i = 0;i < chess.piece_array.size();i++){
        std::cout<<chess.piece_array[i]<<'\n';
    }
    */
    chess.UpdateBoard();
    chess.DisplayBoard();

    Piece* obj = new Piece('P', "e3", 'e');
    vector<string> move_list = getPawnMoves(obj->position, whichColor(obj->name), chess.board_array, obj -> origin);
    for(string i : move_list){
        cout<<i<<", ";
    }
    return 0;
}