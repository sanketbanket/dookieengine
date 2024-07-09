#ifndef MOVES_CLASS_H
#define MOVES_CLASS_H

#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;


////////////////important/////////////////
//row = '8' - rank
//column = file - 'a'

char whichColor(char name);
vector<int> getYX(string square);
string getSquare(int row, int column);
bool isValidSquare(string square);
bool isValidSquare(int row, int column);

//the following are all the possible moves, pseudo legal (ignores potential checks);

std::vector<std::string> getQueenMoves(std::string square, char color, vector<vector<int>> board_array);
std::vector<std::string> getRookMoves(std::string square,char color, vector<vector<int>> board_array);
std::vector<std::string> getBishopMoves(std::string square,char color,  vector<vector<int>> board_array);
std::vector<std::string> getKnightMoves(std::string square,char color, vector<vector<int>> board_array);
std::vector<std::string> getPawnMoves(std::string square, char color, vector<vector<int>> board_array, char origin);

//this is different because we need it to check the square that the pawn "attacks"
//because the pawn cant move forward if its blocked by enemy piece but can still control the diagonal;
std::vector<std::string> getPawnDiagonals(std::string square, char, vector<vector<int>>board_array); //returns the diagonal squares;


#endif