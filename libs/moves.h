#ifndef MOVES_CLASS_H
#define MOVES_CLASS_H

#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;


class Move{
    public:
    string start;
    string target;
};

////////////////important/////////////////
//row = '8' - rank
//column = file - 'a'

char whichColor(char name);

//the following are all the possible moves, pseudo legal (ignores potential checks);

std::vector<std::string> getQueenMoves(std::string square, char color, vector<vector<int>> board_array);
std::vector<std::string> getRookMoves(std::string square,char color, vector<vector<int>> board_array);
std::vector<std::string> getBishopMoves(std::string square,char color,  vector<vector<int>> board_array);
std::vector<std::string> getKingMoves(std::string square, vector<vector<int>> board_array);
std::vector<std::string> getKnightMoves(std::string square,char color, vector<vector<int>> board_array);
std::vector<std::string> getPawnMoves(std::string square, char color, vector<vector<int>> board_array, char origin);
    


#endif