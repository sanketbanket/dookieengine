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
    std::vector<std::string> piece_array = {}; //each element will be piece/color/coordinate
    std::vector<std::vector<char>> board_array = {{'_','_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_','_'}};

    std::vector<string> board_history = {}; // The correct algebraic notations are used here. Contains the full history of the board (can be modified);
    
    void Initialize(); //set up the default board;
    void InitializeFEN(std::string FEN);
    void UpdateBoard();
    void DisplayBoard();
    std::string GetFEN();

    
};
#endif