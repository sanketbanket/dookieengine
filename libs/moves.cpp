#include "moves.h"

using std::string;
using std::vector;
////////////////important/////////////////
//row = '8' - rank
//column = file - 'a'

vector<int> getXY(string square){
    vector<int> XY = {'8' -  square[1], square[0] - 'a'};
    return XY;
}
string getSquare(int row, int column){
    string squ = "";
    squ.push_back(char(column + 'a'));
    squ.push_back(char('8' - row));
    return squ;
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
    vector<int> xy = getXY(square);
    vector<string> validSquares = {};
    for(int i = 1; i <= 7; i++){
        int row = xy[0] + i;
        int col = xy[1] + i;
        if(row >= 0 && row <= 7 && col >= 0 && col <= 7){
            validSquares.push_back(getSquare(row, col));
        }
        row = xy[0] - i;
        col = xy[1] + i;
        if(row >= 0 && row <= 7 && col >= 0 && col <= 7){
            
            validSquares.push_back(getSquare(row, col));
        }
        row = xy[0] + i;
        col = xy[1] - i;
        if(row >= 0 && row <= 7 && col >= 0 && col <= 7){
            validSquares.push_back(getSquare(row, col));
        }
        row = xy[0] - i;
        col = xy[1] - i;
        if(row >= 0 && row <= 7 && col >= 0 && col <= 7){
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
    vector<int> xy = getXY(square);
    vector<string> validSquares ={};
    return validSquares;
}