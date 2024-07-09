#include "movesearch.h"


int get_number_of_moves(Board board){
    int valid_moves = 0;
    for(Piece* pic : board.piece_array){
        if(pic->name == 'p' || pic->name == 'P'){
            valid_moves += getPawnMoves(pic->position, whichColor(pic->name), board.board_array, pic->origin).size();
        }
        if(pic->name == 'n' || pic->name == 'N'){
            valid_moves += getKnightMoves(pic->position, whichColor(pic->name), board.board_array).size();
        }
        if(pic->name == 'b' || pic->name == 'B'){
            valid_moves += getBishopMoves(pic->position, whichColor(pic->name), board.board_array).size();
        }
        if(pic->name == 'r' || pic->name == 'R'){
            valid_moves += getRookMoves(pic->position, whichColor(pic->name), board.board_array).size();
        }
        if(pic->name == 'q' || pic->name == 'Q'){
            valid_moves += getQueenMoves(pic->position, whichColor(pic->name), board.board_array).size();
        }
        if(pic->name == 'k' || pic->name == 'K'){
            valid_moves += getKingMoves(*pic, board).size();
        }
    }
    return valid_moves;
}
