#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "moves.h"
#include "piece.h"


class Board{
    public : 
    std::vector<Piece*> piece_array = {};
    std::vector<std::vector<int>> board_array = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
    };
    bool white_long_castle = true;  //castling checks
    bool white_short_castle = true;
    bool black_long_castle = true;
    bool black_short_castle = true;
    

    std::vector<string> board_history = {}; // The correct algebraic notations are used here. Contains the full history of the board (can be modified);
    
    void Initialize(); //set up the default starting board;
    void InitializeFEN(std::string FEN);
    void UpdateBoard();
    void DisplayBoard();
    void PlaceNewPiece(char name, std::string square);
    std::string GetFEN();
    vector<Piece*> getKings();
    bool check_castling_rights();
    void MakeMove(string notation);   //use the algebric notation;
    void unMakeMove(string notation);

};
#endif