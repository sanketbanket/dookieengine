#include "moves.h"

using std::string;
using std::vector;
////////////////important/////////////////
//row = '8' - rank
//column = file - 'a'


vector<int> getYX(string square){
    vector<int> XY = {'8' -  square[1], square[0] - 'a'};
    return XY;
}
string getSquare(int row, int column){
    string squ = "";
    squ.push_back(char(column + 'a'));
    squ.push_back(char('8' - row));
    return squ;
}
bool isValidSquare(int row, int column){
    return row >= 0 && row <= 7 && column >= 0 && column <= 7;
}
bool isValidSquare(string square){
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

vector<string> getLegalMoves(char piece, string square){
    vector<string> moves = {};
    return moves;
}
vector<string> getRookMoves(string square){
    vector<string> validSquares = {};
    char file = square[0];
    char rank = square[1];
    string rank_helper= "";
    string file_helper = "";
    

    for(int i = 0; i < 8 ; i++ ) {
        rank_helper.push_back(file);
        rank_helper.push_back(char(8 - i + '0'));
        
        file_helper.push_back(char(i + 'a'));
        file_helper.push_back(rank);
        if(file_helper != square){
            validSquares.push_back(file_helper);
        }
        if(rank_helper != square){
            validSquares.push_back(rank_helper);
        };

        file_helper.clear();
        rank_helper.clear();
    }
    return validSquares;
}

vector<string> getBishopMoves(string square){
    char file = square[0];
    char rank = square[0];
    vector<int> yx = getYX(square);
    vector<string> validSquares = {};
    for(int i = 1; i <= 7; i++){
        int row = yx[0] + i;
        int col = yx[1] + i;
        if(isValidSquare(row, col)){
            validSquares.push_back(getSquare(row, col));
        }
        row = yx[0] - i;
        col = yx[1] + i;
        if(isValidSquare(row, col)){
            
            validSquares.push_back(getSquare(row, col));
        }
        row = yx[0] + i;
        col = yx[1] - i;
        if(isValidSquare(row, col)){
            validSquares.push_back(getSquare(row, col));
        }
        row = yx[0] - i;
        col = yx[1] - i;
        if(isValidSquare(row, col)){
            validSquares.push_back(getSquare(row, col));
        }
    }
    return validSquares;
}
vector<string> getQueenMoves(string square){
    vector<string> diags = getBishopMoves(square);
    vector<string> straights = getRookMoves(square);
    for(int i = 0; i < straights.size(); i++){
        diags.push_back(straights[i]);
    }
    return diags;
}

vector<string> getKnightMoves(string square){
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    vector<string> validSquares ={};
    if(isValidSquare(row + 2, col + 1)){validSquares.push_back(getSquare(row + 2, col + 1));}
    if(isValidSquare(row + 2, col - 1)){validSquares.push_back(getSquare(row + 2, col - 1));}

    if(isValidSquare(row - 2, col + 1)){validSquares.push_back(getSquare(row - 2, col + 1));}
    if(isValidSquare(row - 2, col - 1)){validSquares.push_back(getSquare(row - 2, col - 1));}

    if(isValidSquare(row + 1, col - 2)){validSquares.push_back(getSquare(row + 1, col - 2));}
    if(isValidSquare(row - 1, col - 2)){validSquares.push_back(getSquare(row - 1, col - 2));}

    if(isValidSquare(row + 1, col + 2)){validSquares.push_back(getSquare(row + 1, col + 2));}
    if(isValidSquare(row - 1, col + 2)){validSquares.push_back(getSquare(row - 1, col + 2));}
    return validSquares;
}
vector<string> getKingMoves(string square){
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    vector<string> validSquares ={};
    if(isValidSquare(row + 1, col)){validSquares.push_back(getSquare(row + 1, col));}
    if(isValidSquare(row - 1, col)){validSquares.push_back(getSquare(row - 1, col));}
    if(isValidSquare(row, col + 1)){validSquares.push_back(getSquare(row, col + 1));}
    if(isValidSquare(row, col - 1)){validSquares.push_back(getSquare(row, col - 1));}
    if(isValidSquare(row - 1, col + 1)){validSquares.push_back(getSquare(row - 1, col + 1));}
    if(isValidSquare(row - 1, col - 1)){validSquares.push_back(getSquare(row - 1, col - 1));}
    if(isValidSquare(row + 1, col - 1)){validSquares.push_back(getSquare(row + 1, col - 1));}
    if(isValidSquare(row + 1, col + 1)){validSquares.push_back(getSquare(row + 1, col + 1));}
    return validSquares;
}