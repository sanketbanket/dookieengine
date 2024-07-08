#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H
#include <string>
#include <vector>
#include "moves.h"
using std::string;
using std::vector;

class piece{
    char name;
    char origin;    //file which it belonged to
    string color;
    string position;
    vector<string> history = {};
    piece(char name, string color, string position, char origin);


};


#endif
