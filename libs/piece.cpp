#include "piece.h"

piece::piece(char piece_name, string piece_color, string piece_position, char piece_origin){
    name = piece_name;
    origin = piece_origin;
    position = piece_position;
    color = piece_color;
}