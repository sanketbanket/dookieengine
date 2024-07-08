#include "piece.h"
#include "moves.h"

//these are made here because we need info about the history of the piece.

vector<string> getCastling(bool white_castle = true, bool black_castle = true);
vector<string> getEnPassant();

//NOTE YET TO IMPLEMENT A CHECK FOR ATTACK ON THE KING

Piece::Piece(char piece_name, string piece_position, char piece_origin){
    name = piece_name;
    origin = piece_origin;
    position = piece_position;

}

/*
vector<string>  Piece::getLegalMoves(){
    vector<string> valid_moves;
    if(name == 'r' || name == 'R' ){
        valid_moves = getRookMoves(position);
    }
    else if(name == 'b' || name == 'B'){
        valid_moves = getBishopMoves(position);
    }
    else if(name == 'n' || name == 'N'){
        valid_moves = getKnightMoves(position);
    }
    else if(name == 'q' || name == 'Q'){
        valid_moves = getQueenMoves(position);
    }
    else if(name == 'p' || name == 'P'){
        
    }
    return valid_moves;
}
*/

