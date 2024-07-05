#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <iostream>
#include <vector>

////////////////important/////////////////
//row = '8' - rank
//column = file - 'a'

std::vector<std::string> getLegalMoves(char piece, std::string square);

//the following are all the possible moves, legal or not;
std::vector<std::string> getQueenMoves(std::string square);
std::vector<std::string> getRookMoves(std::string square);
std::vector<std::string> getBishopMoves(std::string square);
std::vector<std::string> getKingMoves(std::string square);
std::vector<std::string> getKnightMoves(std::string square);
#endif