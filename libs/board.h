#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include <string>
#include <iostream>
#include <vector>
#include "moves.h"

static std::string WhichColor(char piece){
    switch(piece){
        case 'r' : 
            return "black";
        case 'n' : 
            return "black";
        case 'b' : 
            return "black";
        case 'q' : 
            return "black";
        case 'k' : 
            return "black";
        case 'p' : 
            return "black";
        case 'R' : 
            return "white";
        case 'N' : 
            return "white";
        case 'B' : 
            return "white";
        case 'Q' : 
            return "white";
        case 'K' : 
            return "white";
        case 'P' : 
            return "white";
    }
    return "none";
}

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

    void Initialize(); //set up the default board;
    void InitializeFEN(std::string FEN);
    void SetBoard();
    void DisplayBoard();

    //now getting all the valid moves for each piece; all outputs will be a vector of string coordinates (like {'e3','d2'}) ...
    //...for a particular piece;
};


#endif