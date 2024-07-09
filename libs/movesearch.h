#ifndef MOVE_GEN_H
#define MOVE_GEN_H

#include "board.h"


class Move{
    public:
    string start;
    string target;
};


int get_number_of_moves(Board board);

    

#endif