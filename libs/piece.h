#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H
#include <string>
#include <vector>
#include "moves.h"
using std::string;
using std::vector;

class Piece{
    public:
    char name;
    char origin;    //file which it belonged to
    string position;
    bool pinned = false;
    vector<string> history = {};
    vector<string> valid_moves ={};

    Piece(char name, string position, char origin);
    vector<string> getLegalMoves();
    void Move();
    void unMove();
    bool amPinned();
};




#endif
