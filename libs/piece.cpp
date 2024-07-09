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
